#include "testStudent.h"

void showStudent(Student &student){
    std::cout<<student.id << " - " << student.name<<std::endl;
}

void showClass(Class &clazz){
    std::cout
    <<clazz.course <<std::endl;
    std::cout <<"------------------------"<<std::endl;
    for (int i = 0; i < clazz.numberStudent; ++i) {
        showStudent(clazz.students[i]);
    }
    std::cout<<"----"<<std::endl;
}
void testAddStudent(Class &clazz){
    std::string names[] = {"Leonardo","Flavia","Bruna","Amanda","Daniela","Paola","Daniel"};
    Student student;
    student.name = names[rand() % 7];
    addStudent(clazz, student);
    showClass(clazz);
}
void testFindStudent(Class &clazz){
    Student student;
    int id = 2;
    if (findStudentById(&clazz, id, &student)){
        showStudent(student);
    }else{
        std::cout<<" Student "<<id<<" not found"<<std::endl;
    }
}
void allTest(){
    Class clazz = createClass("Algoritmos");
    testAddStudent(Class &clazz);
    testAddStudent(Class &clazz);
    testAddStudent(Class &clazz);
    testFindStudent(& clazz);
};