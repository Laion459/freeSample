
#include "mallocCallocRealloc.h"

void testLinkedList01() {
    Node* myList = nullptr;
    Node* student = new Node;
    student->data = "student 01";
    insertAtFirst(myList, student);
    showList(myList);
    student = new Node;
    student->data = "student 02";
    insertAtFirst(myList, student);
    student = new Node;
    student->data = "student 03";
    insertAtFirst(myList, student);
    student = new Node;
    student->data = "student 04";
    insertAtFirst(myList, student);
    showList(myList);
}
void allTest(){
    //calloc();
    //realloc();
    //newReallocMalloc();
    //array2D();
    //studentTest();
    //studentPointer();
    testLinkedList01();
}
