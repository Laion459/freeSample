#include <iostream>
#include "cmath"

/*
 * *** Lista 01 Modularização ***
*/
//1. Verificar se um número inteiro é par ou ímpar.
/**
 * verifica se numero inteiro e par o impar
 * @param number numero a ser verificado
 * @return verdadeiro ou falso
 */
bool evenOrOdd(int number){
    return number % 2 == 0;
}
/*
 * teste evenOrOdd(number) se numero inteiro e par ou impar
 */
void testEvenOrOdd(){
    std::cout<<"testEvenOrOdd"<<std::endl;
    int number[10] = {-1,-2,-3,-4,-5,5,4,3,2,1};
    for (int i = 0; i < sizeof(number)/ sizeof(int); i++){
        if (evenOrOdd(number[i]) != 0){
            std::cout<<number[i]<<": Numero Par "<<std::endl;
        }else{
            std::cout<<number[i]<<": Numero Impar "<<std::endl;
        }
    }
}

//2. Verificar se um número é primo ou não
/*
 * validacao de dados para verificacao de primos
 */
void validateNumberPrime(float number){
    if (number < 1){
        std::cout<<" Error! numero negativo "<<number<<std::endl;
        abort();
    }
    if (number == 1){
        std::cout<<"digite numero maior que 1 "<<std::endl;
        std::cout<<number<<" nao e primo!"<<std::endl;
        abort();
    }
}
/**
 * verifica se numero e primo
 * @param number numero a ser verificado
 * @return valor verdadeiro ou falso
 */
bool isPrime(int number){
    validateNumberPrime(number);
    int result = 0;
    for(int i = 2 ; i <= sqrt(number) ; i++)
        if(number % i == 0)
            result++;
    return result;
}
/*
 * testa isPrime() testa um vetor de inteiros se e primo
 */
void testIsPrime(){
    std::cout<<"testIsPrime"<<std::endl;
    int number[10] = {2,3,4,5,6,7,8,9,10,11};
    for (int i = 0; i < sizeof(number)/ sizeof(int); i++){
        if (isPrime(number[i]) == 0){
            std::cout<<number[i]<<":  E primo "<<std::endl;
        }else{
            std::cout<<number[i]<<":  Nao e primo "<<std::endl;
        }
    }
}

//3. Converter um número decimal para um número binário
/**
 * converte numero inteiro decimal para binario
 * @param number numero decimal a ser convertido
 * @return numero em binario formato string
 */
std::string decimalToBinary(int number){
    std::string binario = "";
    int i = 0;
    while (number > 0){
        if (number % 2 == 0){
            binario = "0" + binario;
            number /= 2;
            i++;
        }else{
            binario = "1 " + binario;
            number /= 2;
            i++;
        }
    }
    return binario;
}
/*
 * testa um array de numeros inteiros convertendo a binario
 */
void testDecimalToBinary(){
    std::cout<<"testDecimalToBinary"<<std::endl;
    int number[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    for (int i = 0; i < sizeof(number)/ sizeof(int); i++){
        std::cout<<" O numero: "<<number[i]<<" em binario ==> = "<<decimalToBinary(number[i])<<std::endl;
    }
}

//4. Criar uma função de conversão

//5. Calcular o fatorial de um número.
/**
 * calcula o fatorial de um numero
 * @param number numero a ser calculado
 * @return valor factorial
 */
int factorial(int number){
    float factorial = 1;
    for (int i = 1; i <= number; i++){
        factorial *= i;
    }
    return factorial;
}
/*
 * testa fatorial
 */
void testFactorial(){
    std::cout<<"testFactorial"<<std::endl;
    int arrayTest[10] = {1,2,3,4,5,6,7,8,9,10};
    for(int i = 0; i < sizeof(arrayTest)/ sizeof(int);i++){
        std::cout<<arrayTest[i]<<"! = "<<factorial(arrayTest[i])<<std::endl;
    }
}

//6. Calcular o somatório da série
/**
 * calcula soma da serie
 * @param number numero n para inicio do somatorio
 * @return total do somatorio
 */
float calculateSum(int number){
    float sum = 0;
    for (int i = 1; i <= number; i++){
        sum += factorial(i) / i;
    }
    return sum;
}
/*
 * testa calculateSum com array de testes
 */
void testCalculateSum(){
    std::cout<<"testCalculateSum"<<std::endl;
    float numbersTest[10] = {1,2,3,4,5,6,7,8,9,10};
    for (int i = 0; i < sizeof(numbersTest) / sizeof(float); i++){
        std::cout<<" numero = "<<numbersTest[i]<<" total soma = "<<calculateSum(numbersTest[i])<<std::endl;
    }
}

//7. Calcular o produtório de todos os números pares de um dado conjunto.
/**
 * calcula o produtorio de numeros pares em um array de inteiros
 * @param number numero a ser testado
 * @param size tamanho do array
 * @return total do produtorio
 */
float productCalculate(int number, int size){
    float multiplication = 1;
    for (int i = 0; i < size; i++){
        if (number % 2 == 0){
            multiplication += multiplication * number;
        }
    }
    return multiplication;
}
/*
 * teste productCalculate testando um array de inteiros e fazendo a soma dos produtos
 */
void testProductCalculate(){
    std::cout<<"testProductCalculate"<<std::endl;
    int number[10] ={1,2,3,4,5,6,7,8,9,10};
    int size = 10;
    for (int i = 0; i < size; i++){
        if (number[i] % 2 == 0){
            std::cout<<" numero testado = "<<number[i]<<" total soma dos produtos = "<<productCalculate(number[i],size)<<std::endl;
        }
    }
}

//8. Retornar o primeiro número primo de uma dada lista de números.
/**
 * retorna primeiro elemento primo de um array de inteiros
 * @param number numero a ser testado
 * @param size tamanho do array
 * @return primeiro elemento primo
 */
bool primariNumberPrime(int number[], int size){
    int prime = 0;
    for (int i = 0; i < size; ++i) {
        if (isPrime(number[i]) == 0){
            prime = number[i];
        }
    }
    return prime;
}
/*
 * teste primeiro numero primo de uma array
 */
void testPrimariPrime(){
    std::cout<<"testPrimariPrime"<<std::endl;
    int number[10] = {22,224,4,55,6,7,8,9,10,11};
    int size = 10;
    for (int i = 0; i < size; ++i) {
        if (isPrime(number[i]) == 0){
            std::cout<<number[i]<< " = Primeiro elemento primo da lista ";
            break;
        }
    }
}

//9. Converter um número inteiro para o valor correspondente em algarismos romanos.
/**
 * valida numero entre 1 a 4999
 * @param number numero a ser verificado
 */
void validateNumberToRoman(int number){
    if (number < 1 || number > 4999){
        std::cout<<" Error! Numero invalido "<<number<<" <== Tem que pertencer ao intervalo 1 ate 4999. "<<std::endl;
        std::cout<<" OPs L(*_*)/"<<std::endl;
        abort();
    }
}
/**
 * arabico a romano
 * @param number numero arabico a ser transformado
 * @return numero em Romano
 */
std::string decimalToRoman(int number) {
    validateNumberToRoman(number);
    std::string numberRoman = "";
    std::string charRoman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int exceptionArabics[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    int length = sizeof(exceptionArabics) / sizeof(int);
    for (int i = 0; i < length; i++) {
        while (number >= exceptionArabics[i]) {
            numberRoman += charRoman[i];
            number -= exceptionArabics[i];
        }
    }
    return numberRoman;
}
/*
 * teste arabico a romano
 */
void testDecimalToRoman(){
    std::cout<<"testDecimalToRoman"<<std::endl;
    int number[] = {1,2,3,4,5,6,7,8,9,10,11,15,13,14,15,16,17,18,19,20,29,1000,1500,290,2000,3000,4000,500};
    for (int i = 0; i < sizeof(number)/ sizeof(int); ++i) {
        std::cout<<" Numero Aarabico = "<<number[i]<< " Numero Romano = " <<decimalToRoman(number[i])<<std::endl;
    }
//    for (int i = 1; i < 10; i++) {
//        int numero = i;
//        char *romanos[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
//        int arabicos[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
//        // acha a quantidade de elementos no array
//        int indice = (sizeof(arabicos) / sizeof(arabicos[0])) - 1;
//        while (numero > 0) {
//            if (numero >= arabicos[indice]) {
//                printf("%s", romanos[indice]);
//                numero -= arabicos[indice];
//            } else {
//                indice--;
//            }
//        }
//        printf("\n");
//    }
}
//10. Implemente o código abaixo para verificar se um determinado ano é bissexto ou não.
void validateLeap(int number){
    if (number < 1){
        std::cout<<"Error! nmero invalido... "<<number<<std::endl;
        std::cout<<"Digite valores positivos! "<<std::endl;
        abort();
    }
}
/**
 * ano e bisexto ou nao
 * @param year ano a ser verificado
 * @return se ano e ou nao bisexto
 */
std::string yearIsLeap(int year){
    validateLeap(year);
    std::string leap;
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                leap =  " is a leap year.";
            } else {
                leap = " is not a leap year.";
            }
        } else {
            leap = " is a leap year.";
        }
    } else {
        leap = " is not a leap year.";
    }
    return leap;
}
/*
 * testLeap testa yearIsLeap
 */
void testLeap(){
    std::cout<<"testLeap"<<std::endl;
    int year[] = {2000,3000,1992,2011,2009,1996,500};
    for (int i = 0; i < sizeof(year)/ sizeof(int ); i++) {
        std::cout<<i+1<<"* Ano pesquisado = "<<year[i]<<" >  "<<yearIsLeap(year[i])<<std::endl;
    }
}

void isPolindrome(){
    int n, num, digit, rev = 0;
    std::cout << "Enter a positive number: ";
    std::cin >> num;
    n = num;
    do {
        digit = num % 10;
        rev = (rev * 10) + digit;
        num = num / 10;
    } while (num != 0);
    std::cout << " The reverse of the number is: " << rev << std::endl;
    if (n == rev) {
        std::cout << " The number is a palindrome.";
    } else {
        std::cout << " The number is not a palindrome.";
    }
}


void welcome(){
    std::cout<<" ***************************"<<std::endl;
    std::cout<<" *        WELCOME          * "<<std::endl;
    std::cout<<" ***************************"<<std::endl;
    std::cout<<" * Lista 01 Modularizacao *"<<std::endl;
    std::cout<<" ***************************"<<std::endl;
}
/*
 * todos os testes
 */
void menu(){
    //welcome();                  // * Lista 01 modularização *
    //testEvenOrOdd();            // 01 = par ou impar.
    //testIsPrime();              // 02 = primo.
    //testDecimalToBinary();      // 03 = decimal a binario.
    //                            // 04 =
    //testFactorial();            // 05 = fatorial.
    //testCalculateSum();         // 06 = calcula somatorio.
    //testProductCalculate();     // 07 = calcula o produtorio.
    //testPrimariPrime();         // 08 = seleciona primeiro numero primo de um array *REVISAR*.
    //testDecimalToRoman();       // 09 = converte numero arabicos em romanos.
    //testLeap();                 // 10 = ano bisexto ou nao.
    //isPolindrome();             // 11 = numero e polindrome?.
}

int main() {
    menu();
    return 0;
}
