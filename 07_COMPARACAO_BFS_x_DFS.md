## 07_COMPARACAO_BFS_x_DFS

## Estrutura de Grafo (Lista de Adjacências)

A professora utilizou ponteiros duplos para armazenar as arestas, o que se assemelha a uma matriz de listas dinâmica[cite: 4].

```c
struct grafo{
    int eh_ponderado;
    int nro_vertices;
    int grau_max;
    int** arestas;
    float** pesos;
    int* grau;
};
typedef struct grafo Grafo;
```

*   **`arestas`**: Ponteiro duplo que atua como vetor de vetores (armazenando o vizinho de destino)[cite: 4].
*   **`grau`**: Vetor indicando quantos vizinhos um determinado vértice já tem armazenado[cite: 4].

## Lógica da Busca em Largura (BFS) em C

A implementação não usa fila circular encadeada, usa um vetor `fila` administrado pelos inteiros `IF` (Início da Fila) e `FF` (Final da Fila) com aritmética modular (`% gr->nro_vertices`)[cite: 5].

```c
// Lógica base da implementação
while (IF != FF){
    vert = fila[IF];
    IF = (IF + 1) % gr->nro_vertices;
    cont++;
    for(i = 0; i < gr->grau[vert]; i++){
        if (visitado[gr->arestas[vert][i]] == 0) {
            predecessor[gr->arestas[vert][i]] = vert;
            visitado[gr->arestas[vert][i]] = cont;
            fila[FF] = gr->arestas[vert][i];
            FF = (FF + 1) % gr->nro_vertices;
        }
    }
}
```

## Lógica da Busca em Profundidade (DFS) em C

Utiliza a pilha de chamadas (recursão). A variável `cont` age de forma similar ao tempo no pseudocódigo de teste de mesa, mapeando a ordem das visitas[cite: 6].

```c
void dfs_visita(Grafo *gr, int ini, int *visitado, int cont, int *predecessor){
    int i;
    visitado[ini] = cont;
    for(i = 0; i < gr->grau[ini]; i++){
        if (visitado[gr->arestas[ini][i]] == 0) {
            predecessor[gr->arestas[ini][i]] = ini;
            dfs_visita(gr, gr->arestas[ini][i], visitado, cont+1, predecessor);
        }
    }
}
```