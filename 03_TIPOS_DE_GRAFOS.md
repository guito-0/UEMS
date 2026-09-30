# Tipos de Grafos

Abaixo estão os tipos de grafos apresentados pela professora, suas características de identificação e propriedades[cite: 3, 4].

## 1. Grafo Direcionado vs Não Direcionado
*   **Não Direcionado:** Ligações expressas em arestas. Se $a$ liga em $b$, $b$ liga em $a$. O par é não ordenado $\{v_1, v_2\}$[cite: 3].
*   **Direcionado (Dígrafo):** Ligações são arcos com sentido. O par é ordenado $(v_1, v_2)$[cite: 3].

## 2. Grafo Simples vs Multigrafo
*   **Grafo Simples:** Não direcionado, sem laços (arestas que conectam o vértice a ele mesmo) e sem múltiplas arestas entre os mesmos dois nós[cite: 3].
*   **Multigrafo:** Possui mais de uma aresta conectando os mesmos dois vértices, mas **não possui laços**[cite: 3].

## 3. Conectividade
*   **Grafo Conexo:** Existe um caminho entre qualquer par de nós[cite: 3].
*   **Grafo Desconexo:** Não existe caminho entre todos os pares. É formado por pelo menos dois subgrafos conexos disjuntos, chamados **Componentes Conexas**[cite: 3].
*   **Grafo Totalmente Desconexo (Nulo):** Todos os vértices têm grau zero[cite: 3].

## 4. Topologias Específicas
*   **Grafo Completo ($K_n$):** Grafo simples onde existe exatamente uma aresta entre cada par de vértices distintos[cite: 3].
*   **Grafo Regular:** Todos os vértices possuem o mesmo grau. (Nota: Todo $K_n$ é regular de grau $n-1$)[cite: 3].
*   **Grafo Bipartido:** Vértices podem ser divididos em 2 conjuntos disjuntos ($V_1$ e $V_2$) de forma que toda aresta liga um vértice de $V_1$ a um de $V_2$[cite: 3].
*   **Biclique ($K_{r,s}$):** Grafo bipartido completo. Todo vértice de $V_1$ está ligado a todo vértice de $V_2$. Possui $r+s$ vértices e $r \times s$ arestas[cite: 3].
*   **Grafo k-Partido:** Particiona os vértices em $k$ conjuntos independentes e disjuntos, com arestas apenas entre conjuntos distintos[cite: 3].
*   **Grafo Acíclico:** Não contém ciclos simples[cite: 3].

## 5. Grafos Ponderados
*   É uma tripla $G = (V, A, w)$ onde $w$ é uma função peso que atribui um valor real a cada aresta[cite: 3]. Usado em Dijkstra e Bellman-Ford (quando fornecidos).

## 6. Caminhos e Ciclos de Euler e Hamilton
*   **Euleriano:**
    *   *Caminho:* Passa por cada **aresta** exatamente uma vez (Semi-euleriano se possuir o caminho).
    *   *Ciclo:* Caminho euleriano que termina no vértice inicial (Grafo Euleriano).
    *   *Teorema de Euler (Suficiência):* Um grafo é euleriano se e somente se **todos** os vértices têm grau par. É semi-euleriano se existem **exatamente dois** vértices de grau ímpar[cite: 4].
*   **Hamiltoniano:**
    *   *Caminho:* Passa por cada **vértice** exatamente uma vez[cite: 3].
    *   *Ciclo:* Caminho hamiltoniano que retorna ao vértice inicial[cite: 3].

Relaciona-se com:
- [Fundamentos de Grafos](02_FUNDAMENTOS_DE_GRAFOS.md)