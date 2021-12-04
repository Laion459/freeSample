#pragma once
#include "testGame.h"
#include "allTest.h"
#include <iostream>
#include <string>
#include <ctime>


void welcom();
void win();
void gameOver();
void menu();
const char KEYCOLORS[6] = {'G','B','O','Y','P','R'};
const char PIN[3] = {'B','W','N'};
std::string randomKey(int lengthRandomKey);
std::string randomKeySystem();
std::string inputPlayerRandom();

/**
 * salva as vidas do jogador
 * @param lifes numero inteiro de vidas
 * @return retorna quantas vidam restam
 */
int lifesPlayer(int lifes);
/**
 * verifia se venceu comparando se chaves(key) sao iguais
 * @param inputPlayer entrada de dados do player
 * @param keySystem chave(key) do sistema
 */
void checkWin(std::string inputPlayer,std::string keySystem);
std::string validatePinWhiteAndN(std::string inputPlayer,std::string keySystem,std::string feedbeck);
std::string feedbeckToInput(std::string inputPlayer,std::string keySystem,std::string feedbeck);
void output(std::string inputPlayer,std::string feedbeck);
void runGame();