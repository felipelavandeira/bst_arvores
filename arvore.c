#include <stdio.h>
#include <stdlib.h>

/* ------------------------------------------------ */
typedef struct _no {
  int dado;
  struct _no *pai;
  struct _no *esq;
  struct _no *dir;
} NO;


/* ------------------------------------------------ */
void inicializar (NO **tree) {

  *tree = NULL;

} /* fim de inicializar */


/* ------------------------------------------------ */
int estaVazia (NO *tree) {

  if (tree == NULL)
  return 1;

  return 0;

} /* fim de estaVazia */


/* ------------------------------------------------ */
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


NO* encontrarMenor(NO* tree) {
  NO *aux = tree;
  while (aux->esq != NULL) {
    aux = aux->esq;
  } /* fim do while */
  return aux;
} /* fim de encontrarMenor */


/* ------------------------------------------------ */
void preOrdem (NO *tree) {

  if (!estaVazia(tree)) {
    printf("%d ", tree->dado);
    preOrdem(tree->esq);
    preOrdem(tree->dir);
  }

} /* fim de preOrdem */

void posOrdem (NO *tree) {

  if (!estaVazia(tree)) {
    posOrdem(tree->esq);
    posOrdem(tree->dir);
    printf("%d ", tree->dado);
  }

} /* fim de posOrdem */

void emOrdem (NO *tree) {

  if (!estaVazia(tree)) {
    emOrdem(tree->esq);
    printf("%d ", tree->dado);
    emOrdem(tree->dir);
  }

} /* fim de posOrdem */

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
}

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
}
/* ------------------------------------------------ */

//Mostrar nós folha
void mostrarNosFolha(NO *tree){
  if(tree == NULL)
    return;

  if(tree->esq == NULL && tree->dir == NULL)
    printf("%i ", tree->dado);

  if(tree->esq != NULL)
    mostrarNosFolha(tree->esq);

  if(tree->dir != NULL)
    mostrarNosFolha(tree->dir);
}

/* ------------------------------------------------ */

//Mostrar nós raíz
void mostrarNoRaiz(NO *tree){
  if(!estaVazia(tree))
    printf("%i ", tree->dado);
  else
    printf("A árvore não tem nó raíz");
}

/* ------------------------------------------------ */

//Mostrar ancestrais e descendentes de um nó
void mostrarLigados(NO* tree, int valor) {

  NO *aux = tree;

  while (aux != NULL) {
    if (valor == aux->dado)
    break;
    else if (valor < aux->dado)
      aux = aux->esq;
    else
      aux = aux->dir;
  } /* fim do while */

  printf("Ancestral e descendentes do nó: %d\n", aux->dado);

  if (aux->pai == NULL)
    printf("O nó é raíz!\n");
  else
    printf("Nó pai: %d\n", aux->pai->dado);

  if (aux->esq != NULL)
    printf("Nó filho à esquerda: %d\n", aux->esq->dado);
  else
    printf("O nó não tem filho à esquerda\n");

  if(aux->dir != NULL)
    printf("Nó filho à direita: %d\n", aux->dir->dado);
  else
    printf("O nó não tem filho à direita\n");
} /* fim de pesquisar */

/* ------------------------------------------------ */

int main () {

  NO *arvore;

  inicializar(&arvore);

  inserir(&arvore, 50);
  inserir(&arvore, 40);
  inserir(&arvore, 30);
  inserir(&arvore, 60);
  inserir(&arvore, 45);
  inserir(&arvore, 14);
  inserir(&arvore, 65);
  inserir(&arvore, 78);
  inserir(&arvore, 55);
  inserir(&arvore, 52);

  printf("Pré Ordem: ");
  preOrdem(arvore);
  printf("\n");
  printf("Pos Ordem: ");
  posOrdem(arvore);
  printf("\n");
  printf("Em Ordem: ");
  emOrdem(arvore);
  printf("\n");

  printf("Nós folha: ");
  mostrarNosFolha(arvore);
  printf("\n");

  printf("Nó raíz da arvore: ");
  mostrarNoRaiz(arvore);
  printf("\n");

  pesquisar(arvore, 60);

  mostrarLigados(arvore, 40);

  /*remover(&arvore, 78);
  emOrdem(arvore);
  printf("\n");

  remover(&arvore, 30);
  emOrdem(arvore);
  printf("\n");

  remover(&arvore, 40);
  emOrdem(arvore);
  printf("\n"); */


} /* fim do main */
