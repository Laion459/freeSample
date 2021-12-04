#include "testQuestionnaire.h"

int main() {
    allTest();
    return 0;
}

//• O programa deve gerenciar questionários

//• Um questionário deve ter um
//         código único,            - O código e calculado automaticamente
//         título,
//         nome da disciplina e
//         quantidade atual de perguntas.


//• Uma pergunta tem um estilo múltipla escolha, sendo formada por um
//         texto (descrição da pergunta), por uma
//         lista de 4 possíveis respostas e pela
//         indicação da resposta correta. Ela também deve possuir um
//         número único, o qual deve ser calculado pelo próprio programa.


//• Funcionalidades esperadas:
// Adicionar, excluir ou buscar um questionário.
//
// Quando um questionário é excluído, todas as suas perguntas também devem ser excluídas.

// Adicionar, excluir ou buscar uma pergunta específica em um questionário existente.
// Listar todas as perguntas de um questionário, dado o número do questionário.
//Dica
//• A solução deve utilizar (lista encadeada?) de objetos struct.