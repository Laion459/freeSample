#include "questionnaireManager.h"

/*
 * show elements
 */
void showList(Question* list) {
    Question* element = list;
    while (element != nullptr) {
        std::cout << element->question << std::endl;
        std::cout << element->options << std::endl;
        element = element->next;
    }
    std::cout << "***************" << std::endl;
}

/*
 * check if list is not null
 */
bool isEmptyQuestion(Question* list) {
    return list == nullptr;
}

/*
 * dynamically add a new question
 */
void addQuestion(Question* &list, Question* element){
    if (isEmptyQuestion(list)) {
        list = element;
        return;
    }
    (element->numbersOfQuestions)++;
    element->next = list;
    list = element;
}

/*
 * look for a question by id
 */
void searchQuestion(Question* &list, Question* element) {
    while (list->next != nullptr){
        if (list->id == element->id){
            std::cout<<" pergunta pesquisada: "<<element->question<<element->options<<std::endl;
            return;
        }
    }
    std::cout<<" pergunta invalida! "<<std::endl;
}

/*
 * delete for a question by id
 */
void deleteQuestion(Question* &list, Question* &element){
    while (list->next != nullptr){
        if (list->id == element->id){
            std::cout<<" pergunta a ser eleiminada: "<<element->question<<element->options<<std::endl;
            //??
            delete element;
            return;
        }
    }
    std::cout<<" pergunta invalida! "<<std::endl;
}

/*
 * check if quiz is not null
 */
bool isEmptyQuiz(Quiz* quiz) {
    return quiz == nullptr;
}


/*
 * show in elements
 */
void showQuiz(Quiz* quiz) {
    Quiz* element = quiz;
    while (element != nullptr) {
        std::cout << element->title << std::endl;
        std::cout << element->course << std::endl;
        element = element->next;
    }
    std::cout << "----------------------" << std::endl;
}

/*
 * dynamically add a new quiz
 */
void addQuiz(Quiz* &quiz, Quiz* element){
    if (isEmptyQuiz(quiz)) {
        quiz = element;
        return;
    }
    (element->numbersOfQuestions)++;
    element->next = quiz;
    quiz = element;
}

/*
 * look for a quiz by id
 */
void searchQuiz(Quiz* &quiz, Quiz* element) {
    while (quiz->next != nullptr){
        if (quiz->id == element->id){
            std::cout<< " questionario pesquisado: " <<" id: "<<quiz->id <<std::endl;
            std::cout<<"titulo: "<<quiz->title<<std::endl;
            return;
        }
    }
    std::cout<<" questionnaires invalido! "<<std::endl;
}

/*
 * look for a quiz by id
 */
void deleteQuiz(Quiz* &quiz, Quiz* &element){
    while (quiz->next != nullptr){
        if (quiz->id == element->id){
            std::cout<<" Id a ser eleiminado: "<<element->id<<std::endl;
            std::cout<<" Questionario a ser eleiminado: "<<element->title<<std::endl;
            //??
            delete element;
            return;
        }
    }
    std::cout<<" pergunta invalida! "<<std::endl;
}

/*
 * check if questionnaires is not null
 */
bool isEmptyQuestionnaires(Questionnaires* questionnaires) {
    return questionnaires == nullptr;
}

/*
 * show in elements of questionnaires
 */
void showQuestionnaires(Questionnaires* questionnaires) {
    Questionnaires* element = questionnaires;
    while (element != nullptr) {
        std::cout << element->quiz.title << std::endl;
        //std::cout << element->id << std::endl;
        element = element->next;
    }
    std::cout << "++++++++++++++++++++" << std::endl;
}

/*
 * dynamically add a new questionnaires
 */
void addQuestionnaires(Questionnaires* &questionnaires, Questionnaires* element){
    if (isEmptyQuestionnaires(questionnaires)) {
        questionnaires = element;
        return;
    }
    element->next = questionnaires;
    questionnaires = element;
}

/*
 * look for a questionnaires by id
 */
void searchQuestionnaires(Questionnaires* &questionnaires, Questionnaires* element) {
    while (questionnaires->next != nullptr){
        if (questionnaires->id == element->id){
            std::cout << " questionario pesquisado: " << " id: " << questionnaires->id << std::endl;
            std::cout << "titulo: " << questionnaires->quiz.title << std::endl;
            return;
        }
    }
    std::cout<<" questionnaires invalido! "<<std::endl;
}

/*
 * delete for a questionnaires by id
 */
void deleteQuestionnaires(Questionnaires* &questionnaires, Questionnaires* &element){
    while (questionnaires->next != nullptr){
        if (questionnaires->id == element->id){
            std::cout<<" Id a ser eleiminado: "<<element->id<<std::endl;
            std::cout<<" Questionario a ser eleiminado: "<<element->quiz.title<<std::endl;
            //??
            delete element;
            return;
        }
    }
    std::cout<<" questionario invalido! "<<std::endl;
}
