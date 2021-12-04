#include <iostream>
//      * Lista 02 modularizacao *
//1. Preencher um conjunto de números inteiros que represente a série 1!/1+2!/2+3!/3+4!/4+5!/5..., onde n!
//representa o fatorial de n. Considere passagem por referência.
/*
 * valida numero positivos >= 1
 */
void validateFactorial(int number){
    if (number < 1){
        std::cout<<" Error... Numero digitado : "<<number<< " esta fora do intervalo"<<std::endl;
        abort();
    }
}
// Calcula o fatorial de um número.
/**
 * calcula o fatorial de um numero
 * @param number numero a ser calculado
 * @return valor factorial
 */
int factorial(int number){
    validateFactorial(number);
    float factorial = 1;
    for (int i = 1; i <= number; i++){
        factorial *= i;
    }
    return factorial;
}
/**
 * somatorio de conjunto de valores e representacao
 * @param number numero parametro ate n!
 * @return total da soma dos calculos da sequencia
 */
int sumFactorial(int number){
    validateFactorial(number);
    int sum = 1;
    for (int i = 1; i < factorial(number) ; i++) {
        sum += factorial(i) / i;
    }
    return sum;
}
/*
 * teste sumFactorial
 */
void testSumFactorial(){
    int numbers[] = {1,2,3,4,5};
    for (int i = 0; i < sizeof(numbers)/ sizeof(int); i++) { //1!/1+2!/2+3!/3+4!/4
        std::cout<<numbers[i]<<"!/"<<i+1<<"+"<<sumFactorial(numbers[i]);
    }
    std::cout<<std::endl;
}
//2. Preencher um array com todos os tokens de uma dada string.
/**
 * tokens de uma string
 * @param toString string a ser transformada
 * @return string transformada
 */
std::string tokensString(std::string toString){
    int array[] = {0};
    for (int i = 0; i < toString.size(); i++) {
        array[i] = toString[i];
    }
    return toString;
}
/*
 * teste tokensString
 */
void testTokensTtring(){
    std::string toString = "aaa;bbb;ccc;leonardo";
    std::cout<<tokensString(toString);
    std::cout<<std::endl;
}
/*3. Ordenar (crescente) um conjunto de números inteiros. Considere passagem por referência.
 */
void swap(int *number, int *size){
    int temp = *number;
    *number = *size;
    *size = temp;
}
std::string bubbleSort(int number[],int size){
    std::string bubbleSort[] ="";
    for (int i = 0; i < size; i++) {
        if (number[i] > number[i+1] ){
            swap (&number[i],&number[i+1]);
        }
    }
    std::cout<<bubbleSort(number, size-1);
}
void testbubbleSort(){
    int size = 10;
    int number[] = {1,2,4,58,3,5,4,7,14,20};
    std::cout<<" lista de numeros desordenados: "<<std::endl;
    for (int i = 0; i < size; i++) {
        std::cout<<number[i]<<",";
    }
    std::cout<<std::endl;
    std::cout<<" lista de numeros desordenados: "<<std::endl;
    for (int i = 1; i < size; i++) {
        std::cout<<bubbleSort(number,size)<<std::endl;
    }
}
/*     welcome
 */
void welcome(){
    std::cout<<" ***************************"<<std::endl;
    std::cout<<" *        WELCOME          * "<<std::endl;
    std::cout<<" ***************************"<<std::endl;
    std::cout<<" * Lista 02 Modularizacao *"<<std::endl;
    std::cout<<" ***************************"<<std::endl;
}

void menu(){
    //welcome();
    //testSumFactorial();                // 01 = somatorio
    //testTokensTtring();                // 02 = tokens de string
    testbubbleSort();                  // 03 = ordenar arrai de inteiros bubble Sort
}

int main() {
    menu();
    return 0;
}
