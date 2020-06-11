#include <stdio.h>
#include <stdlib.h>

typedef struct cartas 	{	
	char carta;
	struct cartas *prox;
} Cartas;

typedef struct pilhaDecresente 	{ 	
	Cartas *topo, *final;
	int qtd;
} PilhaDecresente;


int main() {
	int vDescart[55], qtd2, c=0, k=0;
	PilhaDecresente	pilhaD;
	Cartas *aux;

	while (scanf("%d", &qtd2) && qtd2 != 0) {
		for(c=0; c < 55; c++) {
			vDescart[c] = 0;	
		}

		k = 0;

		pilhaD.topo = NULL;
		pilhaD.qtd = 0;

		for(c=qtd2; c > 0; c--) {
			aux = (Cartas *) malloc(sizeof(Cartas));

			if(aux == NULL) {
				break;
      }

			aux->carta = c;
			aux->prox = pilhaD.topo;

			pilhaD.topo = aux;
			pilhaD.qtd++;

			if(c == qtd2) {
				pilhaD.final = aux;
      }
		}

		while (pilhaD.qtd >= 2) {
			aux = pilhaD.topo;
			pilhaD.topo = aux->prox;
			vDescart[k] = aux->carta;
			free(aux);
			pilhaD.qtd--;
			k++;
			aux = pilhaD.topo->prox;
			pilhaD.final->prox = pilhaD.topo;
			pilhaD.final = pilhaD.topo;
			pilhaD.topo = aux;
		}

		printf("Discarded cards:");
		for(c=0; c < k; c++) {
			printf(" %d", vDescart[c]);
			if(c != k-1) {
				printf(",");
			}
		}
		printf("\nRemaining card: %d\n", pilhaD.final->carta);
	}

	return 0;
}
