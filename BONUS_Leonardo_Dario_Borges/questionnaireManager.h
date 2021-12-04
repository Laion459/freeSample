#pragma once
#include <iostream>
#include <string>

struct Question{
    int id;
    std::string question;
    std::string options;
    int numbersOfQuestions;
    std::string correctQuestion;
    Question* next = nullptr;
};

struct Quiz{
    int id;
    std::string title;
    std::string course;
    Question question;
    int numbersOfQuestions;
    Quiz* next = nullptr;
};

struct Questionnaires{
    int id = 0;
    Quiz quiz;
    Questionnaires* next = nullptr;
};

/*
 * show elements
 */
void showList(Question* list);

/*
 * check if list is not null
 */
bool isEmptyQuestion(Question* list);

/*
 * dynamically add a new question
 */
void addQuestion(Question* &list, Question* element);

/*
 * look for a question by id
 */
void searchQuestion(Question* &list, Question* element);

/*
 * delete for a question by id
 */
void deleteQuestion(Question* &list, Question* &element);

/*
 * check if quiz is not null
 */
bool isEmptyQuiz(Quiz* quiz);


/*
 * show in elements
 */
void showQuiz(Quiz* quiz);

/*
 * dynamically add a new quiz
 */
void addQuiz(Quiz* &quiz, Quiz* element);

/*
 * look for a quiz by id
 */
void searchQuiz(Quiz* &quiz, Quiz* element);

/*
 * look for a quiz by id
 */
void deleteQuiz(Quiz* &quiz, Quiz* &element);

/*
 * check if questionnaires is not null
 */
bool isEmptyQuestionnaires(Questionnaires* questionnaires);

/*
 * show in elements of questionnaires
 */
void showQuestionnaires(Questionnaires* questionnaires);

/*
 * dynamically add a new questionnaires
 */
void addQuestionnaires(Questionnaires* &questionnaires, Questionnaires* element);

/*
 * look for a questionnaires by id
 */
void searchQuestionnaires(Questionnaires* &questionnaires, Questionnaires* element);

/*
 * delete for a questionnaires by id
 */
void deleteQuestionnaires(Questionnaires* &questionnaires, Questionnaires* &element);