#include "game.h"
/**
 * Gera o senha aleatoria
 * @param lengthRandomKey tamanho da senha
 * @return retorna senha aleatoria
 */
std::string randomKey(int lengthRandomKey){
    std::string randomKey;
    srand(time(nullptr));
    for (int i=0; i < lengthRandomKey; i++){
        int index = rand() % 6;
        randomKey += KEYCOLORS[index];
    }
    return randomKey;
}
/**
 * gera e salva a chave aleatoria principal do sistema
 * @return string com as chaves a ser adivinhada
 */
std::string randomKeySystem(){
    std::string keySystem = randomKey(4);
    return keySystem;
}
/*
 * boas vindas
 */
void welcom(){
    std::cout<<" **********         WELCOM         ***********"<<std::endl;
    std::cout<<" **********  It's MASTER MIND 2.0  ***********"<<std::endl;
    std::cout<<"                                              "<<std::endl;


}
/*
 * mensagem se vencer / chama menu
 */
void win(){
    std::cout<<"                                              "<<std::endl;
    std::cout<<" **********         You Win!                         ***********"<<std::endl;
    std::cout<<" **********  voce venceu com total:                  ***********"<<std::endl;//<<funcaoTentativas()<<"x tentativas"
    std::cout<<" **********  chave secreta : "<<randomKeySystem()<<"                    ***********"<<std::endl;
    menu();

}
/*
 * mensagem se perder/ chama menu
 */
void gameOver(){
    std::cout<<" **********         GAME OVER         ***********"<<std::endl;
    std::cout<<" **********       Used all lives      ***********"<<std::endl;
    std::cout<<"                                              "<<std::endl;
    menu();

}
void validateInputMenu(int option){
    if (option < 1 || option > 4){
        std::cout<<" Opcao invalida! Por favor digite novamente: "<<std::endl;
        menu();
    }
}
/*
 * menu opcoes / menu principal
 * 1 para iniciar jogo
 * 2 para escolher tamanho da sequencia
 * 3 para escolher quantidade de vidas
 * 4 para encerrar o programa
 */
void menu(){
    int options = 0;
    std::cout<<" **** MENU ****"<<std::endl;
    std::cout<<" 1 voltar a comecar "<<std::endl;
    std::cout<<" 2 Sair "<<std::endl;
    std::cout<<" 3 incrivel sair tambem "<<std::endl;
    std::cin >> options;
    validateInputMenu(options);
    switch (options) {
        case 1:
            runGame();
            break;
        case 2:
            exit(0);
        case 3:
            abort();
    }
}
/*
 * valida o tamanho da entrada de dados.
 */
void validateInputLength(std::string inputPlayer){
    if (inputPlayer.length() != 4){
        std::cout<<" Error!    Tamanho quantidade de elementos digitada e invalida!"<<std::endl;
        std::cout<<" Por favor digite novamente!. "<<std::endl;
        //chama funçao input player
        abort();
    }
}
/**
 * valida se as cores digitadas estao corretas
 * @param inputPlayer entrada de dados do player
 */
void validateInputKeys(std::string inputPlayer){
    for (int i = 0; i < inputPlayer.size(); i++) {
        for (int j = 0; j < inputPlayer.size(); j++) {
            if (inputPlayer[i] != KEYCOLORS[j]){
                std::cout<<" Error!  Cores escolhidas incorretas! "<<std::endl;
                std::cout<<" Por favor digite novamente: "<<std::endl;
                //chama funcao digitar input
                abort();
            }
        }
    }
}
/**
 * Gera entrada de dados de um player de forma aleatoria/randomica.
 * @return retorna chave(key) criada aleatoriamente.
 */
std::string inputPlayerRandom(){
   std::string inputsPlayer;
   //std::cout<<" Digite chave com as iniciais das cores: "<<std::endl;              //deletar aopos o teste***
   //std::cin >> inputsPlayer;
    inputsPlayer = randomKey(4);
    validateInputLength(inputsPlayer);
    //validateInputKeys(inputsPlayer);
    return inputsPlayer;
}
/**
 * salva as vidas do jogador
 * @param lifes numero inteiro de vidas
 * @return retorna quantas vidam restam
 */
int lifesPlayer(int lifes){
    lifes--;
    return lifes;
}
/**
 * verifia se venceu comparando se chaves(key) sao iguais
 * @param inputPlayer entrada de dados do player
 * @param keySystem chave(key) do sistema
 */
void checkWin(std::string inputPlayer,std::string keySystem){
    std::string feedbeck;
    for (int i = 0; i < inputPlayer.size(); i++) {
        if (inputPlayer == keySystem){
            feedbeck[i] += 'B';
        }
    }
    win();
}
/**
 * valida o pin de feedbeck white and N
 * @param inputPlayer entrada da chave(key) do player
 * @param keySystem chave(key) do sistema
 * @return feedbeck para o player
 */
std::string validatePinWhiteAndN(std::string inputPlayer,std::string keySystem,std::string feedbeck){
    for (int i = 0; i < inputPlayer.size(); i++) {
        for (int j = 0; j < inputPlayer.size(); j++) {
            if (inputPlayer[i] == keySystem[j]){
                feedbeck[i] += 'W';
            }else{
                feedbeck[i] += '*';
            }
        }
    }
    std::cout<<feedbeck<<" teste feed "<<std::endl;
    return feedbeck;
}
/**
 * quantifica os acertos e retorna um feedbeck pelas cores
 * @param inputPlayer chave(key) de entrada do player
 * @param keySystem chave(key) so sistema
 * @return retorna feedbeck
 */
std::string feedbeckToInput(std::string inputPlayer,std::string keySystem,std::string feedbeck){
    checkWin(inputPlayer,keySystem);
    validatePinWhiteAndN(inputPlayer,keySystem,feedbeck);
    return feedbeck;
}
void output(std::string inputPlayer,std::string keySystem,std::string feedbeck){
     std::cout<<inputPlayer<<" <= key digitado || feedbeck pins: "<< feedbeckToInput(inputPlayer,keySystem,feedbeck)<<std::endl;
}
void runGame(){
    std::string input,key,feed;
    welcom();
    key = randomKeySystem();
    input = inputPlayerRandom();
    //feed = feedbeckToInput(input,key,feed);
    output(input,key,feed);
    std::cout<<feedbeckToInput(input,key,feed);
}