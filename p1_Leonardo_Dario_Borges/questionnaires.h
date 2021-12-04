#pragma once

#include <ctime>
#include <string>
#include <iostream>

const int MAX_QUIZ = 100;
const int MAX_QUESTIONNAIRES = 10;
const int MAX_QUESTIONS = 1000;

/*
 * estrutura do questionario
 */
struct Quiz{
    int idCode = 1;              // aqui vai gerador aleatorio mas como fazer com rand para nao repetir?
    std::string title;
    std::string course;
    int numberOfQuestions;
    //aqui vai questionario de perguntas[tammaximo]
};

/*
 * estrutura dos questionarios
 */
struct Questionnaires{
    std::string name;
    Quiz quiz[MAX_QUIZ];
    int idCode = 1;             // aqui vai rand()
    int sizeQuiz = 0;
};

/*
 * estrutura pergunta e suas opcoes e resposta
 */
struct Question{
    int idQuestion;             //aqui random
    std::string question;
    std::string a;
    std::string b;
    std::string c;
    std::string d;
    int idAnswer;
};

/*
 * estrutura de perguntas array de perguntas
 */
struct Questions{
    Question questions[MAX_QUESTIONS];
    int idCode = 1;
    int nuberToQuestions = 0;
};

Questions inputQuestinnaires();
Question createQuestion();
Questions addQuestion(Questions &questions,Question &question);
Questions removeQuestion(Questions &questions,int idcode);
void searchQuestion(Questions questions,int idcode);
Questionnaires addQuestionnaires(Questionnaires &questionnaires,std::string &name);
Questionnaires removeQuestionnaires(Questionnaires &questionnaires, int idcode);
void searchQuestionnaires(Questionnaires questionnaires,int idcode);
void printQuestion(Questions questions);