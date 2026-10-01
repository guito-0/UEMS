# Fundamentos de Grafos

## 1. O que é um Grafo?
É um modelo matemático $G = (V, A)$ que representa relações entre objetos, onde $V$ é o conjunto de vértices (não vazio) e $A$ é o conjunto de arestas[cite: 3].
*   **Vértices:** Entidades representadas (ex: pessoas, casas)[cite: 3].
*   **Arestas (ou Arcos):** Fazem a ligação entre dois vértices, indicando a relação entre eles[cite: 3].

## 2. Graus dos Vértices
*   **Grafo Não Direcionado:** O grau $g(v)$ ou $d(v)$ é o número de arestas incidentes ao vértice. *Atenção:* Cada laço conta como **duas** arestas[cite: 3].
    *   $\delta(G)$: Menor grau presente no grafo[cite: 3].
    *   $\Delta(G)$: Maior grau presente no grafo[cite: 3].
*   **Grafo Direcionado:**
    *   $g^-(v)$ (Grau de Entrada): Número de arestas que "entram" no vértice[cite: 3].
    *   $g^+(v)$ (Grau de Saída): Número de arestas que "saem" do vértice[cite: 3].
*   **Classificações Específicas:** Vértice trivial/isolado (grau 0), vértice pendente (grau 1)[cite: 3].

## 3. Movimentação no Grafo
*   **Passeio:** Sequência alternada de nós e arestas do nó $i$ ao $j$. Pode repetir nós e arestas[cite: 3].
*   **Caminho:** É um passeio que **não contém nós repetidos**[cite: 3]. O comprimento de um caminho é a quantidade de arestas[cite: 3].
*   **Circuito:** Um passeio fechado (nó de partida = nó de chegada)[cite: 3].
*   **Ciclo:** Um caminho fechado. Contém exatamente dois nós iguais: o primeiro e o último[cite: 3].

## 4. Isomorfismo
Dois grafos $G_1$ e $G_2$ são isomorfos ($G_1 \cong G_2$) se existe um mapeamento bijetivo (um-para-um) entre os vértices que preserve a adjacência[cite: 3].
*   **Condições necessárias (mas não suficientes):** Mesmo número de vértices, arestas, componentes, e vértices com mesmo grau[cite: 3].
*   **Complexidade do Teste:** O algoritmo intuitivo analisa permutações, tendo complexidade $O(n!)$[cite: 3].

Relaciona-se com:
- [Tipos de Grafos](03_TIPOS_DE_GRAFOS.md)


[Próximo](03_TIPOS_DE_GRAFOS.md)