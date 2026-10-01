# 05_BUSCA_EM_LARGURA_BFS.md

# Busca em Largura (BFS - Breadth-First Search)

## 1. O que é
É um algoritmo que explora o grafo sistematicamente expandindo a "fronteira" de vértices descobertos. A partir de um nó inicial, visita todos os seus vizinhos diretos (distância 1), para depois visitar os vizinhos dos vizinhos (distância 2), e assim por diante.

## 2. Para que serve
- Achar componentes conectados.
- Achar todos os vértices conectados a 1 componente.
- Achar o **menor caminho** (em número mínimo de arestas) de um vértice de origem a todos os outros vértices acessíveis.
- Testar bipartição em grafos.

## 3. Em qual tipo de grafo é utilizado
Grafos direcionados e não direcionados (para distâncias baseadas puramente em "saltos" ou número de arestas, sem pesos).

## 4. Ideia intuitiva
A BFS processa o grafo em "camadas" ou "níveis". Ela não avança para o nível $k+1$ antes de ter descoberto absolutamente todos os vértices no nível $k$.

## 5. Analogia
Imagine procurar uma pessoa em um prédio visitando primeiro todos os quartos a uma porta de distância de você. Somente depois de abrir todas essas portas, você avança para procurar nos quartos que estão a duas portas de distância.

## 6. Conceitos necessários antes de estudar
- Filas (FIFO).
- Listas de adjacência.
- Conceito de caminhos.

## 7. Variáveis utilizadas pela professora
- `cor[u]`: Estado do vértice.
  - **Branco (B):** Não descoberto.
  - **Cinza (C):** Descoberto (na fronteira), mas com vizinhos não examinados. Fica na fila.
  - **Preto (P):** Vértice descoberto e todos os seus vizinhos já foram examinados.
- `d[u]`: Distância do vértice raiz até `u` (em número de arestas).
- `π[u]`: Predecessor (pai) de `u` na árvore da busca.
- `Q`: Fila que administra a ordem de visitação (mantém os vértices Cinzas).

## 8. Pseudocódigo original da professora

```text
BFS(V, A, s)
1.  para cada vértice u em V - {s}
2.      cor[u] ← BRANCO
3.      d[u] ← ∞
4.      π[u] ← NULO
5.  cor[s] ← CINZA
6.  d[s] ← 0
7.  π[s] ← NULO
8.  Q ← {}
9.  ENFILEIRA(Q, s)
10. enquanto Q não está vazia
11.     u ← DESENFILEIRA(Q)
12.     para cada vértice v adjacente a u
13.         se cor[v] = BRANCO
14.             então cor[v] ← CINZA
15.                   d[v] ← d[u] + 1
16.                   π[v] ← u
17.                   ENFILEIRA(Q, v)
18.     cor[u] ← PRETO
```

## 9. Pseudocódigo traduzido para linguagem simples

A função `BFS` funciona como uma exploração por **camadas** utilizando uma **fila (FIFO)**.

**Preparação:**
Primeiro, o algoritmo prepara todos os vértices:
* Todos os vértices, exceto a origem `s`, são pintados de **Branco**.
* A distância `d[u]` de cada vértice é definida como **infinito (`∞`)**, pois ainda não sabemos se ele será alcançado.
* O predecessor `π[u]` de cada vértice é definido como **NULO**.

Depois, o vértice inicial `s` é preparado:
* `s` fica **Cinza**, pois acabou de ser descoberto.
* `d[s] = 0`, porque a distância da origem para ela mesma é zero.
* `π[s] = NULO`, porque a origem não possui predecessor.

Por fim:
* A fila `Q` é criada vazia.
* O vértice `s` é colocado na fila.

---

## 10. Funcionamento da BFS

Enquanto a fila `Q` não estiver vazia:
1. Retira um vértice da frente da fila.
2. Esse vértice é chamado de `u`.
3. Analisa todos os seus vizinhos.
4. Para cada vizinho `v`:
   * Se `v` ainda estiver **Branco**, significa que ele ainda não foi descoberto.
   * Então:
     * `v` vira **Cinza**.
     * Sua distância recebe `d[u] + 1`.
     * `u` passa a ser o predecessor de `v`.
     * `v` é colocado no final da fila.
5. Depois que **todos os vizinhos de `u` forem examinados**, `u` vira **Preto**.
6. O algoritmo continua retirando vértices da fila até que ela fique vazia.

### Regra principal

> **A BFS sempre termina de processar os vértices de uma camada antes de começar a processar a próxima camada.**

---

## 11. Como executar manualmente

Para executar uma BFS manualmente:
1. Escolha o vértice inicial `s`.
2. Coloque `s` na fila.
3. Pinte `s` de **Cinza**.
4. Coloque `d[s] = 0`.
5. Defina `π[s] = NULO`.
6. Retire o primeiro vértice da fila.
7. Analise seus vizinhos na ordem apresentada pelo grafo ou pela lista de adjacência.
8. Para cada vizinho **Branco**:
   * Pinte de Cinza.
   * Defina sua distância como `d[u] + 1`.
   * Defina seu pai como `u`.
   * Coloque-o no final da fila.
9. Depois de analisar todos os vizinhos de `u`, pinte `u` de **Preto**.
10. Retire o próximo vértice da fila.
11. Repita até a fila ficar vazia.

---

## 12. Exemplo de execução

Considere o seguinte grafo:

```text
        A
       / \
      B   C
     / \   \
    D   E   F
```

Vértice inicial: `A`

A BFS começa com: `Q = [A]`
E:
```text
cor[A] = C
d[A] = 0
π[A] = NULO
```

---

### Passo 1 — Processando A
Retiramos `A` da fila: `Q = []`
Os vizinhos de A são: `B, C` (Os dois estão Brancos).

Então:
```text
B → Cinza
d[B] = d[A] + 1 = 1
π[B] = A

C → Cinza
d[C] = d[A] + 1 = 1
π[C] = A
```

Colocamos os dois na fila: `Q = [B, C]`
Agora A terminou de ser processado: `A → Preto`

---

### Passo 2 — Processando B
Retiramos `B` da fila: `Q = [C]`
Os vizinhos de B são: `A, D, E`
A já está Preto.
D está Branco:
```text
D → Cinza
d[D] = d[B] + 1 = 2
π[D] = B
```
E está Branco:
```text
E → Cinza
d[E] = d[B] + 1 = 2
π[E] = B
```

Agora: `Q = [C, D, E]`
B termina: `B → Preto`

---

### Passo 3 — Processando C
Retiramos `C`: `Q = [D, E]`
Os vizinhos de C são: `A, F`
A já foi visitado. F está Branco:
```text
F → Cinza
d[F] = d[C] + 1 = 2
π[F] = C
```

Fila: `Q = [D, E, F]`
C termina: `C → Preto`

---

### Passo 4 — Processando D
Retiramos D: `Q = [E, F]`
Seus vizinhos já foram descobertos.
Então: `D → Preto`

---

### Passo 5 — Processando E
Retiramos E: `Q = [F]`
Seus vizinhos já foram descobertos.
Então: `E → Preto`

---

### Passo 6 — Processando F
Retiramos F: `Q = []`
Seus vizinhos já foram descobertos.
Então: `F → Preto`
A fila está vazia. A BFS terminou.

---

## 13. Resultado da BFS

### Ordem de descoberta
A ordem em que os vértices foram descobertos foi:
`A → B → C → D → E → F`

### Distâncias

| Vértice | `d` | `π` |
| :--- | --: | :--- |
| A | 0 | NULO |
| B | 1 | A |
| C | 1 | A |
| D | 2 | B |
| E | 2 | B |
| F | 2 | C |

A distância representa o **menor número de arestas** entre a origem e o vértice.
Por exemplo: `d[D] = 2`. Isso significa: `A → B → D` possui 2 arestas.

---

## 14. O papel da fila

A fila é a principal estrutura utilizada pela BFS. Ela segue o princípio:
> **FIFO — First In, First Out (O primeiro que entra é o primeiro que sai).**

Exemplo:
```text
ENFILEIRA(A)
Q = [A]

ENFILEIRA(B)
ENFILEIRA(C)
Q = [A, B, C]

DESENFILEIRA(Q) // Sai o A
Q = [B, C]
```
Isso faz com que a BFS processe os vértices na ordem necessária para explorar o grafo por níveis.

---

## 15. As três cores da BFS

* **Branco:** O vértice ainda não foi descoberto. (`cor[u] = BRANCO`)
* **Cinza:** O vértice foi descoberto e está aguardando ou ainda está sendo processado. Normalmente, os vértices Cinzas estão na **fila**. (`cor[u] = CINZA`)
* **Preto:** O vértice já foi processado completamente e todos os seus vizinhos já foram examinados. (`cor[u] = PRETO`)

---

## 16. Distância `d[u]`

A variável `d[u]` representa a distância entre a origem `s` e o vértice `u`. A distância é medida pelo **número de arestas**. A origem sempre começa com `d[s] = 0`.
Se um vértice `v` é descoberto a partir de `u`: `d[v] = d[u] + 1`.

---

## 17. Predecessor `π[u]`

A variável `π[u]` indica o **pai** ou **predecessor** de `u` na árvore formada pela BFS.
Se `π[D] = B`, significa que D foi descoberto a partir de B. A origem não possui predecessor: `π[A] = NULO`.

---

## 18. Menor caminho

Uma das principais aplicações da BFS é encontrar o **menor caminho em número de arestas** em grafos sem pesos. A BFS garante a menor distância em quantidade de arestas porque processa os vértices por níveis.

---

## 19. BFS em grafos desconectados

Uma BFS iniciada em um único vértice **não necessariamente visita todo o grafo**. Ela visita apenas os vértices que são **alcançáveis a partir da origem**. Para percorrer todo o grafo desconexo, seria necessário iniciar uma nova BFS a partir de algum vértice ainda Branco.

---

## 20. BFS em grafos direcionados

A BFS também pode ser utilizada em grafos direcionados. Nesse caso, devemos respeitar a direção das arestas. A BFS segue somente as arestas disponíveis na direção permitida.

---

## 21. BFS e grafos ponderados

A BFS encontra o menor caminho quando o custo de cada aresta é considerado igual (ex: custo 1). Se as arestas possuírem pesos diferentes, a BFS comum não é adequada para determinar o caminho de menor custo.
Para grafos ponderados, devem ser utilizados:
* **Dijkstra** — pesos não negativos.
* **Bellman-Ford** — permite pesos negativos.
* **Floyd-Warshall** — menor caminho entre todos os pares de vértices.

---

## 22. BFS para testar bipartição

A BFS pode ser utilizada para verificar se um grafo é **bipartido**. A ideia é separar os vértices em dois grupos ou cores.
A regra é: **Vértices adjacentes devem pertencer a grupos diferentes.**
Durante a BFS, o vértice inicial recebe um grupo, seus vizinhos recebem o grupo oposto, e o processo continua alternando. Se em algum momento dois vértices adjacentes precisarem ficar no mesmo grupo, o grafo não é bipartido.

---

## 23. Diferença entre BFS e DFS

| Característica | BFS | DFS |
| :--- | :--- | :--- |
| Nome | Busca em Largura | Busca em Profundidade |
| Estrutura principal | Fila | Pilha / Recursão |
| Estratégia | Explora por níveis | Aprofunda um caminho |
| Menor caminho sem pesos | Sim | Não necessariamente |
| Usa `d[u]` | Sim | Não para distância (usa para "descoberta") |
| Usa `f[u]` | Não | Sim |
| Usa predecessor `π[u]` | Sim | Sim |
| Usa cores | Sim | Sim |
| Pode usar recursão | Não é necessário | Sim |
| Explora primeiro | Vértices mais próximos | Vértice mais profundo disponível |

**Regra para lembrar:**
* **BFS:** Fila → níveis → menor número de arestas.
* **DFS:** Pilha/recursão → profundidade → descoberta e finalização.

---

## 24. Teste de mesa — método para a prova

Ao fazer um teste de mesa da BFS, acompanhe principalmente: a fila `Q`, a cor, a distância `d[u]` e o predecessor `π[u]`.

| Vértice | Cor | `d` | `π` |
| :--- | :--- | --: | :--- |
| A | P | 0 | NULO |
| B | P | 1 | A |
| C | P | 1 | A |
| D | P | 2 | B |
| E | P | 2 | B |
| F | P | 2 | C |

Também é obrigatório acompanhar o estado da fila a cada passo (`Q = [A]`, depois `Q = [B, C]`, etc.) até ela ficar vazia.

---

## 25. Erros comuns na prova

* **Erro 1 — Confundir BFS com DFS:** BFS usa FILA. DFS usa PILHA/RECURSÃO.
* **Erro 2 — Colocar distância 1 na origem:** A origem sempre possui `d[s] = 0`.
* **Erro 3 — Colocar um vértice na fila várias vezes:** Um vértice só vai para a fila quando passa de BRANCO para CINZA.
* **Erro 4 — Confundir Cinza com Preto:** Cinza ainda está na fronteira (na fila). Preto já teve todos os vizinhos examinados.
* **Erro 5 — Achar que BFS sempre percorre todo o grafo:** Ela visita somente os vértices alcançáveis.
* **Erro 6 — Achar que BFS encontra o menor caminho com pesos:** Ela encontra apenas o menor caminho em **número de arestas**.

---

## 26. Checklist para a prova

* [ ] Sei que BFS significa **Busca em Largura**.
* [ ] Sei que BFS utiliza uma **fila (FIFO)**.
* [ ] Sei que a busca ocorre por **níveis/camadas**.
* [ ] Sei que a origem começa com `d[s] = 0`.
* [ ] Sei calcular `d[v] = d[u] + 1`.
* [ ] Sei preencher `π[u]`.
* [ ] Sei diferenciar Branco, Cinza e Preto.
* [ ] Sei acompanhar a fila `Q`.
* [ ] Sei determinar a ordem de descoberta dos vértices.
* [ ] Sei determinar a distância mínima em número de arestas.
* [ ] Sei reconstruir um caminho utilizando `π`.
* [ ] Sei que BFS não necessariamente visita componentes desconectados.
* [ ] Sei que BFS pode ser utilizada em grafos direcionados.
* [ ] Sei que BFS comum não resolve corretamente menor custo em grafos ponderados.
* [ ] Sei a diferença entre BFS e DFS.
* [ ] Sei utilizar BFS para raciocinar sobre bipartição.
* [ ] Sei fazer um teste de mesa acompanhando `Q`, `cor`, `d` e `π`.

---

## Relação com outros conteúdos

Este conteúdo está relacionado com:
* **Filas:** A BFS utiliza uma fila para controlar a ordem de processamento.
* **Pilhas:** Comparação com a estrutura utilizada pela DFS.
* **Busca em Profundidade (DFS):** Outra estratégia para percorrer grafos.
* **Grafos:** Vértices, arestas, caminhos e componentes conexos.
* **Caminhos mínimos:** BFS encontra menores caminhos em número de arestas quando as arestas possuem custo uniforme.
* **Bipartição:** A BFS pode ser utilizada para verificar se um grafo pode ser dividido em dois conjuntos sem que existam arestas entre vértices do mesmo conjunto.


[Próximo](06_BUSCA_EM_PROFUNDIDADE_DFS.md)