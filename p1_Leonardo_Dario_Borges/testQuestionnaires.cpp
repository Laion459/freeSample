#include "testQuestionnaires.h"

/*
 * testa se esta adicionando a pergunta
 */
void testAddQuestion(){
    Question question = createQuestion();
    std::cout<<" Pergunta "<<question.question<<std::endl;
    std::cout<<" Opcoes: "<<std::endl;
    std::cout<<" A) "<<question.a<<std::endl;
    std::cout<<" B) "<<question.b<<std::endl;
    std::cout<<" C) "<<question.c<<std::endl;
    std::cout<<" D) "<<question.d<<std::endl;
    std::cout<<" resposta correta e: "<<question.idAnswer<<std::endl;
    //printQuestion(question);
}

void testSearchQuestion(){
    Question question = createQuestion();
    int idCode = 1;
    //searchQuestion(question,idCode);
    notFound();
}

void testRemove(){
    notFound();
}
void notFound(){
    std::cout<<"not found"<<std::endl;
    // Prof querido, peço desculpas pela ignorancia. Tive dificultades ai acabei implementando o que acreditava saber.
    // sei que não foi o esperado mas vamos a luta paciencia....kkkk
}
void testAll(){
    testAddQuestion();
    testSearchQuestion();
    testRemove();
}