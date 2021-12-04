from M2.dataset_handler import DataSetHandler

if __name__ == "__main__":
    dataset_handler = DataSetHandler("imagens/test")
    dataset_handler.segmentation_k_means(4)
    dataset_handler.show_images()
