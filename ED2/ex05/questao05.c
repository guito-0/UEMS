#include <stdio.h>
#include <stdlib.h>

struct grafo{
    int eh_ponderado;
    int nro_vertices;
    int grau_max;
    int** arestas;
    float** pesos;
    int* grau;
};
typedef struct grafo Grafo;

Grafo *cria_Grafo(int nro_vertices, int grau_max, int eh_ponderado){
    Grafo *gr = (Grafo*) malloc(sizeof(struct grafo));
    int i;
    if(gr != NULL){
        gr->nro_vertices = nro_vertices;
        gr->grau_max = grau_max;
        gr->eh_ponderado = (eh_ponderado != 0) ?1:0;
        gr->grau = (int*) calloc(nro_vertices, sizeof(int));
        gr->arestas = (int**) malloc(nro_vertices*sizeof(int*));
        for(i = 0; i <nro_vertices; i++)
            gr->arestas[i] = (int*) malloc(grau_max*sizeof(int));
        if(gr->eh_ponderado){
            gr->pesos = (float**)malloc(nro_vertices*sizeof(float*));
            for(i=0; i<nro_vertices; i++)
                gr->pesos[i] = (float*) malloc(grau_max*sizeof(float));
        }
    }
    return gr;
}

void libera_Grafo(Grafo* gr){
    if(gr!= NULL){
        int i;
        for(i=0; i<gr->nro_vertices; i++)
            free(gr->arestas[i]);
        free(gr->arestas);
        if(gr->eh_ponderado){
            for(i=0; i<gr->nro_vertices; i++)
                free(gr->pesos[i]);
            free(gr->pesos);
        }
        free(gr->grau);
        free(gr);
    }
}

int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso){
    if(gr == NULL)
        return 0;
    if(orig < 0 || orig >= gr->nro_vertices)
        return 0;
    if(dest < 0 || dest >= gr->nro_vertices)
        return 0;
    gr->arestas[orig][gr->grau[orig]] = dest;
    if(gr->eh_ponderado)
        gr->pesos[orig][gr->grau[orig]] = peso;
    gr->grau[orig]++;
    if(eh_digrafo == 0)
        insereAresta(gr, dest, orig, 1, peso);
    return 1;
}

int removeAresta(Grafo* gr, int orig, int dest, int eh_digrafo){
    if(gr == NULL)
        return 0;
    if(orig < 0 || orig >= gr->nro_vertices)
        return 0;
    if(dest < 0 || dest >= gr->nro_vertices)
        return 0;
    int i = 0;
    while(i<gr->grau[orig] && gr->arestas[orig][i] != dest)
        i++;
    if(i == gr->grau[orig])
        return 0;
    gr->grau[orig]--;
    gr->arestas[orig][i] = gr->arestas[orig][gr->grau[orig]];
    if(gr->eh_ponderado)
        gr->pesos[orig][i]=gr->pesos[orig][gr->grau[orig]];
    if(eh_digrafo == 0)
        removeAresta(gr,dest,orig,1);
    return 1;
}

void busca_profundidade_iterativa(Grafo *gr, int ini, int *visitado, int *predecessor) {
    int i, cont = 1;

    for(i = 0; i < gr->nro_vertices; i++) {
        visitado[i] = 0;
        predecessor[i] = -1;
    }

    int tam_pilha = gr->nro_vertices * gr->grau_max;
    int pilha[tam_pilha];
    int topo = -1;

    pilha[++topo] = ini;

    while(topo >= 0) {
        int atual = pilha[topo--];

        if(visitado[atual] == 0) {
            visitado[atual] = cont++;

            for(i = gr->grau[atual] - 1; i >= 0; i--) {
                int vizinho = gr->arestas[atual][i];

                if(visitado[vizinho] == 0) {
                    pilha[++topo] = vizinho;
                    predecessor[vizinho] = atual;
                }
            }
        }
    }
}

int imprimeGrafo(Grafo *gr) {
    if(gr == NULL)
        return 0;

    for (int i = 0; i < gr->nro_vertices; i++) {
        printf("Vertice: %d", i);
        for(int j = 0; j < gr->grau[i]; j++)
            printf(" %d", gr->arestas[i][j]);
        printf("\n");
    }
    return 1;
}

int main(){
    Grafo *gr = cria_Grafo(5, 3, 0);
    insereAresta(gr, 0, 1, 0, 0);
    insereAresta(gr, 0, 2, 0, 0);
    insereAresta(gr, 1, 2, 0, 0);
    insereAresta(gr, 1, 3, 0, 0);
    insereAresta(gr, 2, 4, 0, 0);
    insereAresta(gr, 3, 4, 0, 0);

    imprimeGrafo(gr);

    int visitado[gr->nro_vertices];
    int predecessor[gr->nro_vertices];
    busca_profundidade_iterativa(gr, 1, visitado, predecessor);

    for(int i = 0; i < gr->nro_vertices; i++) {
        printf("Vertice: %d | ", i);
        printf("Visitado: %d | ", visitado[i]);
        printf("Predecessor: %d  | \n", predecessor[i]);
    }

    libera_Grafo(gr);

    return 0;
}