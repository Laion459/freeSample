#include <iostream>
#include "pointers.h"
#include <cstdlib>

void pointerTest(){
    std::cout<<std::endl;
    std::cout<<"Pointer test, count, &, *"<<std::endl;
    std::cout<<std::endl;
    int count = 10;
    int* pointer = &count;
    std::cout << "*pointer: "<<*pointer << std::endl;
    (*pointer)++;
    std::cout << "*pointer: "<<*pointer << std::endl;
    std::cout << "count: "<<count << std::endl;
}
void testMalloc01(){
    std::cout<<std::endl;
    std::cout<<" test: malloc Pointer "<<std::endl;
    std::cout<<std::endl;
    int* pointer = nullptr;
    pointer = (int*) malloc(sizeof(int));
    if (!pointer){
        std::cout<<" Error: out of memory "<<std::endl;
        abort();
    }
    *pointer = 55;
    std::cout<< "*Pointer: "<< *pointer<<std::endl;
    (*pointer)++;
    std::cout<< "Pointer: "<<pointer <<std::endl;
    std::cout<< "&Pointer: "<< &pointer <<std::endl;
    std::cout<< "*Pointer: "<< *pointer<<std::endl;
    free(pointer);
}
void allocTest(){
    std::cout<<std::endl;
    std::cout<<" test: Alloc array"<<std::endl;
    std::cout<<std::endl;
    float* array = nullptr;
    array = (float*) calloc(10, sizeof(float));
    if (!array){
        std::cout<<" Error! Out of memory "<<std::endl;
        abort();
    }
    for (int i = 0; i < 10; i++) {
        std::cout<<"Valor da posicao: " << i << " = " << array[i]
        << " = " << *(array + 1) <<std::endl;
    }
    free(array);
}
void mallocTest(){
    std::cout<<std::endl;
    std::cout<<" test: malloc array "<<std::endl;
    std::cout<<std::endl;
    float* array = nullptr;
    array = (float*) malloc( sizeof(float));
    if (!array){
        std::cout<<" Error! Out of memory "<<std::endl;
        abort();
    }
    for (int i = 0; i < 10; i++) {
        std::cout<<"Valor da posicao: " << i << " = " << array[i]
                 << " = " << *(array + 1) <<std::endl;
    }
    free(array);
}

void allTest(){
   pointerTest();
   testMalloc01();
   allocTest();
   mallocTest();
}