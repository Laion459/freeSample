from math import floor

import cv2
import numpy as np


class ImageHandler:

    def __init__(self, image_1_path, image_2_path):
        self.image_1 = cv2.imread(image_1_path)
        self.image_2 = cv2.imread(image_2_path)
        self.result = self.image_1.copy()

    def iterate(self, calculation):
        """
        Itera sobre a altura e a largura da image_1 e faz o calculo recebido
        :param calculation: função que será chamada no pixel
        """
        # itera sobre a altura da imagem
        for x in range(self.image_1.shape[0]):
            # itera sobre a largura da imagem
            for y in range(self.image_1.shape[1]):
                # itera sobre o GBR
                for z in range(3):
                    try:
                        calculation(x, y, z)
                    except:
                        continue

    def apply_gray_scale(self):
        """
        Aplica a escala de cinza na image_1 e image_2
        """
        def calculate(x, y, z):
            gray[0][x, y] = np.clip(
                0.07 * self.image_1[x, y, 0] + 0.72 * self.image_1[x, y, 1] + 0.21 * self.image_1[x, y, 2], 0, 255)
            gray[1][x, y] = np.clip(
                0.07 * self.image_2[x, y, 0] + 0.72 * self.image_2[x, y, 1] + 0.21 * self.image_2[x, y, 2], 0, 255)

        gray = [np.zeros((self.image_1.shape[0], self.image_1.shape[1]), np.uint8),
                np.zeros((self.image_2.shape[0], self.image_2.shape[1]), np.uint8)]
        self.iterate(calculate)
        self.image_1 = gray[0]
        self.image_2 = gray[1]

    def arithmetic(self, operation):
        """
        Faz o calculo aritimético recebido.
        :param operation: pode ser "+", "-", "/" ou "*"
        """
        def sum(x, y, z):
            self.result[x][y][z] = (int(self.image_1[x][y][z]) + int(self.image_2[x][y][z])) / 2

        def subtraction(x, y, z):
            result = int(self.image_1[x][y][z]) - int(self.image_2[x][y][z])
            self.result[x][y][z] = 0 if result < 0 else result

        def multiplication(x, y, z):
            result = int(self.image_1[x][y][z]) * int(self.image_2[x][y][z])
            self.result[x][y][z] = 255 if result > 255 else result

        def division(x, y, z):
            result = int(self.image_1[x][y][z]) / int(self.image_2[x][y][z])
            self.result[x][y][z] = 0 if result < 0 else result

        if operation == "+":
            self.iterate(sum)
        elif operation == "-":
            self.iterate(subtraction)
        elif operation == "*":
            self.iterate(multiplication)
        elif operation == "/":
            self.iterate(division)

    def isolate(self, color):
        """
        Isola a cor recebida por parametro
        :param color: pode ser "red", "green" ou "blue"
        """
        def isolate_red(x, y, z):
            self.result[x][y][0] = 0
            self.result[x][y][1] = 0

        def isolate_green(x, y, z):
            self.result[x][y][0] = 0
            self.result[x][y][2] = 0

        def isolate_blue(x, y, z):
            self.result[x][y][1] = 0
            self.result[x][y][2] = 0

        if color == "red":
            self.iterate(isolate_red)
        elif color == "green":
            self.iterate(isolate_green)
        elif color == "blue":
            self.iterate(isolate_blue)
        else:
            raise ValueError("Cor inválida!")

    def arithmetic_average(self):
        """
        Faz o calculo de média aritimética das imagens iamge_1 e image_2
        """
        def calculate(x, y, z):
            self.result[x][y] = (int(self.image_1[x][y]) + int(self.image_2[x][y])) / 2

        self.apply_gray_scale()
        self.iterate(calculate)

    def arithmetic_weighted_average(self, weight_1=7, weight_2=3):
        """
        Faz o calculo da média aritimética ponderada das imagens image_1 e image_2
        :param weight_1: peso da image_1
        :param weight_2: peso da image_2
        """
        def calculate(x, y, z):
            self.result[x][y] = ((int(self.image_1[x][y]) * weight_1) + (int(self.image_2[x][y])) * weight_2) / 2

        self.apply_gray_scale()
        self.iterate(calculate)

    def thresholding(self, L=127):
        """
        Faz a limirarização das imagem image_1
        :param L: delimitante do limiar
        """
        def calculate(x, y, z):
            self.result[x][y] = 255 if int(self.image_1[x][y]) > L else 0

        self.apply_gray_scale()
        self.iterate(calculate)

    def convolution(self, mask):
        """
        Faz a convolução genérica da imagem image_1
        :param mask: mask to be used in calculate
        """
        def calculate(x, y, z):
            mask_size = len(mask)
            temp = 0
            for mask_column in range(mask_size):
                x_pos = x + (mask_column - floor(mask_size / 2))
                # Verifica se é menor que 0 pois o python aceita valores negativos para acessar as listas
                if x_pos < 0:
                    raise ValueError("Posição de X inválida!")
                for mask_line in range(mask_size):
                    y_pos = y + (floor(mask_size / 2) - mask_line)
                    # Verifica se é menor que 0 pois o python aceita valores negativos para acessar as listas
                    if y_pos < 0:
                        raise ValueError("Posição de Y inválida!")
                    temp += self.image_1[x_pos][y_pos][z] * mask[mask_line][mask_column]
            self.result[x][y][z] = temp / (mask_size*mask_size)

        self.iterate(calculate)

    def dilation(self, structure_element):
        """
        Faz a dilatação da imagem de acordo com a estrutura recebida
        :param structure_element: estrutura para realizar a dilatação
        """
        def calculate(x, y, z):
            central_element = floor(len(structure_element) / 2)
            # Verifica se é menor que 0 pois o python aceita valores negativos para acessar as listas
            if x - central_element < 0 or y - central_element < 0:
                raise ValueError("Pixel inválido!")
            if self.image_1[x][y] > 0:
                for elem_x, x_val in enumerate(structure_element):
                    for elem_y, y_val in enumerate(x_val):
                        if y_val == 1:
                            self.result[x + (elem_x - central_element)][y + (elem_y - central_element)] = self.image_1[x][y]

        self.apply_gray_scale()
        self.iterate(calculate)

    def erosion(self, structure_element, zero_result=True):
        """
        Faz a erosão da imagem de acordo com a estrutura recebida
        :param structure_element:estrutura para realizar a erosão
        :return:
        """
        def calculate(x, y, z):
            central_element = floor(len(structure_element) / 2)
            # Verifica se é menor que 0 pois o python aceita valores negativos para acessar as listas
            if x - central_element < 0 or y - central_element < 0:
                raise ValueError("Pixel inválido!")
            counter = 0
            for elem_x, x_val in enumerate(structure_element):
                for elem_y, y_val in enumerate(x_val):
                    if self.image_1[x + (elem_x - central_element)][y + (elem_y - central_element)] == 255 and y_val == 1:
                        counter += 1
            if counter == 5:
                self.result[x][y] = 255
        if zero_result:
            self.result = np.zeros(np.array(self.image_1.shape))
        self.apply_gray_scale()
        self.iterate(calculate)

    def opening(self, structure_element):
        """
        Faz a abertura da imagem de acordo com a estrutura recebida
        :param structure_element: estrutura para realizar a abertura
        """
        self.erosion(structure_element)
        self.dilation(structure_element)

    def closing(self, structure_element):
        """
        Faz o fechamento da imagem de acordo com a estrutura recebida
        :param structure_element: estrutura para realizar o fechamento
        """
        self.dilation(structure_element)
        self.erosion(structure_element, False)

    def show_image(self):
        cv2.imshow("Resultado", self.result)
        cv2.waitKey(0)
        cv2.destroyAllWindows()


if __name__ == "__main__":
    # SOMA ARITMÉTICA
    image_handler = ImageHandler("imagens/c.jpg", "imagens/i.jpg")
    image_handler.arithmetic("/")
    image_handler.show_image()

    # SUBTRAÇÃO ARITMÉTICA
    # image_handler = ImageHandler("imagens/yoda.jpg", "imagens/yoda2.jpg")
    # image_handler.arithmetic("-")
    # image_handler.show_image()

    # DIVISÃO ARITMÉTICA
    # image_handler = ImageHandler("imagens/yoda.jpg", "imagens/yoda2.jpg")
    # image_handler.arithmetic("/")
    # image_handler.show_image()

    # MULTIPLICAÇÃO ARITMÉTICA
    # image_handler = ImageHandler("imagens/yoda.jpg", "imagens/yoda2.jpg")
    # image_handler.arithmetic("*")
    # image_handler.show_image()

    # ISOLA O VERMELHO
    # image_handler = ImageHandler("imagens/yoda.jpg", "imagens/yoda2.jpg")
    # image_handler.isolate("red")
    # image_handler.show_image()

    # ISOLA O VERDE
    # image_handler = ImageHandler("imagens/yoda.jpg", "imagens/yoda2.jpg")
    # image_handler.isolate("green")
    # image_handler.show_image()

    # ISOLA O AZUL
    # image_handler = ImageHandler("imagens/yoda.jpg", "imagens/yoda2.jpg")
    # image_handler.isolate("blue")
    # image_handler.show_image()

    # MÉDIA ARITMÉTICA
    # image_handler = ImageHandler("imagens/yoda.jpg", "imagens/yoda2.jpg")
    # image_handler.arithmetic_average()
    # image_handler.show_image()

    # MÉDIA ARITMÉTICA PONDERADA
    # image_handler = ImageHandler("imagens/yoda.jpg", "imagens/yoda2.jpg")
    # image_handler.arithmetic_weighted_average()
    # image_handler.show_image()

    # LIMIARIZAÇÃO
    # image_handler = ImageHandler("imagens/yoda.jpg", "imagens/yoda2.jpg")
    # image_handler.thresholding()
    # image_handler.show_image()

    # CONVOLUÇÃO
    # mask = [[1, 1, 1, 1, 1],
    #         [1, 1, 1, 1, 1],
    #         [1, 1, 1, 1, 1],
    #         [1, 1, 1, 1, 1],
    #         [1, 1, 1, 1, 1]]
    # image_handler = ImageHandler("imagens/yoda.jpg", "imagens/yoda2.jpg")
    # image_handler.convolution(mask)
    # image_handler.show_image()

    # DILATAÇÃO
    # structure_element = [[0, 1, 0],
    #                      [1, 1, 1],
    #                      [0, 1, 0]]
    # image_handler = ImageHandler("imagens/j.png", "imagens/j2.png")
    # image_handler.dilation(structure_element)
    # image_handler.show_image()

    # EROSÃO
    # structure_element = [[0, 1, 0],
    #                      [1, 1, 1],
    #                      [0, 1, 0]]
    # image_handler = ImageHandler("imagens/j.png", "imagens/j2.png")
    # image_handler.erosion(structure_element)
    # image_handler.show_image()

    # ABERTURA
    # structure_element = [[0, 1, 0],
    #                      [1, 1, 1],
    #                      [0, 1, 0]]
    # image_handler = ImageHandler("imagens/j2.png", "imagens/j3.png")
    # image_handler.opening(structure_element)
    # image_handler.show_image()

    # FECHAMENTO
    # structure_element = [[0, 1, 0],
    #                      [1, 1, 1],
    #                      [0, 1, 0]]
    # image_handler = ImageHandler("imagens/j3.png", "imagens/j3.png")
    # image_handler.closing(structure_element)
    # image_handler.show_image()
