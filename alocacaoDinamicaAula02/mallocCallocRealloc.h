#pragma once
#include "testsMallocCallocRealloc.h"
#include "iostream"

void calloc();
void realloc();
void newReallocMalloc();
void array2D();
struct Student{
    std::string id;
    std::string name;
};

void studentTest();
void studentPointer();

struct Node {
    std::string data;
    Node* next = nullptr;
};
void insertAtFirst(Node* &list, Node* element);
void showList(Node* list);