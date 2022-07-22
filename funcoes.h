#include <stdio.h> //código feito por Diêgo de Barros
#include <stdlib.h>
#include <string.h>
//#include <ctype.h>

typedef struct{
char nome[21];
char descricao[201];
} nota;//tipo nota, anotação

//função para ler a anotação, coletar os dados, para criação:
nota criaNota(){
  nota n;
  printf("\nInsira o título da nova anotação:\t");
  //lendo título da nota
  
  scanf (" %21[^\n]", &n.nome);//scanf só para de ler a string quando encontra o \n
  
  printf("Insíra o conteúdo da anotação:\t");
  //lendo conteúdo da nota
  scanf (" %201[^\n]", &n.descricao);
  return n;
}


nota alteraNota(){//função para alterar uma anotação
  nota n;
  printf("\n\nInsira o título da nova anotação):\n\n");
  //lendo título da nota
  scanf (" %21[^\n]", &n.nome);
  
  printf("\nInsíra o conteúdo da anotação:");
  //lendo conteúdo da nota
  scanf (" %201[^\n]", &n.descricao);
  return n;
}

void mostraMenu(){
  printf("\n----------------------------\n");
  printf("\n       >MENU PRINCIPAL<\n\n");
  printf("\n[1] Criar nova anotação\n\n");
  printf("[2] Alterar anotação existente\n\n");
  printf("[3] Ler anotação existente\n\n");
  printf("[4] Deletar\n\n");
  printf("\n(A tela é atualizada automaticamente após alterações)");
  printf("\n----------------------------\n");
}

void mostraAnotacoes(nota notas[30], nota comparacao)
//essa função mostra o conteúdo dos vetores de struct que não estão vazios, com o valor padrão "NULL" que eu defini.
{
  int i=0, retorno=0, retorno2=0;
  for(i=0;i<30;i++)
  {
    retorno=strcmp(notas[i].nome, comparacao.nome);
    retorno2=strcmp(notas[i].descricao, comparacao.descricao);
    if(retorno!=0 || retorno2!=0)
    {
      printf("\n--------------------\n\n\n");
      printf("\n\t[ %d ]",i);
      printf("\n\tTÍTULO: %s",notas[i].nome);
      printf("\n\tDESCRIÇÃO: %s\n\n\n",notas[i].descricao);
    }
  }
}

void leAnotacao(nota notas[30], nota comparacao,int l)
{//função para ler/selecionar/pesquisar uma anotação existente
  int i=0, retorno=0, retorno2=0;
  for(i=0;i<30;i++)
  {
    retorno=strcmp(notas[i].nome, comparacao.nome);
    retorno2=strcmp(notas[i].descricao, comparacao.descricao);
    if(retorno!=0 || retorno2!=0 && l==i)
    {
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n -----> A anotação pesquisada foi:");
      printf("\n\t[ %d ]",i);
      printf("\n\tTÍTULO: %s",notas[i].nome);
      printf("\n\n\n\tDESCRIÇÃO: %s\n",notas[i].descricao);
      printf("\n\n\n\n\n\n\n\n\n\n\n");
    }
  }
} 