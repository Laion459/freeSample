#include "student.h"


Class createClass(std::string course){
    Class clazz;
    clazz.course = course;
    return clazz;
}
void addStudent(Class &clazz, Student student){
    student.id = clazz.nezxtId++;
    clazz.students[clazz.numberStudent++] = student;
}
bool findStudentById(Class &clazz,int id, Student &student){
    for (int i = 0; i < clazz.numberStudent; ++i) {
        if (clazz.students[i].id == id){
            student = clazz.students[i];
            return true;
        }
    }
    return false;
}