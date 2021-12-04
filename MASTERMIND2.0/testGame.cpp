#include "testGame.h"

/*
 * testa a chave(key) criada randomicamente.
 */
void testNumberRandomKey(){
    std::cout<<randomKey(4)<<std::endl;
}

/*
 * testa a chave(key) salva no sistema para escalar o jogo.
 */
void testKeySystem(){
    std::cout<<randomKeySystem()<<std::endl;
}

/*
 * mensagem se vencer / chama menu.
 */
void testWin(){
    win();
}

/*
 * testa a entrada de dados aleatoria.
 */
void testinputPlayerRandom(){
    int lifes = 0;
    do {
        std::cout<<inputPlayerRandom()<<std::endl;
        lifes++;
    } while (lifes < 13);
}
/*
 * testa
 */
void testFeedbeck(){
    int lifes = 12;
    do{

    } while (lifesPlayer(lifes) > 0);
}
