# 06_BUSCA_EM_PROFUNDIDADE_DFS.md

# Busca em Profundidade (DFS - Depth-First Search)

## 1. O que é
É um algoritmo de travessia que explora o grafo indo "o mais fundo possível" em um caminho antes de voltar (backtracking) para explorar os ramos alternativos. A DFS visita **todos** os vértices do grafo, mesmo aqueles em componentes desconexas, ao contrário da BFS.

## 2. Para que serve
*   Encontrar componentes conectados e componentes fortemente conectados.
*   Ordenação topológica de um grafo.
*   Resolver quebra-cabeças (como labirintos).

## 3. Em qual tipo de grafo é utilizado
Grafos direcionados e não direcionados.

## 4. Ideia intuitiva
A DFS avança por uma aresta e imediatamente chama a si mesma recursivamente para o próximo vértice. Ela só volta para o vértice anterior quando chega a um "beco sem saída" (um vértice sem vizinhos brancos).

## 5. Analogia
Imagine entrar em um labirinto e continuar andando até bater em uma parede sem saída (fundo). Só então você recua (volta um passo) para pegar o último corredor que você ignorou.

## 6. Conceitos necessários antes de estudar
*   Pilhas (LIFO) e Pilha de Chamadas Recursivas[cite: 2, 6].
*   Grafos direcionados e não direcionados.

## 7. Variáveis utilizadas pela professora
*   `cor[u]`: Estado do vértice.
    *   **Branco:** Não descoberto (antes de `d`).
    *   **Cinza:** Descoberto, mas seus vizinhos ainda estão sendo examinados (entre `d` e `f`).
    *   **Preto:** Vértice e toda a sua subárvore descendente já foram processados (após `f`).
*   `d[u]`: Instante de **descoberta** do vértice[cite: 6].
*   `f[u]`: Instante de **finalização** do vértice (quando ele vira preto)[cite: 6].
*   `\pi[u]`: Predecessor (pai) de $u$ na árvore da busca[cite: 6].
*   `tempo`: Variável global que é incrementada a cada evento (descoberta ou finalização)[cite: 6].

## 8. Pseudocódigo original da professora

```text
DFS(V, A)
1.  para cada vértice u em V
2.      cor[u] ← BRANCO
3.      π[u] ← NULO
4.  tempo ← 0
5.  para cada vértice u em V
6.      se cor[u] = BRANCO
7.          então DFS-Visita(u)

DFS-Visita(u)
1.  cor[u] ← CINZA
2.  tempo ← tempo + 1
3.  d[u] ← tempo
4.  para cada vértice v adjacente a u
5.      se cor[v] = BRANCO
6.          então π[v] ← u
7.                DFS-Visita(v)
8.  cor[u] ← PRETO
9.  tempo ← tempo + 1
10. f[u] ← tempo
```

## 9. Pseudocódigo traduzido para linguagem simples

*   **A função DFS:** Simplesmente zera os relógios (`tempo = 0`), pinta todo mundo de branco, e depois varre a lista de vértices. Se achar um branco, inicia a busca profunda a partir dele chamando `DFS-Visita(u)`. Isso garante que todo o grafo será varrido, criando uma floresta caso haja desconexão.
*   **A função DFS-Visita:**
    *   Pinta de Cinza (descobriu).
    *   Sobe o relógio e anota a hora de descoberta `d[u]`.
    *   Olha os vizinhos: Se o vizinho for Branco, eu me declaro pai dele e já chamo a função `DFS-Visita` para ele imediatamente (recursão).
    *   Depois que todos os vizinhos encerrarem e a recursão voltar, pinto de Preto.
    *   Sobe o relógio novamente e anoto a hora de fim `f[u]`.

## 10. Como executar manualmente

1.  Comece no nó raiz indicado (ou iterando pela lista).
2.  Pinte de cinza, aumente o tempo `d`.
3.  Escolha o primeiro vizinho Branco e vá para ele imediatamente.
4.  Repita até o nó não ter mais vizinhos brancos.
5.  Se não tiver mais vizinhos brancos, pinte de preto, aumente o tempo `f` e retorne para o nó pai para checar se ele tem outros vizinhos brancos.

## 11. Teste de mesa — método da professora

A professora utiliza uma notação visual `d|f` acima dos nós no grafo, além de preencher a tabela conforme o tempo avança[cite: 6].

**Exemplo dos Slides (Vértice Inicial = A):**

| Vértice | A | B | C | D | E | F | G | H | I |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **cor** | P | P | P | P | P | P | P | P | P |
| **d** | 1 | 2 | 4 | 3 | 6 | 8 | 9 | 10 | 11 |
| **f** | 18 | 17 | 5 | 16 | 7 | 15 | 14 | 13 | 12 |
| **$\pi$** | NULO | A | D | B | D | D | F | G | H |

**Passo a passo lógico (simplificado baseado nos slides)[cite: 6]:**
1.  O tempo inicia 0.
2.  Em A: vira Cinza. Tempo=1. `d[A]=1`. Vai para o vizinho B.
3.  Em B: vira Cinza. Tempo=2. `d[B]=2`. Vai para o vizinho D.
4.  Em D: vira Cinza. Tempo=3. `d[D]=3`. Vai para o vizinho C.
5.  Em C: vira Cinza. Tempo=4. `d[C]=4`. Não tem vizinhos brancos (beco sem saída). C vira Preto. Tempo=5. `f[C]=5`. Retorna para D.
6.  De volta a D: tem outro vizinho branco, E. Vai para E.
7.  Em E: vira Cinza. Tempo=6. `d[E]=6`. B é vizinho de E, mas já é cinza. Vira Preto. Tempo=7. `f[E]=7`. Retorna para D.
8.  De volta a D: tem vizinho F. Vai para F.
9.  Em F: vira Cinza. Tempo=8. `d[F]=8`. Vai para G.
10. Em G: vira Cinza. Tempo=9. `d[G]=9`. Vai para H.
11. Em H: vira Cinza. Tempo=10. `d[H]=10`. Vai para I.
12. Em I: vira Cinza. Tempo=11. `d[I]=11`. O vizinho F já é cinza. Vira Preto. Tempo=12. `f[I]=12`. Volta pra H.
13. H vira Preto, `f[H]=13`. Volta pra G.
14. G vira Preto, `f[G]=14`. Volta pra F.
15. F vira Preto, `f[F]=15`. Volta pra D.
16. D vira Preto, `f[D]=16`. Volta pra B.
17. B vira Preto, `f[B]=17`. Volta pra A.
18. A vira Preto, `f[A]=18`.

**Ordem de visitação (descoberta):** `{A, B, D, C, E, F, G, H, I}`[cite: 6].

## 12. Comparação

A DFS usa recursão (pilha), e visita todos os vértices do grafo. BFS usa fila e visita apenas os alcançáveis pela raiz[cite: 6].

## 13. Checklist para prova

- [ ] Sei acompanhar o tempo global sem me perder nas subidas e descidas da recursão.
- [ ] Entendo que o tempo é incrementado tanto na descoberta quanto na finalização.
- [ ] Sei que a cor cinza indica arestas de retorno (ciclos).
- [ ] Sei preencher a tabela de teste de mesa com $d$, $f$ e $\pi$.

**Relaciona-se com:**
*   [Revisão Filas e Pilhas](01_REVISAO_FILAS_E_PILHAS.md) (Pilhas Recursivas)
*   [Busca em Largura (BFS)](05_BUSCA_EM_LARGURA_BFS.md)

