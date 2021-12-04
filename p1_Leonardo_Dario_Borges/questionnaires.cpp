//
// Created by laion on 07/04/2021.
//
#include "questionnaires.h"

/**
 * preenche array de perguntas
 * @return structs de perguntas
 */
Questions inputQuestinnaires(){
    Question arrayQuestions[MAX_QUESTIONS] = {
            {1, "Quem era o presidente do Brasil, antes de Dilma assumir o cargo? ", "Fernando Henrique Cardoso",
             "Fernando Collor De Melo", "Itamar Franco", "lula",4},
            {2, "Qual das substancias pode causar cancer? ", "agua com gas", "bebida alcoolica", "cigarro", "cha",3},
            {3, "o que a coroa da Estatua da Liberdade representa? ", "A liberdade dos EUA", "as 13 colonias",
             "as cidades mais famosas de NY", "Os 7 continentes",4},
    };
    Questions questions;
    for (int i = 0; i < 3; ++i) {
        questions.idCode = i;
        //questions.questions = arrayQuestions[rand() % 3];
        questions.nuberToQuestions = i;
    }
    return questions;
}

/**
 * cria uma pergunta
 * @param question parametros para inicializar a estrutura
 * @return retorna uma pergunta pronta com todos os parametros necesarios na estrutura
 */
Question createQuestion(){
    Question question = {2, "Qual das substancias pode causar cancer? ", "agua com gas", "bebida alcoolica", "cigarro", "cha",3};
    return question;
}

/**
 * adiciona uma pergunta
 * @param questions array dentro do struckt a ser inserido a pergunta
 * @param question pergunta a ser inserida
 * @return perguntas com a pergunta nova
 */
Questions addQuestion(Questions &questions,Question &question){
    questions.questions->question = " esta funcionando inserir perguntas? no questionario?";
    questions.nuberToQuestions++;
    questions.idCode++;
    return questions;
}

/**
 * deleta pergunta passando o idcode referente a pergunta
 * @param questions perguntas onde vai ser eliminado
 * @param idcode codigo da pergunta a ser removida da lista
 * @return nova lista organizada sem a pergunta removida
 */
Questions removeQuestion(Questions &questions,int idcode){
    for (int i = 0; i < questions.nuberToQuestions; ++i) {
        if (questions.questions->idQuestion == idcode){
            questions.questions[i] = questions.questions[i+1];
            questions.nuberToQuestions--;
        }
    }
    return questions;
}

/*
 * busca uma pergunta especifica pelo codigo id
 */
void searchQuestion(Questions questions,int idcode){
    for (int i = 0; i < questions.nuberToQuestions; ++i) {
        if (questions.questions->idQuestion == idcode){
            std::cout<<questions.questions<<std::endl;
        }else{
            std::cout<<idcode<<" no found "<<std::endl;
        }
    }
}

/**
 * adiciona um questionario
 * @param questionnaires
 * @param name
 * @return
 */
Questionnaires addQuestionnaires(Questionnaires &questionnaires,std::string &name){
    questionnaires.name = name;
    questionnaires.idCode++;
    return questionnaires;
}

/**
 * remove um questionario
 * @param questionnaires questionario onde sera removido
 * @param idcode codigo id para localizar qual sera removido
 * @return retorna o questionario ordenado já sem o questionario removido
 */
Questionnaires removeQuestionnaires(Questionnaires &questionnaires, int idcode){
    for (int i = 0; i < questionnaires.sizeQuiz; ++i) {
        if (questionnaires.idCode == idcode){
            questionnaires.quiz[i] = questionnaires.quiz[i+1];
            questionnaires.sizeQuiz--;
        }
    }
    return questionnaires;
}

/**
 * procura e mostra na tela um questionario pelo id
 * @param questionnaires questionarios a serem procurados
 * @param idcode codigo de selecao para mostrar na tela
 */
void searchQuestionnaires(Questionnaires questionnaires,int idcode){
    for (int i = 0; i < questionnaires.sizeQuiz; ++i) {
        if (questionnaires.idCode == idcode){
            std::cout<<questionnaires.quiz << std::endl;
        }else{
            std::cout<<" codigo id invalido "  << std::endl;
        }
    }
}

/*
 * mostra na tela o print da pergunta e suas alternativas
 */
void printQuestion(Questions questions){
    std::cout<<questions.questions->question<<std::endl;
    std::cout<<questions.questions->a<<std::endl;
    std::cout<<questions.questions->b<<std::endl;
    std::cout<<questions.questions->c<<std::endl;
    std::cout<<questions.questions->d<<std::endl;
}