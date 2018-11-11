#include <stdio.h>


#include "Arvore-funcoes.c"

/* ********************************************************** */
/*  FUNCAO PRINCIPAL                                          */
/* ********************************************************** */
int main () {

  NO *arvore;
  int num=1;
  int n1, n2;
  int opcao = 0;

  inicializar(&arvore);
  
  while(opcao <= 11){

	    printf("****  ARVORE  ****\n"); 
	    printf(" 1 - INSERIR NOS\n");
	    printf(" 2 - PRE ORDEM\n");
	    printf(" 3 - POS ORDEM\n");
	    printf(" 4 - EM ORDEM\n");
	    printf(" 5 - NOS FOLHA\n");
	    printf(" 6 - NO RAIZ\n");
	    printf(" 7 - NO RAMOS\n");
	    printf(" 8 - PROFUNDIDADE, ALTURA, GRAU DA ARVORE\n");
	    printf(" 9 - ASCENDENTE E DESCENDENTE\n");
	    printf("10 - PROFUNDIDADE, ALTURA, GRAU E NIVEL DO NO\n");
	    printf("11 - REPRESENTACAO DE BARRAS\n");
	    printf("------------------------------------------------\n");
	    printf("Escolha uma opcao: \n");
	    printf("\n");
	    
	    scanf("%d", &opcao);
	    fflush(stdin);

	    switch(opcao){
	    	case 1:
	    		printf("Insira os no na arvore\n");
  				printf("DIGITE 0 PARA PARAR A INSERCAO DE NOS\n");
  
				while (num != 0) {
				  	scanf("%d", &num);
				  	if (num == 0) {
				  		break;
					}
				  	inserir(&arvore, num);
				}
				break;
	      	case 2:
		        printf("=================================\n");
  				printf("Pré Ordem: ");
				preOrdem(arvore);
				printf("\n=================================\n\n");
	      		break;
	      	case 3:
	      		printf("=================================\n");
				printf("Pos Ordem: ");
				posOrdem(arvore);
				printf("\n=================================\n\n");
	      		break;
	      	case 4:
		        printf("=================================\n");
				printf("Em Ordem: ");
				emOrdem(arvore);
				printf("\n=================================\n\n");
	      		break;
	      	case 5:
		        printf("=================================\n");
				printf("Nós folha: ");
				mostrarNosFolha(arvore);
				printf("\n=================================\n\n");
		      	break;
	      	case 6:
		        printf("=================================\n");
			    printf("Nó raíz da arvore: ");
			    mostrarNoRaiz(arvore);
			    printf("\n=================================\n\n");
	      		break;
	      	case 7:
	        	printf("=================================\n");
				printf("Nós ramo: ");
				mostrarNosRamos(arvore);
				printf("\n=================================\n\n");
	      		break;
	      	case 8:
	        	printf("=================================\n");
  				printf("Altura/profundidade da árvore: %d \n", altura(arvore));
  				printf("Grau da árvore: %d \n", grau(arvore));
  				printf("=================================\n\n");
	      		break;
	      	case 9:
	      		printf("=================================\n");
		  		printf("DIGITE UM NO PARA MOSTRAR ASCENDENTES E DESCENDENTES\n");
		  		scanf("%d", &n1);
		  		mostraAscDesc(arvore, n1);
		  		printf("\n=================================\n\n");	
		  		break;
			case 10:
				printf("=================================\n");
  				printf("DIGITE UM NO PARA MOSTRAR PROFUNDIDADE, ALTURA, NIVEL E GRAU\n");
  				scanf("%d", &n2);
  				alturaNoh(arvore, n2);
  				printf("=================================\n\n");
  				break;
	      	case 11:
	        	printf("=================================\n");
  				printf("Representação da árvore: \n");
  				exibeRep(arvore);
  				printf("\n=================================\n\n");
	      		break;
	      	default:
	      		printf("Opcao invalida!!!\n");
	      		break;
	    }
	    
	    printf("Pressione qualquer tecla para continuar...");
	    getch();
	    system("cls");
	}
  
  
/*inserir(&arvore, 50);
  inserir(&arvore, 40);
  inserir(&arvore, 30);
  inserir(&arvore, 60);
  inserir(&arvore, 45);
  inserir(&arvore, 14);
  inserir(&arvore, 65);
  inserir(&arvore, 78);
  inserir(&arvore, 55);
  inserir(&arvore, 52);
*/

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
