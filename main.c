#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Define o tamanho m�ximo da pilha

#define MAX_SIZE 100


// Define a estrutura da Pilha


typedef struct Pilha
{

 // Array de caracteres para armazenar os elementos da pilha

  char caractere[MAX_SIZE];

// Vari�vel que indica a posi��o do topo da pilha
  int topo;
} Pilha;


// Fun��o para inicializar a pilha

void inicializarPilha(Pilha *pilha)
{

 // Define o topo da pilha para -1
 // indicando que est� vazia

  pilha->topo = -1;
}


// Fun��o para verificar se a pilha est� vazia


int pilhaVazia(Pilha *pilha)
{

 // Retorna 1 se vazia, 0 se n�o estiver vazia

  return (pilha->topo == -1);
}



// Fun��o para verificar se a pilha est� cheia

int pilhaCheia(Pilha *pilha)
{

 // Retorna 1 se cheia, 0 se n�o estiver cheia

  return (pilha->topo == MAX_SIZE - 1);
}




// Fun��o para inserir um elemento na pilha

void push(Pilha *pilha, char caractere)
{

 // Verifica se a pilha est� cheia

  if (pilhaCheia(pilha))
  {
    printf("A pilha est� cheia\n");
  }
  else
  {

   // Insere o caractere no topo da pilha

    pilha->caractere[++pilha->topo] = caractere;
  }
}


// Fun��o para remover um elemento da pilha

char pop(Pilha *pilha)
{

 // Verifica se a pilha est� vazia
  if (pilhaVazia(pilha))
  {
    printf("A pilha est� vazia\n");

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

 //Declara��o de  uma vari�vel do tipo "Pilha"

  Pilha pilha;


  // Inicializa a pilha

  inicializarPilha(&pilha);

  printf("Digite uma sequencia de caracteres (# para backspace, @ para apagar tudo):\n");

   // Array para armazenar a entrada do usu�rio

  char caracterUsuario[MAX_SIZE];

  // Leitura da entrada do usu�rio (caractereUsuario)

  scanf("%s", caracterUsuario);

  // La�o para percorrer o caracterUsuario

  for (int i = 0; i < strlen(caracterUsuario); i++)
  {

    // Se o caractere for '#', remove o �ltimo elemento
    // da pilha (backspace)


    if (caracterUsuario[i] == '#')
    {
      pop(&pilha);
    }

     // Se o caractere for '@', apaga toda a pilha


    else if (caracterUsuario[i] == '@')
    {

     // La�o para remover todos os elementos da pilha


      while (!pilhaVazia(&pilha))        {
        pop(&pilha);
      }
    }

    // Se o caractere n�o for '#' ou '@',
    // insere o caractere na pilha


    else
    {
      push(&pilha, caracterUsuario[i]);
    }
  }

  // Exibe mensagem ao usu�rio

  printf("Texto final da pilha: ");


  // La�o para imprimir todos os elementos
  // da pilha

  while (!pilhaVazia(&pilha))
  {

   // Imprime o caractere removido da pilha

    printf("%c", pop(&pilha));
  }

  return 0;
}


