import cv2
import os
import xml.etree.ElementTree as ET
import numpy as np
from M2.fruit import Fruit


class ImageHandler:
    """
    Classe responsável por armazenar os dados da imagem retirados
    do arquivo de metadados
    """

    def __init__(self, meta_path):
        self.meta_path = meta_path
        self.fruits = []
        self._read_meta_file()

    def _read_meta_file(self):
        """
        Le os dados do metadado e salva no objeto
        """
        # Faz a leitura do arquivo xml
        tree = ET.parse(self.meta_path)
        root = tree.getroot()
        # Concatena o caminho da pasta do arquivo xml com o filename dos metadados
        image_path = os.path.join(os.path.dirname(self.meta_path), root.find("filename").text)
        # Lê a imagem utilizando a lib do OpenCV
        self.image = cv2.imread(image_path)
        # Le altura e largura da imagem dos metadados
        self.height = int(root.find("size").find("height").text)
        self.width = int(root.find("size").find("width").text)
        # Itera sobre os objects pois existe um objeto para cada fruta na imagem e
        # podem ter mais de uma fruta na mesma imagem
        for object in root.findall("object"):
            # Procura os dados do objeto e salva nas variáveis
            fruit_name = object.find("name").text
            fruit_truncated = bool(int(object.find("truncated").text))
            bnbbox = object.find("bndbox")
            fruit_xmin = int(bnbbox.find("xmin").text)
            fruit_ymin = int(bnbbox.find("ymin").text)
            fruit_xmax = int(bnbbox.find("xmax").text)
            fruit_ymax = int(bnbbox.find("ymax").text)
            # Cria um novo objeto 'Fruta' e adiciona a lista de frutas
            self.fruits.append(Fruit(fruit_name, fruit_truncated, fruit_xmin, fruit_ymin, fruit_xmax, fruit_ymax))

    def apply_function(self, function, **kwargs):
        """
        Aplica a função recebida na imagem
        :param function: função para executar na imagem
        :param kwargs: argumentos para a função
        """
        self.image = function(self.image, **kwargs)

    def reshape_image(self, shape=(-1, 3), float32=False):
        """
        Faz a remodelagem da imagem para o shape recebido
        :param shape: shape destino da imagem
        :param float32: se True altera a imagem para formato
            float32
        """
        self.image = self.image.reshape(shape)
        if float32:
            self.image = np.float32(self.image)

    def show_fruits(self):
        """
        Mostra somente as frutas de acordo com as coordenadas do metadados
        """
        temp_images = []
        for fruit in self.fruits:
            temp_images.append(self.image[fruit.ymin:fruit.ymax, fruit.xmin:fruit.xmax])
        for image in temp_images:
            cv2.imshow(self.fruits[0].name, image)
            cv2.waitKey(0)
            cv2.destroyAllWindows()

    def show_image(self):
        """
        Mostra todas as imagens uma por vez
        """
        cv2.imshow("-".join([fruit.name for fruit in self.fruits]), self.image)
        cv2.waitKey(0)
        cv2.destroyAllWindows()

    def apply_kmean(self, criteria, K, attempts):
        """
        Aplica o algoritmo de segmentação do K-means na imagem
        :param criteria: Critério para avaliação do k-means
        :param K: Define o número de clusters / grupos aos quais um pixel
                  pode pertencer
        :param attempts: Número de tentativas máximo
        """
        # Salva a dimensão original da imagem para poder retorná-la após a segmentação
        original_shape = self.image.shape
        # Faz o reshape da imagem e transforma para float32
        self.reshape_image(float32=True)
        # Aplica o kmeans
        _, label, center = cv2.kmeans(self.image, K=K, bestLabels=None, criteria=criteria, attempts=attempts,
                   flags=cv2.KMEANS_PP_CENTERS)
        # Converte de volta para valores de 8 bits
        center = np.uint8(center)
        # Achata a matriz de rótulos ex: [[3], [3], [3]] -> [3, 3, 3]
        label = label.flatten()
        # converter todos os pixels para a cor dos centróides
        result_image = center[label.flatten()]
        # Faz o reshape de volta para a dimensão original
        self.image = result_image.reshape(original_shape)

