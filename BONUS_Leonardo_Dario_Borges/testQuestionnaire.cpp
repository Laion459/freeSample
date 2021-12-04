#include "testQuestionnaire.h"


void testAddToList() {
    std::cout<<"teste de adicionar perguntas: "<<std::endl;
    Question* list = nullptr;
    Question* question = new Question;
    question->question = "pergunta 01 ";
    addQuestion(list, question);
    showList(list);
    question = new Question;
    question->question = "pergunta 02 ";
    addQuestion(list, question);
    showList(list);
}

void testSearchQuestion(){
    std::cout<<"teste de procurar pergunta: vamos procurar opcao 2"<<std::endl;
    Question* myList = nullptr;
    Question* question = new Question;
    question->question = "pergunta 01 ";
    question->options = "ABCD";
    (question->id)++;
    addQuestion(myList, question);
    //showList(myList);
    question = new Question;
    question->question = "pergunta 02 ";
    question->options = "ABCD";
    (question->id)++;
    addQuestion(myList, question);
    //showList(myList);
    question->id = 2;
    searchQuestion(myList,question);
    //showList(myList);
    delete question;
}

void testDeleteQuestion(){
    std::cout<<"teste de deletar pergunta"<<std::endl;
    Question* myList = nullptr;
    Question* element = new Question;
    element->question = "pergunta 01 ";
    element->options = "ABCD";
    (element->id)++;
    addQuestion(myList, element);
    //showList(myList);
    element = new Question;
    element->question = "pergunta 02 ";
    element->options = "ABCD";
    (element->id)++;
    addQuestion(myList, element);
    showList(myList);
    deleteQuestion(myList,element);
    showList(myList);
    delete element;
}

void testAddQuiz() {
    std::cout<<"teste de adicionar questionario: "<<std::endl;
    Quiz* list = nullptr;
    Quiz* quiz = new Quiz;
    quiz->title = "questionario numero 01 ";
    addQuiz(list, quiz);
    showQuiz(list);
    quiz = new Quiz;
    quiz->title = "questionario numero 02 ";
    addQuiz(list, quiz);
    showQuiz(list);
    delete quiz;
}

void testSearchQuiz(){
    std::cout<<"teste de procurar questionario: "<<std::endl;
    Quiz* myQuiz = nullptr;
    Quiz* quiz = new Quiz;
    quiz->title = "questionario 01";
    (quiz->id)++;
    addQuiz(myQuiz, quiz);
    //showQuiz(myQuiz);
    quiz = new Quiz;
    quiz->title = "questionario 02";
    (quiz->id)++;
    addQuiz(myQuiz, quiz);
    //showQuiz(myQuiz);
    quiz->id = 2;
    searchQuiz(myQuiz, quiz);
    //showQuiz(myQuiz);
    delete quiz;
}

void testDeleteQuiz(){
    std::cout<<"teste de deletar questionario"<<std::endl;
    Quiz* myList = nullptr;
    Quiz* element = new Quiz;
    element->title = "qustionario 01 teste deletar ";
    (element->id)++;
    addQuiz(myList, element);
    //showList(myList);
    element = new Quiz ;
    element->title = "questionario 02 teste de deletar";
    (element->id)++;
    addQuiz(myList, element);
    showQuiz(myList);
    deleteQuiz(myList,element);
    showQuiz(myList);
    delete element;
}

void testAddQuestionnaires() {
    std::cout<<"teste de adicionar questionarios: "<<std::endl;
    Questionnaires* list = nullptr;
    Questionnaires* questionnaires = new Questionnaires;
    questionnaires->quiz.title = "questionarios numero 01 ";
    addQuestionnaires(list, questionnaires);
    showQuestionnaires(list);
    questionnaires = new Questionnaires;
    questionnaires->quiz.title = "questionarios numero 02 ";
    addQuestionnaires(list, questionnaires);
    showQuestionnaires(list);
    delete questionnaires;
}

void testSearchQuestionnaires(){
    std::cout<<"teste de procurar questionarios: "<<std::endl;
    Questionnaires* myQuestionnaires = nullptr;
    Questionnaires* questionnaires = new Questionnaires;
    questionnaires->quiz.title = "questionarios 05";
    (questionnaires->id)++;
    addQuestionnaires(myQuestionnaires, questionnaires);
    //showQuiz(myQuestionnaires);
    questionnaires = new Questionnaires;
    questionnaires->quiz.title = "questionarios 06";
    (questionnaires->id)++;
    addQuestionnaires(myQuestionnaires, questionnaires);
    //showQuiz(myQuestionnaires);
    questionnaires->id = 2;
    searchQuestionnaires(myQuestionnaires, questionnaires);
    //showQuiz(myQuestionnaires);
    delete questionnaires;
}

void testDeleteQuestionnaires(){
    std::cout<<"teste de deletar questionarios"<<std::endl;
    Questionnaires* myList = nullptr;
    Questionnaires* element = new Questionnaires;
    element->quiz.title = "qustionario 01 ";
    (element->id)++;
    addQuestionnaires(myList, element);
    //showList(myList);
    element = new Questionnaires ;
    element->quiz.title = "questionario 02 ";
    (element->id)++;
    addQuestionnaires(myList, element);
    showQuestionnaires(myList);
    deleteQuestionnaires(myList,element);
    showQuestionnaires(myList);
    delete element;
}

void testQuestion(){
    testAddToList();
    testSearchQuestion();
    testDeleteQuestion();
}

void testQuiz(){
    testAddQuiz();
    testSearchQuiz();
    testDeleteQuiz();
}

void testQuestionnaires(){
    testAddQuestionnaires();
    testSearchQuestionnaires();
    testDeleteQuestionnaires();
}

void allTest(){
    testQuestion();
    testQuiz();
    testQuestionnaires();
}