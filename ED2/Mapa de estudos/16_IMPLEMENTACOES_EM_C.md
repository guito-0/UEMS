# 16_IMPLEMENTACOES_EM_C.md

# Implementações em C (Avançadas)

Os algoritmos gulosos e de programação dinâmica ganham estrutura própria em `C`. Note a manipulação direta de ponteiros e matrizes dinâmicas via `malloc` com a biblioteca `<float.h>` (para constante `FLT_MAX`).

## Dijkstra (Busca com Fila de Prioridade em C)
O Dijkstra implementado delega a checagem do menor custo para a função auxiliar `procuraMenorDistancia`.

```c
int procuraMenorDistancia(float *dist, int *visitado, int nv){
    int i, menor = -1, primeiro = 1;
    for(int i=0; i < nv; i++){
        if (dist[i] >= 0 && visitado[i] == 0){
            if(primeiro){
                menor = i;
                primeiro = 0;
            } else {
                if (dist[menor] > dist[i])
                    menor = i;
            }
        }
    }
    return menor;
}
```


A implementação base carrega um `while (cont > 0)` onde os vizinhos não-resolvidos são relaxados `dist[ind] > dist[u] + gr->pesos[u][i]`.   

## Bellman-Ford
Encontra arestas negativas usando loop contínuo sem `procuraMenorDistancia` estruturado, relaxando repetidamente:

```c
while (cont < nv){
    for (int u=0; u < nv; u++) {
        for(int j=0; j<gr->grau[u]; j++) {
            v = gr->arestas[u][j];
            if (dist[u] < FLT_MAX && dist[v] > dist[u] + gr->pesos[u][j]){
                dist[v] = dist[u] + gr->pesos[u][j];
                predecessor[v] = u;
            }
        }
    }
    cont++;
}
```

## Floyd-Warshall
Caracterizado pelo loop triplo iterando `k`, `i`, e `j` sobre a matriz de custos global pré-preenchida.   

```c
for (int k=0; k < nv; k++) {
    for (int i=0; i < nv; i++) {
        for (int j=0; j < nv; j++) {
            if (dist[i][k] == FLT_MAX || dist[k][j] == FLT_MAX)
                continue;
            if (dist[i][j] > dist[i][k] + dist[k][j]) {
                dist[i][j] = dist[i][k] + dist[k][j];
                predecessor[i][j] = predecessor[k][j];
            }
        }
    }
}
```

## Algoritmo de Prim

```c
while (1) {
    primeiro = 1;
    for(i=0; i<n; i++){
        if (predecessor[i] != -1){
            for (j=0; j<gr->grau[i]; j++) {
                // ...procurar o menor peso e registrar 'dest' e 'orig'[cite: 69]
                if (predecessor[gr->arestas[i][j]] == -1) {
                     // Verifica pesos 
                }
            }
        }
    }
    //... atualiza o predecessor
}
```

## Algoritmo de Kruskal
Usa array de rastreio de florestas `arv` e une iterativamente.   

```c
if (arv[i] != arv[gr->arestas[i][j]]){
    if(primeiro){
        menorPeso = gr->pesos[i][j];
        dest = gr->arestas[i][j];
        primeiro = 0;
    } else {
        if (menorPeso > gr->pesos[i][j]){
            menorPeso = gr->pesos[i][j];
            orig = i;
            dest = gr->arestas[i][j];
        }
    }
}
```