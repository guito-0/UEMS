# 12_ARVORE_GERADORA_MINIMA_AGM.md

# Árvores e Árvores Geradoras Mínimas (AGM)

## 1. O que é uma Árvore
Uma árvore é um grafo **conexo** e **sem ciclos** em que há somente um caminho entre qualquer par de vértices[cite: 47]. 

**Propriedades de uma árvore com $n$ vértices:**
*   É conexa e sem ciclos[cite: 49].
*   Possui exatamente $n - 1$ arestas[cite: 49].
*   É um grafo planar (as arestas não se cruzam no desenho)[cite: 49].
*   Se $n > 1$, possui pelo menos dois vértices folhas (terminais)[cite: 49].

## 2. Florestas
Uma floresta é um conjunto de árvores sem vértices em comum. Uma floresta geradora é uma floresta que contém todos os vértices de um grafo[cite: 53].

## 3. O que é uma Árvore Geradora (Spanning Tree)
É um subgrafo conexo e acíclico que possui **todos os vértices originais** do grafo `G` e um subconjunto das arestas originais[cite: 50]. Todo grafo conexo possui pelo menos uma árvore geradora[cite: 50].

*Exceção Notável:* Um **grafo caminho** é um caso especial de árvore em que todos os vértices têm grau 2 ou 1, com apenas dois vértices com grau 1[cite: 48].

## 4. O que é a Árvore Geradora de Custo Mínimo (AGM/MST)?
A Árvore Geradora de Custo Mínimo (AGM) ou *Minimum Spanning Tree (MST)* é a árvore geradora de menor custo dentre todas as possíveis em um grafo ponderado[cite: 54]. (Da mesma forma, a de custo máximo seria a de maior custo). A determinação pode ser feita em tempo polinomial por algoritmos gulosos[cite: 54].

## 5. Algoritmos Clássicos
A complexidade dos algoritmos originais (de 1928) evoluiu de $O(m \log n)$ para $O(m)$ em 2008[cite: 56]. Os dois mais populares e gulosos surgiram na década de 50:
*   [Algoritmo de Prim](13_PRIM.md)[cite: 56].
*   [Algoritmo de Kruskal](14_KRUSKAL.md)[cite: 56].


[Próximo](13_PRIM.md)