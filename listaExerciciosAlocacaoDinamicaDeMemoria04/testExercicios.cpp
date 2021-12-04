#include "testExercicios.h"

void testAllocation(){
    int* pointer = nullptr;
    allocationmemory();
    std::cout<<" pointer: "<<pointer<<std::endl;
    std::cout<<" *pointer: "<<&pointer<<std::endl;
}

void allTest(){
    //std::cout << "Hello, World!" << std::endl;
    //teste01();
    //testAllocation();
    allocationmemoryArray();
}