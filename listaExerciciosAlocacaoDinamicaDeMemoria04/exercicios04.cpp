#include "exercicios04.h"

//3. Considerando o último slide do material sobre Alocação Dinâmica, implemente funções para:
//a. Incluir um novo nodo no início da lista.
//b. Incluir um novo nodo no final da lista.
//c. Incluir um novo nodo no meio da lista (por exemplo, incluindo strings em ordem alfabética).
//d. Excluir um nodo a partir do valor fornecido.
//e. Procurar por um determinado nodo.

void teste01(){
    int count = 10;
    int* pointer = &count;
    std::cout<<"count: "<<count<<std::endl;
    std::cout<<"&count: "<<&count<<std::endl;
    std::cout<<"Pointer: "<<pointer<<std::endl;
    std::cout<<"&Pointer: "<<&pointer<<std::endl;
    std::cout<<"============================= "<<std::endl;
    (*pointer)++;
    std::cout<<"count: "<<count<<std::endl;
    std::cout<<"&count: "<<&count<<std::endl;
    std::cout<<"Pointer: "<<pointer<<std::endl;
    std::cout<<"&Pointer: "<<&pointer<<std::endl;
}
void validateAllocation(int* pointer){
    if (!pointer){
        std::cout<<"Error! outof memory. "<<std::endl;
    }
}
void allocationmemory(){
    int* pointer = new int;
    validateAllocation(pointer);
    *pointer = 10;
    std::cout<<" pointer: dentro: "<<pointer<<std::endl;
    std::cout<<" *pointer22: "<<*pointer<<std::endl;
    delete pointer;
}
void allocationmemoryArray(){
    int* pointer = new int[5];
    for (int i = 0; i < 5; ++i) {
        pointer[i] = i;
    }
    for (int i = 0; i < 5; ++i) {
        std::cout<<" valor: "<<pointer[i]<<std::endl;
    }
    for (int i = 0; i < 5; ++i) {
        std::cout<<" valor: "<<&pointer[i]<<std::endl;
    }
    delete [] pointer;
}