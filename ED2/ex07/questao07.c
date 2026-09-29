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

void dfs_marca_componente(Grafo *gr, int atual, int *componente, int comp){
    int i;
    componente[atual] = comp;
    for(i = 0; i < gr->grau[atual]; i++){
        int viz = gr->arestas[atual][i];
        if(componente[viz] == 0)
            dfs_marca_componente(gr, viz, componente, comp);
    }
}

int numero_componentes_conexas(Grafo *gr, int *componente){
    int i, num_comp = 0;
    for(i = 0; i < gr->nro_vertices; i++)
        componente[i] = 0;

    for(i = 0; i < gr->nro_vertices; i++){
        if(componente[i] == 0){
            num_comp++;
            dfs_marca_componente(gr, i, componente, num_comp);
        }
    }
    return num_comp;
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
    Grafo *gr = cria_Grafo(6, 3, 0);
    insereAresta(gr, 0, 1, 0, 0);
    insereAresta(gr, 0, 2, 0, 0);
    insereAresta(gr, 1, 2, 0, 0);
    insereAresta(gr, 1, 3, 0, 0);
    insereAresta(gr, 2, 4, 0, 0);
    insereAresta(gr, 3, 4, 0, 0);

    imprimeGrafo(gr);

    int componente[gr->nro_vertices];
    int num_comp = numero_componentes_conexas(gr, componente);

    for(int i = 0; i < gr->nro_vertices; i++)
        printf("Vertice: %d | Componente: %d\n", i, componente[i]);

    printf("Numero de componentes conexas: %d\n", num_comp);

    libera_Grafo(gr);

    return 0;
}