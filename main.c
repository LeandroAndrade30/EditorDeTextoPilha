#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Define o tamanho máximo da pilha

#define MAX_SIZE 100


// Define a estrutura da Pilha


typedef struct Pilha
{

 // Array de caracteres para armazenar os elementos da pilha

  char caractere[MAX_SIZE];

// Variável que indica a posição do topo da pilha
  int topo;
} Pilha;


// Função para inicializar a pilha

void inicializarPilha(Pilha *pilha)
{

 // Define o topo da pilha para -1
 // indicando que está vazia

  pilha->topo = -1;
}


// Função para verificar se a pilha está vazia


int pilhaVazia(Pilha *pilha)
{

 // Retorna 1 se vazia, 0 se não estiver vazia

  return (pilha->topo == -1);
}



// Função para verificar se a pilha está cheia

int pilhaCheia(Pilha *pilha)
{

 // Retorna 1 se cheia, 0 se não estiver cheia

  return (pilha->topo == MAX_SIZE - 1);
}




// Função para inserir um elemento na pilha

void push(Pilha *pilha, char caractere)
{

 // Verifica se a pilha está cheia

  if (pilhaCheia(pilha))
  {
    printf("A pilha está cheia\n");
  }
  else
  {

   // Insere o caractere no topo da pilha

    pilha->caractere[++pilha->topo] = caractere;
  }
}


// Função para remover um elemento da pilha

char pop(Pilha *pilha)
{

 // Verifica se a pilha está vazia
  if (pilhaVazia(pilha))
  {
    printf("A pilha está vazia\n");

    // Retorna caractere nulo se vazia
    return '\0';
  }
  else
  {

   //Remove o caractere do topo da pilha e retorna ao topo


    return pilha->caractere[pilha->topo--];    }
}

int main()
{

 //Declaração de  uma variável do tipo "Pilha"

  Pilha pilha;


  // Inicializa a pilha

  inicializarPilha(&pilha);

  printf("Digite uma sequencia de caracteres (# para backspace, @ para apagar tudo):\n");

   // Array para armazenar a entrada do usuário

  char caracterUsuario[MAX_SIZE];

  // Leitura da entrada do usuário (caractereUsuario)

  scanf("%s", caracterUsuario);

  // Laço para percorrer o caracterUsuario

  for (int i = 0; i < strlen(caracterUsuario); i++)
  {

    // Se o caractere for '#', remove o último elemento
    // da pilha (backspace)


    if (caracterUsuario[i] == '#')
    {
      pop(&pilha);
    }

     // Se o caractere for '@', apaga toda a pilha


    else if (caracterUsuario[i] == '@')
    {

     // Laço para remover todos os elementos da pilha


      while (!pilhaVazia(&pilha))        {
        pop(&pilha);
      }
    }

    // Se o caractere não for '#' ou '@',
    // insere o caractere na pilha


    else
    {
      push(&pilha, caracterUsuario[i]);
    }
  }

  // Exibe mensagem ao usuário

  printf("Texto final da pilha: ");


  // Laço para imprimir todos os elementos
  // da pilha

  while (!pilhaVazia(&pilha))
  {

   // Imprime o caractere removido da pilha

    printf("%c", pop(&pilha));
  }

  return 0;
}


