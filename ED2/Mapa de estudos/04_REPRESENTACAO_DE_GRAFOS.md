# 04_REPRESENTACAO_DE_GRAFOS.md

# Representação de Grafos

A professora ensina duas formas principais de representar grafos computacionalmente[cite: 4].

## 1. Lista de Adjacência
*   **O que é:** Um vetor de listas. Para cada vértice $u$, existe uma lista com todos os vértices vizinhos $v$[cite: 4].
*   **Para que serve:** Ideal para **grafos esparsos** (poucas arestas)[cite: 4].
*   **Complexidade de Espaço:** $O(\vert{}V\vert{} + \vert{}A\vert{})$. Muito compacta[cite: 4].
*   **Vantagem:** Muito rápida para percorrer todo o grafo: $O(\vert{}V\vert{} + \vert{}A\vert{})$[cite: 4]. Rápida para saber o grau de um vértice[cite: 4].
*   **Desvantagem:** Lenta para determinar se existe aresta entre $u$ e $v$ ($O(\vert{}V\vert{})$ no pior caso)[cite: 4].

## 2. Matriz de Adjacência
*   **O que é:** Uma matriz $n \times n$ onde as linhas e colunas representam os vértices[cite: 4]. Se há aresta de $i$ para $j$, $B[i,j] = 1$ (ou o peso, se for ponderado). Caso contrário, $0$[cite: 4].
*   **Para que serve:** Ideal para **grafos densos** (quantidade de arestas próxima a $\vert{}V\vert{}^2$)[cite: 4].
*   **Complexidade de Espaço:** $\Omega(\vert{}V\vert{}^2)$. Desperdiça muita memória com zeros se o grafo for esparso[cite: 4].
*   **Vantagem:** Muito rápida, $O(1)$, para verificar se existe uma aresta entre $i$ e $j$[cite: 4].
*   **Desvantagem:** Lenta para percorrer o grafo todo: $O(\vert{}V\vert{}^2)$[cite: 4].

Relaciona-se com:
- [Implementações em C](18_IMPLEMENTACOES_EM_C.md)


[Próximo] (05_BUSCA_EM_LARGURA_BFS.md)
