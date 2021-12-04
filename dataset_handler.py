import glob
import cv2
from M2.image_handler import ImageHandler


class DataSetHandler:
    """
    Classe responsável por ler todos os metadados do caminho recebido e
    agrupa-los.
    """

    def __init__(self, folder_path):
        if not folder_path.endswith("/"):
            folder_path += "/"
        self.folder_path = folder_path + "*.xml"
        self.image_handlers = []
        self._read_directory()

    def _read_directory(self):
        """
        Le as imagens da pasta e inclui no array de imagens
        """
        # Itera sobre todos os arquivos .xml da pasta e adiciona a
        # lista de images
        for path in glob.glob(self.folder_path):
            self.image_handlers.append(ImageHandler(path))

    def apply_function(self, function, **kwargs):
        """
        Aplica a função recebida em todas as imagens
        :param function: função para executar na imagem
        :param kwargs: argumentos para a função
        """
        for image_handler in self.image_handlers:
            image_handler.apply_function(function, **kwargs)

    def show_images(self, only_fruits=False):
        """
        Mostra todas as imagens uma por vez
        only_fruits: se verdadeiro mostra somente a imagem da fruta cortada
            de acordo com o metadado
        """
        for image_handler in self.image_handlers:
            image_handler.show_fruits() if only_fruits else image_handler.show_image()

    def segmentation_k_means(self, K=2, attempts=10):
        """
        Aplica o algoritmo de segmentação do K-means em todas as imagens
        :param K: Define o número de clusters / grupos aos quais um pixel
                  pode pertencer
        :param attempts: Número de tentativas máximo
        """
        # Converte as cores para RGB
        self.apply_function(cv2.cvtColor, code=cv2.COLOR_BGR2RGB)
        # Define o critério
        criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 10, 1.0)
        for image_handler in self.image_handlers:
            # Roda o kmean em todos os image handlers
            image_handler.apply_kmean(criteria, K, attempts)




