#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcoes.h"

//>>>>>>>>>>para entendimento, quando menciono a palavra "nota", me refiro a anotação. <<<<<<<<<<<<<<<<<<<<<<<<<<

/*typedef struct{
char nome[21];
char descricao[201];
} nota;//tipo nota, anotação*/

int main(void) {
  int l=0,f=0,marcador=0,i=0, is=0, retorno=0, retorno2=0,option=0,c=0;//variáveis contadoras, variáveis para retorno de funções, variável para o switch case e etc.
  
  nota notas[30];//vetor de struct do tipo 'nota' que armazena as anotações
  
  nota comparacao; //variável para efeitos de comparação
  
  //inicializando variável de comparação, com uma string padrão que eu defini
  strcpy(comparacao.nome, "NULL");
  strcpy(comparacao.descricao, "NULL");
    
  /*inicializando vetor com um valor que eu predefini, para fazer comparações, com o intuito de saber se é uma anotação existente ou não posteriomente*/
  for(i=0;i<30;i++)
  {
   strcpy(notas[i].nome, "NULL");
   strcpy(notas[i].descricao, "NULL");
  }
  
  printf("------------------------------\n");
  printf("Bem vindo ao app de anotações!\n");
  printf("------------------------------\n");
    
  while(marcador==0)//loop para repetição do print do menu de opções, repetição do switch case e etc
    {
      f=0;
      printf("\n>>>>Anotações existentes:       <<<<\n");
      
      mostraAnotacoes(notas, comparacao);//mostra anotações existentes
      mostraMenu(); 
      
      printf("\ninsira uma das opções (de 1 até 4):\n");
      scanf(" %i", &option);
      
      is=isalpha(option);//função/esquema para checar se o caractere digitado não seria uma letra
      while(is!=0)
      {
        printf("\ninsira uma das opções 1, 2, 3 ou 4:");
        scanf(" %i",&option);
      }
      
  switch(option)//switch case para as opções do menu
      {
      case 1://criar nova anotação
        
        for(i=0;i<30;i++)//Laço for checa quais posições do vetor já estão com anotações "gravadas" e pula essas, para garantir que apenas os vetores disponíveis sejam selecionados para a criação de nova anotaçao.
        {
          retorno=strcmp(notas[i].nome, comparacao.nome);
          retorno2=strcmp(notas[i].descricao, comparacao.descricao);
          
            if(retorno==0 && retorno2==0)
            {
              notas[i]=criaNota();  
              system("clear");//limpar a tela do console
             break;
            }
        }
      break;
      case 2://altera uma anotação---------------------------
        printf("\nDigite o número da anotação a ser alterada(por exemplo, 0):\t");
        
        scanf(" %d",&c);
        
        notas[c]=alteraNota();//essa função altera a anotação selecionada 
        system("clear");
     break;
        
      case 3://case 3, objetivo: ler anotação existente

        printf("\ndigite o número da anotação a ser lida:\t");
        scanf(" %d",&l);
        leAnotacao(notas, comparacao,l);
        printf("INSÍRA UM >NÚMERO< PARA VOLTAR AO MENU:\n\n\n\n\n\n\n\n");
        scanf(" %d",&f);
        system("clear");       
     break;
    
      case 4://case 4, "delete". No caso, sobrescreve o contéudo do vetor que armazena a string nome e conteúdo da anotação, substituindo o valor anterior pelo valor "NULL", para que as funções que checam quais posições de vetor estão disponíveis para nova gravação, integrem essa posição deletada como disponível novamente. E a anotação deletada, normalmente, para de aparecer na aba "Anotações existentes".
          i=0;
          printf("\n-->digite o número da anotação a ser deletada:\t");
          scanf(" %d", &i);
          strcpy(notas[i].nome, "NULL");
          strcpy(notas[i].descricao, "NULL");
          system("clear");//limpar a tela do console
        break;
        
    }
    }
    return 0;
}
