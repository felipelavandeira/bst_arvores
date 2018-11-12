#include <string.h>
#include <stdlib.h>
#include "arvore.h"
/* ********************************************************** */
/*  IMPLEMENTACAO DAS FUNCOES                                 */
/* ********************************************************** */

/* ********************************************************** */
/*                        Inicializar                         */
/* ********************************************************** */
void inicializar (NO **tree) {

  *tree = NULL;

} /* fim de inicializar */


/* ********************************************************** */
/*  verifica se a lista de alunos est� vazia                  */
/* ********************************************************** */
int estaVazia (NO *tree) {

  if (tree == NULL)
  return 1;

  return 0;

} /* fim de estaVazia */


/* ********************************************************** */
/*                pesquisa na arvore um valor                 */
/* ********************************************************** */
NO* pesquisar (NO* tree, int valor) {

  NO *aux = tree;

  while (aux != NULL) {

    if (valor == aux->dado)
    break;

    else if (valor < aux->dado)
    aux = aux->esq;

    else
    aux = aux->dir;

  } /* fim do while */

  return aux;

} /* fim de pesquisar */


/* ********************************************************** */
/*              Encontra o menor n� na arvore                 */
/* ********************************************************** */
NO* encontrarMenor(NO* tree) {
  NO *aux = tree;

  while (aux->esq != NULL) {
    aux = aux->esq;
  } /* fim do while */

  return aux;

} /* fim de encontrarMenor */


/* ********************************************************** */
/*                      Imprime em Pre Ordem                  */
/* ********************************************************** */
void preOrdem (NO *tree) {

  if (!estaVazia(tree)) {
    printf("%d ", tree->dado);
    preOrdem(tree->esq);
    preOrdem(tree->dir);
  }

} /* fim de preOrdem */


/* ********************************************************** */
/*                      Imprime em Pos Ordem                  */
/* ********************************************************** */
void posOrdem (NO *tree) {

  if (!estaVazia(tree)) {
    posOrdem(tree->esq);
    posOrdem(tree->dir);
    printf("%d ", tree->dado);
  }

} /* fim de posOrdem */


/* ********************************************************** */
/*                      Imprime em Ordem                      */
/* ********************************************************** */
void emOrdem (NO *tree) {

  if (!estaVazia(tree)) {
    emOrdem(tree->esq);
    printf("%d ", tree->dado);
    emOrdem(tree->dir);
  }

} /* fim de posOrdem */


/* ********************************************************** */
/*                      Insere n� na Arvore                   */
/* ********************************************************** */
void inserir (NO **tree, int valor) {

  NO *aux = *tree;
  NO *pai = *tree;

  //alocar novo noh na memoria
  NO *novo = (NO *) malloc(sizeof(NO));

  //preenche o novo noh
  novo->dado = valor;
  novo->pai = NULL;
  novo->esq = NULL;
  novo->dir = NULL;

  //se a arvore estiver vazia
  if (estaVazia(*tree)) {
    *tree = novo;
    return;
  }else{
    while (aux != NULL) {

	  pai = aux;

      if (valor == aux->dado){
        printf("O valor que você quer inserir já existe.\n");
        break;
      }else if(valor < aux->dado){
        aux = aux->esq;
      }else{
        aux = aux->dir;
      }
    } /* fim do while */

    novo->pai = pai;
    aux = novo;

    if (valor < pai->dado) {
      pai->esq = aux;
    }else{
      pai->dir = aux;
    }

  }
} /* fim do inserir */


/* ********************************************************** */
/*                      Remove n� da Arvore                   */
/* ********************************************************** */
void remover(NO **tree, int valor){

  NO *aux;
  NO *pai;
  NO *menor;
  int numero;

  //se a árvore está vazia
  if (estaVazia(*tree)){
      printf("Arvore vazia\n");
      return;
  }

  //pesquisa o valor a ser removido
  aux = pesquisar(*tree, valor);

  //verifica se o valor foi encontrado
  if (aux == NULL) {
      printf("%d não encontrado! \n", valor);
      return;
  }

  if (aux->esq == NULL && aux->dir == NULL){
    //remove o nó raiz
    if (aux->pai == NULL) {
      inicializar(tree);
      free(aux);
      return;
    }
    //remove um nó folha que não é raiz
    if (valor < aux->pai->dado) {
      aux->pai->esq = NULL;
      free(aux);
      return;
    }else{
      aux->pai->dir = NULL;
      free(aux);
      return;
    }
  }else if((aux->esq != NULL && aux->dir == NULL) || (aux->esq == NULL && aux->dir != NULL) ){
    pai = aux->pai;
    if (valor > pai->dado) {
      pai->dir = aux->dir;
    }else if(valor < pai->dado){
      pai->esq = aux->esq;
    }
    free(aux);
    return;
  }else if(aux->esq != NULL && aux->dir != NULL){
    menor = encontrarMenor(aux->dir);
    numero = menor->dado;
    remover(&aux, numero);
    aux->dado = numero;
    //removerNoFilhosMultiplos(*aux);
  }

} /* fim do remover */


/* ********************************************************** */
/*                  Mostra o n�s das folhas                   */
/* ********************************************************** */
void mostrarNosFolha(NO *tree){

  if(tree == NULL)
    return;

  if(tree->esq == NULL && tree->dir == NULL)
    printf("%i ", tree->dado);

  if(tree->esq != NULL)
    mostrarNosFolha(tree->esq);

  if(tree->dir != NULL)
    mostrarNosFolha(tree->dir);

} /* fim mostrarNosFolha */



/* ********************************************************** */
/*                       Mostra o n� Raiz                     */
/* ********************************************************** */
void mostrarNoRaiz(NO *tree){

  if(!estaVazia(tree))
    printf("%i ", tree->dado);
  else
    printf("A árvore não tem nó raíz");

} /* fim mostrarNoRaiz */



/* ********************************************************** */
/*                  Descendente Esquerdo                      */
/* ********************************************************** */
void descEsq(NO* tree) {

  NO *aux = tree;

  while (aux->esq != NULL) {
    aux = aux->esq;
    printf("%d ", aux->dado);
  }   /* fim do while */

} /* fim de descEsq */


/* ********************************************************** */
/*                    Descendente Direito                     */
/* ********************************************************** */
void descDir(NO* tree) {

  NO *aux = tree;

  while (aux->dir != NULL) {
    aux = aux->dir;
    printf("%d ", aux->dado);
  } /* fim do while */

} /* fim de descDir */


/* ********************************************************** */
/*             Mostra o Ascendente e Descendente              */
/* ********************************************************** */
void mostraAscDesc(NO* tree, int valor) {

  NO *aux = tree;

  printf("Ancestrais de %d:\n", valor);

  while (aux != NULL) {
    if (valor == aux->dado)
    break;
    else if (valor < aux->dado){
      printf("%d ", aux->dado);
      aux = aux->esq;
    }else{
      printf("%d ", aux->dado);
      aux = aux->dir;
    }

  } /* fim do while */
  printf("\n");

  printf("Descendentes de %d:\n", valor);

  if (aux->esq == NULL && aux->dir == NULL) {
    printf("O nó não tem descendentes, é um nó folha");
    return;
  }

  if (aux->esq != NULL) {
    descEsq(aux);
  }

  if (aux->dir != NULL) {
    descDir(aux);
  }

} /* fim de pesquisar */


/* ********************************************************** */
/*                    Mostrar Ramos do n�                     */
/* ********************************************************** */
void mostrarNosRamos(NO *tree){

	if (!estaVazia(tree)) {
    	mostrarNosRamos(tree->esq);
    	if((((tree->dir!=NULL)&&(tree->esq!=NULL)) || ((tree->dir!=NULL) || (tree->esq!=NULL)))&&(tree->pai!=NULL))printf("%d ", tree->dado);
    	mostrarNosRamos(tree->dir);
    }

} /* fim MostraNosRamos */

/* ********************************************************** */
/*                         Mostrar Grau                       */
/* ********************************************************** */
int grau(NO* tree){

	if((tree->dir==NULL&&tree->esq==NULL)&& tree->pai == NULL)return 0;

	if(tree->dir!=NULL&&tree->esq!=NULL)return 2;

	if(!estaVazia(tree)){
		if(tree->dir==NULL && tree->esq!= NULL) grau(tree->esq);
		if(tree->dir!=NULL && tree->esq== NULL) grau(tree->dir);
		return 1;
	}

} /* fim grau */


/* ********************************************************** */
/*              Auxiliar para Calcular Altura                 */
/* ********************************************************** */
int maior(int a, int b){

    if(a > b)
        return a;
    else
        return b;

} /* fim maior */


/* ********************************************************** */
/*                  Mostrar Altura da Arvore                  */
/* ********************************************************** */
int altura(NO *tree){

   if((tree == NULL) || (tree->esq == NULL && tree->dir == NULL))
       return 0;
   else
       return 1 + maior(altura(tree->esq), altura(tree->dir));

} /* fim altura */


/* ********************************************************** */
/*                    Calcula Nivel                           */
/* ********************************************************** */
int calculaNivel(NO* tree){

	NO *aux=tree;
	int lvl = 0;

	while(!estaVazia(aux)){
		lvl++;
		aux=aux->pai;
	}

	return lvl;

} /* fim calculaNivel */


/* ********************************************************** */
/*      Mostra Profundidade, Altura, Nivel e Grau do n�       */
/* ********************************************************** */
void alturaNoh(NO *tree, int noh){

	NO *aux = pesquisar(tree, noh);
	int lvl = calculaNivel(aux);
	int prof =  lvl-1;
	int alt = altura(aux);
	int gr = grau(aux);

	printf("Noh %d: \n Nivel: %d\n Profundidade: %d\n Altura: %d\n Grau: %d\n", noh,  lvl, prof, alt, gr);

} /* fim alturaNoh */


/* ********************************************************** */
/*             Auxilia a Representa��o da Arbore              */
/* ********************************************************** */
int calculaQtdBarras(int nivel, int dado){

  int espaco = 10, caracteres = sizeof(dado);
  return espaco-(nivel-caracteres);

} /* calculaQtdBarras */


/* ********************************************************** */
/*                  Representa��o por Barras                  */
/* ********************************************************** */
void exibeRep (NO *tree) {

  int nivelNo, qtdBarras, i;

  if (!estaVazia(tree)) {

    nivelNo = calculaNivel(tree);
    qtdBarras = calculaQtdBarras(nivelNo, tree->dado);

    for(i = 0; i < nivelNo; i++)
      printf(" ");
    printf("%d ", tree->dado);
    for(i = 0; i < qtdBarras; i++)
      printf("-");
    printf("\n");

    exibeRep(tree->esq);
    exibeRep(tree->dir);
  }

} /* fim exibeRep */
