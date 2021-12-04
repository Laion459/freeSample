#pragma once
#include "testStudent.h"
#include <iostream>
#include <string>
#include <ctime>

const int MAX_STUDENTS = 100;
// declaração de structs

// *struct estudante com seu codigo id e nome
struct Student{
    int id;
    std::string name;
};
// *struct turma com array de estudantes e tamnaho ocupados do array
struct Class{
    std::string course;
    int nezxtId = 1;
    int numberStudent = 0;
    Student students[MAX_STUDENTS];
};
// declarção de assinaturas

//cria a turma
Class createClass(std::string course);

//adiciona um estudante na turma
void addStudent(Class &clazz, Student student);

//acha o estudante
bool findStudentById(Class &clazz,int id, Student &student);