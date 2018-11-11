typedef struct _no {
  int dado;
  struct _no *pai;
  struct _no *esq;
  struct _no *dir;
} NO;

void inicializar (NO **tree);
int estaVazia (NO *tree);
NO* pesquisar (NO* tree, int valor);
NO* encontrarMenor(NO* tree);

void preOrdem (NO *tree);
void posOrdem (NO *tree);
void emOrdem (NO *tree);

void inserir (NO **tree, int valor);
void remover(NO **tree, int valor);

void mostrarNosFolha(NO *tree);
void mostrarNoRaiz(NO *tree);

void descEsq(NO* tree);
void descDir(NO* tree);

void mostraAscDesc(NO* tree, int valor);
void mostrarNosRamos(NO *tree);

int grau(NO* tree);
int maior(int a, int b);
int altura(NO *tree);

int calculaNivel(NO* tree);
void alturaNoh(NO *tree, int noh);
int calculaQtdBarras(int nivel, int dado);

void exibeRep (NO *tree);



