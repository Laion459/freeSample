#include <iostream>
#include "mallocCallocRealloc.h"



void calloc(){
    unsigned char* array = nullptr;
    array = (unsigned char *) calloc(10,1);
    if (!array){
        std::cout<<" Error: out of memory "<<std::endl;
        abort();
    }
    for (int i = 0; i < 10; ++i) {
        std::cout<<" Array "<<unsigned(array[i])<<std::endl;
    }
}
void realloc(){
    unsigned char* array = nullptr;
    array = (unsigned char*) realloc(array, 15);
    if (!array){
        std::cout<<" Error: out of memory "<<std::endl;
        abort();
    }
    for (int i = 0; i < 10; ++i) {
        std::cout<<" Array "<<unsigned(array[i])<<std::endl;
    }
}

void newReallocMalloc(){
    int* array = new int[5];
    for (int i = 0; i < 5; ++i) {
        array[i] = i;
    }
    for (int i = 0; i < 5; ++i) {
        std::cout << array[i] << std::endl;
    }
    delete [] array;
}

void array2D(){
    const int rowCount = 3, colCount = 2;
    int** array2D = new int*[rowCount];
    for (int i = 0; i < rowCount; ++i) {
        array2D[i] = new int[colCount];
    }
    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < rowCount; ++j) {
            std::cout<<j<<" - "<<array2D[i][j]<<std::endl;
        }
    }
    for (int i = 0; i < rowCount; ++i) {
        delete [] array2D[i];
    }
    delete [] array2D;
}
void studentTest(){
    Student* student = new Student;
    (*student).id = "12345";
    (*student).name = "John";
    std::cout << (*student).id << ", ";
    std::cout << (*student).name << std::endl;
    delete student;
}
void studentPointer(){
    Student* student = new Student;
    student->id = "12345";
    student->name = "Johny";
    std::cout << student->id << ", ";
    std::cout << student->name << std::endl;
    delete student;
}
void insertAtFirst(Node* &list, Node* element) {
    if (list == nullptr) {
        list = element;
        return;
    }
    element->next = list;
    list = element;
}
void showList(Node* list) {
    Node* element = list;
    while (element != nullptr) {
        std::cout << element->data << std::endl;
        element = element->next;
    }
    std::cout << "-------- xxx --------" << std::endl;
}