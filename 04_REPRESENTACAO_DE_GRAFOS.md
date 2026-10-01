# Representação de Grafos

A professora ensina duas formas principais de representar grafos computacionalmente[cite: 4].

## 1. Lista de Adjacência# Busca em Largura (BFS - Breadth-First Search)
## 1. O que é
É um algoritmo que explora o grafo sistematicamente expandindo a "fronteira" de vértices descobertos. A partir de um nó inicial, visita todos os seus vizinhos diretos (distância 1), para depois visitar os vizinhos dos vizinhos (distância 2), e assim por diante.

## 2. Para que serve# Busca em Largura (BFS - Breadth-First Search)

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

## 9. Pseudocódigo traduzido para linguagem simples**

A função `BFS` funciona como uma exploração por **camadas** utilizando uma **fila (FIFO)**.

### Preparação

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

# 11. Como executar manualmente

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

# 12. Exemplo de execução

Considere o seguinte grafo:

```text
        A
       / \
      B   C
     / \   \
    D   E   F
```

Vértice inicial:

```text
A
```

A BFS começa com:

```text
Q = [A]
```

E:

```text
cor[A] = C
d[A] = 0
π[A] = NULO
```

---

## Passo 1 — Processando A

Retiramos `A` da fila:

```text
Q = []
```

Os vizinhos de A são:

```text
B, C
```

Os dois estão Brancos.

Então:

```text
B → Cinza
d[B] = d[A] + 1 = 1
π[B] = A
```

E:

```text
C → Cinza
d[C] = d[A] + 1 = 1
π[C] = A
```

Colocamos os dois na fila:

```text
Q = [B, C]
```

Agora A terminou de ser processado:

```text
A → Preto
```

---

## Passo 2 — Processando B

Retiramos `B` da fila:

```text
Q = [C]
```

Os vizinhos de B são:

```text
A, D, E
```

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

Agora:

```text
Q = [C, D, E]
```

B termina:

```text
B → Preto
```

---

## Passo 3 — Processando C

Retiramos `C`:

```text
Q = [D, E]
```

Os vizinhos de C são:

```text
A, F
```

A já foi visitado.

F está Branco:

```text
F → Cinza
d[F] = d[C] + 1 = 2
π[F] = C
```

Fila:

```text
Q = [D, E, F]
```

C termina:

```text
C → Preto
```

---

## Passo 4 — Processando D

Retiramos D:

```text
Q = [E, F]
```

Seus vizinhos já foram descobertos.

Então:

```text
D → Preto
```

---

## Passo 5 — Processando E

Retiramos E:

```text
Q = [F]
```

Seus vizinhos já foram descobertos.

Então:

```text
E → Preto
```

---

## Passo 6 — Processando F

Retiramos F:

```text
Q = []
```

Seus vizinhos já foram descobertos.

Então:

```text
F → Preto
```

A fila está vazia.

A BFS terminou.

---

# 13. Resultado da BFS

## Ordem de descoberta

A ordem em que os vértices foram descobertos foi:

```text
A → B → C → D → E → F
```

---

## Distâncias

| Vértice | `d` | `π`  |
| ------- | --: | ---- |
| A       |   0 | NULO |
| B       |   1 | A    |
| C       |   1 | A    |
| D       |   2 | B    |
| E       |   2 | B    |
| F       |   2 | C    |

A distância representa o **menor número de arestas** entre a origem e o vértice.

Por exemplo:

```text
d[A] = 0
d[B] = 1
d[D] = 2
```

Isso significa:

```text
A → B
```

possui 1 aresta, enquanto:

```text
A → B → D
```

possui 2 arestas.

---

# 14. O papel da fila

A fila é a principal estrutura utilizada pela BFS.

Ela segue o princípio:

> **FIFO — First In, First Out**

Ou seja:

> **O primeiro que entra é o primeiro que sai.**

Exemplo:

```text
ENFILEIRA(A)

Q = [A]
```

Depois:

```text
ENFILEIRA(B)
ENFILEIRA(C)

Q = [A, B, C]
```

Quando retiramos um elemento:

```text
DESENFILEIRA(Q)
```

Sai primeiro:

```text
A
```

Restando:

```text
Q = [B, C]
```

Isso faz com que a BFS processe os vértices na ordem necessária para explorar o grafo por níveis.

---

# 15. As três cores da BFS

## Branco

Significa:

> O vértice ainda não foi descoberto.

Exemplo:

```text
cor[u] = BRANCO
```

---

## Cinza

Significa:

> O vértice foi descoberto e está aguardando ou ainda está sendo processado.

Normalmente, os vértices Cinzas estão na **fila**.

```text
cor[u] = CINZA
```

---

## Preto

Significa:

> O vértice já foi processado completamente e todos os seus vizinhos já foram examinados.

```text
cor[u] = PRETO
```

### Resumo

```text
BRANCO → ainda não descoberto

CINZA  → descoberto / na fronteira / aguardando processamento

PRETO  → totalmente processado
```

---

# 16. Distância `d[u]`

A variável `d[u]` representa a distância entre a origem `s` e o vértice `u`.

A distância é medida pelo **número de arestas**.

A origem sempre começa com:

```text
d[s] = 0
```

Se um vértice `v` é descoberto a partir de `u`:

```text
d[v] = d[u] + 1
```

Exemplo:

```text
A → B → D → G
```

Temos:

```text
d[A] = 0
d[B] = 1
d[D] = 2
d[G] = 3
```

---

# 17. Predecessor `π[u]`

A variável `π[u]` indica o **pai** ou **predecessor** de `u` na árvore formada pela BFS.

Se:

```text
π[D] = B
```

significa que D foi descoberto a partir de B.

Exemplo:

```text
A
|
B
|
D
```

Temos:

```text
π[B] = A
π[D] = B
```

A origem não possui predecessor:

```text
π[A] = NULO
```

---

# 18. Menor caminho

Uma das principais aplicações da BFS é encontrar o **menor caminho em número de arestas** em grafos sem pesos.

Considere:

```text
A ─ B ─ D
 \      /
  C ───
```

Partindo de A, a BFS calcula as menores distâncias.

Se:

```text
d[D] = 2
```

então existe um caminho com apenas duas arestas entre A e D.

Por exemplo:

```text
A → B → D
```

ou:

```text
A → C → D
```

A BFS garante a menor distância em quantidade de arestas porque processa os vértices por níveis.

---

# 19. BFS em grafos desconectados

Uma BFS iniciada em um único vértice **não necessariamente visita todo o grafo**.

Ela visita apenas os vértices que são **alcançáveis a partir da origem**.

Por exemplo:

```text
A ─ B ─ C

D ─ E
```

Se começarmos a BFS em A:

```text
A → B → C
```

Os vértices D e E não serão visitados.

Isso acontece porque não existe caminho entre o componente de A e o componente de D.

Para percorrer todo o grafo, seria necessário iniciar uma nova BFS a partir de algum vértice ainda Branco.

---

# 20. BFS em grafos direcionados

A BFS também pode ser utilizada em grafos direcionados.

Nesse caso, devemos respeitar a direção das arestas.

Por exemplo:

```text
A → B → C
```

Partindo de A:

```text
A → B → C
```

Mas não podemos percorrer:

```text
C → B
```

se a aresta existente for apenas:

```text
B → C
```

A BFS segue somente as arestas disponíveis na direção permitida.

---

# 21. BFS e grafos ponderados

A BFS encontra o menor caminho quando o custo de cada aresta é considerado igual, normalmente igual a **1**.

Por exemplo:

```text
A ─ B ─ C
```

Cada aresta representa um custo de 1.

Nesse caso:

```text
A → B → C
```

possui custo total:

```text
1 + 1 = 2
```

Porém, se as arestas possuírem pesos diferentes:

```text
A ──5── B
 \      |
  1     1
   \    |
     C
```

a BFS comum não é adequada para determinar o caminho de menor custo.

Para grafos ponderados, outros algoritmos podem ser utilizados, como:

* **Dijkstra** — pesos não negativos.
* **Bellman-Ford** — permite pesos negativos.
* **Floyd-Warshall** — menor caminho entre todos os pares de vértices.

---

# 22. BFS para testar bipartição

A BFS também pode ser utilizada para verificar se um grafo é **bipartido**.

A ideia é separar os vértices em dois grupos ou cores.

Por exemplo:

```text
Grupo 1: A, D, E

Grupo 2: B, C, F
```

A regra é:

> Vértices adjacentes devem pertencer a grupos diferentes.

Durante a BFS:

* O vértice inicial recebe uma cor/grupo.
* Seus vizinhos recebem o grupo oposto.
* Os vizinhos desses vizinhos recebem novamente o primeiro grupo.
* O processo continua alternando os grupos.

Se em algum momento dois vértices adjacentes precisarem ficar no mesmo grupo, o grafo não é bipartido.

---

# 23. Diferença entre BFS e DFS

| Característica          | BFS                    | DFS                              |
| ----------------------- | ---------------------- | -------------------------------- |
| Nome                    | Busca em Largura       | Busca em Profundidade            |
| Estrutura principal     | Fila                   | Pilha / Recursão                 |
| Estratégia              | Explora por níveis     | Aprofunda um caminho             |
| Menor caminho sem pesos | Sim                    | Não necessariamente              |
| Usa `d[u]`              | Sim                    | Não para distância               |
| Usa `f[u]`              | Não                    | Sim                              |
| Usa predecessor `π[u]`  | Sim                    | Sim                              |
| Usa cores               | Sim                    | Sim                              |
| Pode usar recursão      | Não é necessário       | Sim                              |
| Explora primeiro        | Vértices mais próximos | Vértice mais profundo disponível |

### Regra para lembrar

**BFS:**

> **Fila → níveis → menor número de arestas.**

**DFS:**

> **Pilha/recursão → profundidade → descoberta e finalização.**

---

# 24. Teste de mesa — método para a prova

Ao fazer um teste de mesa da BFS, acompanhe principalmente:

1. A fila `Q`.
2. A cor de cada vértice.
3. A distância `d[u]`.
4. O predecessor `π[u]`.
5. A ordem em que os vértices são descobertos.
6. A ordem em que os vértices são retirados da fila.

Uma tabela pode ser organizada assim:

| Vértice | Cor | `d` | `π`  |
| ------- | --- | --: | ---- |
| A       | P   |   0 | NULO |
| B       | P   |   1 | A    |
| C       | P   |   1 | A    |
| D       | P   |   2 | B    |
| E       | P   |   2 | B    |
| F       | P   |   2 | C    |

Também é importante acompanhar a fila:

```text
Início:
Q = [A]

Depois de processar A:
Q = [B, C]

Depois de processar B:
Q = [C, D, E]

Depois de processar C:
Q = [D, E, F]

Depois de processar D:
Q = [E, F]

Depois de processar E:
Q = [F]

Depois de processar F:
Q = []
```

Quando:

```text
Q = []
```

a BFS terminou.

---

# 25. Erros comuns na prova

### Erro 1 — Confundir BFS com DFS

Não confundir:

```text
BFS → FILA
DFS → PILHA/RECURSÃO
```

---

### Erro 2 — Colocar distância 1 na origem

A origem sempre possui:

```text
d[s] = 0
```

Não:

```text
d[s] = 1
```

---

### Erro 3 — Colocar um vértice na fila várias vezes

Um vértice deve ser colocado na fila quando é descoberto, ou seja, quando passa de:

```text
BRANCO → CINZA
```

Depois disso, ele não deve ser descoberto novamente.

---

### Erro 4 — Confundir Cinza com Preto

**Cinza:**

> Ainda está na fronteira da busca ou sendo processado.

**Preto:**

> Todos os seus vizinhos já foram examinados.

---

### Erro 5 — Achar que BFS sempre percorre todo o grafo

Uma BFS iniciada em `s` percorre somente os vértices **alcançáveis a partir de `s`**.

Se o grafo for desconexo, será necessário iniciar novas buscas para percorrer os outros componentes.

---

### Erro 6 — Achar que BFS encontra o menor caminho com pesos

A BFS encontra o menor caminho em **número de arestas**, não necessariamente o menor caminho em custo.

Para pesos diferentes, é necessário utilizar um algoritmo apropriado, como Dijkstra ou Bellman-Ford, dependendo das características do grafo.

---

# 26. Checklist para a prova

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

# Relação com outros conteúdos

Este conteúdo está relacionado com:

* **Filas**

  * A BFS utiliza uma fila para controlar a ordem de processamento.

* **Pilhas**

  * Comparação com a estrutura utilizada pela DFS.

* **Busca em Profundidade (DFS)**

  * Outra estratégia para percorrer grafos.

* **Grafos**

  * Vértices, arestas, caminhos e componentes conexos.

* **Caminhos mínimos**

  * BFS encontra menores caminhos em número de arestas quando as arestas possuem custo uniforme.

* **Bipartição**

  * A BFS pode ser utilizada para verificar se um grafo pode ser dividido em dois conjuntos sem que existam arestas entre vértices do mesmo conjunto.

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


## 9. Pseudocódigo traduzido para linguagem simples
A função `BFS` funciona como uma exploração por **camadas** utilizando uma **fila (FIFO)**.

### Preparação

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

# 11. Como executar manualmente

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

# 12. Exemplo de execução

Considere o seguinte grafo:

```text
        A

       / \\

      B   C

     / \   \\

    D   E   F

```
Vértice inicial:

```text
A

```
A BFS começa com:

```text
Q = [A]

```
E:

```text
cor[A] = C

d[A] = 0

π[A] = NULO

```
---
## Passo 1 — Processando A
Retiramos `A` da fila:

```text
Q = []

```
Os vizinhos de A são:

```text
B, C

```
Os dois estão Brancos.

Então:

```text
B → Cinza

d[B] = d[A] + 1 = 1

π[B] = A

```
E:

```text
C → Cinza

d[C] = d[A] + 1 = 1

π[C] = A

```
Colocamos os dois na fila:

```text
Q = [B, C]

```
Agora A terminou de ser processado:

```text
A → Preto

```
---
## Passo 2 — Processando B
Retiramos `B` da fila:

```text
Q = [C]

```
Os vizinhos de B são:

```text
A, D, E

```
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
Agora:

```text
Q = [C, D, E]

```
B termina:

```text
B → Preto

```
---
## Passo 3 — Processando C
Retiramos `C`:

```text
Q = [D, E]

```
Os vizinhos de C são:

```text
A, F

```
A já foi visitado.

F está Branco:

```text
F → Cinza

d[F] = d[C] + 1 = 2

π[F] = C

```
Fila:

```text
Q = [D, E, F]

```
C termina:

```text
C → Preto

```
---
## Passo 4 — Processando D
Retiramos D:

```text
Q = [E, F]

```
Seus vizinhos já foram descobertos.

Então:

```text
D → Preto

```
---
## Passo 5 — Processando E
Retiramos E:

```text
Q = [F]

```
Seus vizinhos já foram descobertos.

Então:

```text
E → Preto

```
---
## Passo 6 — Processando F
Retiramos F:

```text
Q = []

```
Seus vizinhos já foram descobertos.

Então:

```text
F → Preto

```
A fila está vazia.

A BFS terminou.

---
# 13. Resultado da BFS
## Ordem de descoberta
A ordem em que os vértices foram descobertos foi:

```text
A → B → C → D → E → F

```
---
## Distâncias
\| Vértice | `d` | `π`  |

\| ------- | --: | ---- |

\| A       |   0 | NULO |

\| B       |   1 | A    |

\| C       |   1 | A    |

\| D       |   2 | B    |

\| E       |   2 | B    |

\| F       |   2 | C    |

A distância representa o **menor número de arestas** entre a origem e o vértice.

Por exemplo:

```text
d[A] = 0

d[B] = 1

d[D] = 2

```
Isso significa:

```text
A → B

```
possui 1 aresta, enquanto:

```text
A → B → D

```
possui 2 arestas.

---
# 14. O papel da fila
A fila é a principal estrutura utilizada pela BFS.

Ela segue o princípio:

> **FIFO — First In, First Out**

Ou seja:

> **O primeiro que entra é o primeiro que sai.**

Exemplo:

```text
ENFILEIRA(A)

Q = [A]

```
Depois:

```text
ENFILEIRA(B)

ENFILEIRA(C)

Q = [A, B, C]

```
Quando retiramos um elemento:

```text
DESENFILEIRA(Q)

```
Sai primeiro:

```text
A

```
Restando:

```text
Q = [B, C]

```
Isso faz com que a BFS processe os vértices na ordem necessária para explorar o grafo por níveis.

---
# 15. As três cores da BFS
## Branco
Significa:

> O vértice ainda não foi descoberto.

Exemplo:

```text
cor[u] = BRANCO

```
---
## Cinza
Significa:

> O vértice foi descoberto e está aguardando ou ainda está sendo processado.

Normalmente, os vértices Cinzas estão na **fila**.

```text
cor[u] = CINZA

```
---
## Preto
Significa:

> O vértice já foi processado completamente e todos os seus vizinhos já foram examinados.

```text
cor[u] = PRETO

```
### Resumo
```text
BRANCO → ainda não descoberto

CINZA  → descoberto / na fronteira / aguardando processamento

PRETO  → totalmente processado

```
---
# 16. Distância `d[u]`
A variável `d[u]` representa a distância entre a origem `s` e o vértice `u`.

A distância é medida pelo **número de arestas**.

A origem sempre começa com:

```text
d[s] = 0

```
Se um vértice `v` é descoberto a partir de `u`:

```text
d[v] = d[u] + 1

```
Exemplo:

```text
A → B → D → G

```
Temos:

```text
d[A] = 0

d[B] = 1

d[D] = 2

d[G] = 3

```
---
# 17. Predecessor `π[u]`
A variável `π[u]` indica o **pai** ou **predecessor** de `u` na árvore formada pela BFS.

Se:

```text
π[D] = B

```
significa que D foi descoberto a partir de B.

Exemplo:

```text
A

|

B

|

D

```
Temos:

```text
π[B] = A

π[D] = B

```
A origem não possui predecessor:

```text
π[A] = NULO

```
---
# 18. Menor caminho
Uma das principais aplicações da BFS é encontrar o **menor caminho em número de arestas** em grafos sem pesos.

Considere:

```text
A ─ B ─ D

 \      /

  C ───

```
Partindo de A, a BFS calcula as menores distâncias.

Se:

```text
d[D] = 2

```
então existe um caminho com apenas duas arestas entre A e D.

Por exemplo:

```text
A → B → D

```
ou:

```text
A → C → D

```
A BFS garante a menor distância em quantidade de arestas porque processa os vértices por níveis.

---
# 19. BFS em grafos desconectados
Uma BFS iniciada em um único vértice **não necessariamente visita todo o grafo**.

Ela visita apenas os vértices que são **alcançáveis a partir da origem**.

Por exemplo:

```text
A ─ B ─ C

D ─ E

```
Se começarmos a BFS em A:

```text
A → B → C

```
Os vértices D e E não serão visitados.

Isso acontece porque não existe caminho entre o componente de A e o componente de D.

Para percorrer todo o grafo, seria necessário iniciar uma nova BFS a partir de algum vértice ainda Branco.

---
# 20. BFS em grafos direcionados
A BFS também pode ser utilizada em grafos direcionados.

Nesse caso, devemos respeitar a direção das arestas.

Por exemplo:

```text
A → B → C

```
Partindo de A:

```text
A → B → C

```
Mas não podemos percorrer:

```text
C → B

```
se a aresta existente for apenas:

```text
B → C

```
A BFS segue somente as arestas disponíveis na direção permitida.

---
# 21. BFS e grafos ponderados
A BFS encontra o menor caminho quando o custo de cada aresta é considerado igual, normalmente igual a **1**.

Por exemplo:

```text
A ─ B ─ C

```
Cada aresta representa um custo de 1.

Nesse caso:

```text
A → B → C

```
possui custo total:

```text
1 + 1 = 2

```
Porém, se as arestas possuírem pesos diferentes:

```text
A ──5── B

 \      |

  1     1

   \    |

     C

```
a BFS comum não é adequada para determinar o caminho de menor custo.

Para grafos ponderados, outros algoritmos podem ser utilizados, como:

* **Dijkstra** — pesos não negativos.

* **Bellman-Ford** — permite pesos negativos.

* **Floyd-Warshall** — menor caminho entre todos os pares de vértices.

---
# 22. BFS para testar bipartição
A BFS também pode ser utilizada para verificar se um grafo é **bipartido**.

A ideia é separar os vértices em dois grupos ou cores.

Por exemplo:

```text
Grupo 1: A, D, E

Grupo 2: B, C, F

```
A regra é:

> Vértices adjacentes devem pertencer a grupos diferentes.

Durante a BFS:

* O vértice inicial recebe uma cor/grupo.

* Seus vizinhos recebem o grupo oposto.

* Os vizinhos desses vizinhos recebem novamente o primeiro grupo.

* O processo continua alternando os grupos.

Se em algum momento dois vértices adjacentes precisarem ficar no mesmo grupo, o grafo não é bipartido.

---
# 23. Diferença entre BFS e DFS
\| Característica          | BFS                    | DFS                              |

\| ----------------------- | ---------------------- | -------------------------------- |

\| Nome                    | Busca em Largura       | Busca em Profundidade            |

\| Estrutura principal     | Fila                   | Pilha / Recursão                 |

\| Estratégia              | Explora por níveis     | Aprofunda um caminho             |

\| Menor caminho sem pesos | Sim                    | Não necessariamente              |

\| Usa `d[u]`              | Sim                    | Não para distância               |

\| Usa `f[u]`              | Não                    | Sim                              |

\| Usa predecessor `π[u]`  | Sim                    | Sim                              |

\| Usa cores               | Sim                    | Sim                              |

\| Pode usar recursão      | Não é necessário       | Sim                              |

\| Explora primeiro        | Vértices mais próximos | Vértice mais profundo disponível |

### Regra para lembrar
**BFS:**

> **Fila → níveis → menor número de arestas.**

**DFS:**

> **Pilha/recursão → profundidade → descoberta e finalização.**

---
# 24. Teste de mesa — método para a prova
Ao fazer um teste de mesa da BFS, acompanhe principalmente:

1. A fila `Q`.

2. A cor de cada vértice.

3. A distância `d[u]`.

4. O predecessor `π[u]`.

5. A ordem em que os vértices são descobertos.

6. A ordem em que os vértices são retirados da fila.

Uma tabela pode ser organizada assim:

\| Vértice | Cor | `d` | `π`  |

\| ------- | --- | --: | ---- |

\| A       | P   |   0 | NULO |

\| B       | P   |   1 | A    |

\| C       | P   |   1 | A    |

\| D       | P   |   2 | B    |

\| E       | P   |   2 | B    |

\| F       | P   |   2 | C    |

Também é importante acompanhar a fila:

```text
Início:

Q = [A]

Depois de processar A:

Q = [B, C]

Depois de processar B:

Q = [C, D, E]

Depois de processar C:

Q = [D, E, F]

Depois de processar D:

Q = [E, F]

Depois de processar E:

Q = [F]

Depois de processar F:

Q = []

```
Quando:

```text
Q = []

```
a BFS terminou.

---
# 25. Erros comuns na prova
### Erro 1 — Confundir BFS com DFS
Não confundir:

```text
BFS → FILA

DFS → PILHA/RECURSÃO

```
---
### Erro 2 — Colocar distância 1 na origem
A origem sempre possui:

```text
d[s] = 0

```
Não:

```text
d[s] = 1

```
---
### Erro 3 — Colocar um vértice na fila várias vezes
Um vértice deve ser colocado na fila quando é descoberto, ou seja, quando passa de:

```text
BRANCO → CINZA

```
Depois disso, ele não deve ser descoberto novamente.

---
### Erro 4 — Confundir Cinza com Preto
**Cinza:**

> Ainda está na fronteira da busca ou sendo processado.

**Preto:**

> Todos os seus vizinhos já foram examinados.

---
### Erro 5 — Achar que BFS sempre percorre todo o grafo
Uma BFS iniciada em `s` percorre somente os vértices **alcançáveis a partir de `s`**.

Se o grafo for desconexo, será necessário iniciar novas buscas para percorrer os outros componentes.

---
### Erro 6 — Achar que BFS encontra o menor caminho com pesos
A BFS encontra o menor caminho em **número de arestas**, não necessariamente o menor caminho em custo.

Para pesos diferentes, é necessário utilizar um algoritmo apropriado, como Dijkstra ou Bellman-Ford, dependendo das características do grafo.

---
# 26. Checklist para a prova
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
# Relação com outros conteúdos
Este conteúdo está relacionado com:

* **Filas**

  * A BFS utiliza uma fila para controlar a ordem de processamento.

* **Pilhas**

  * Comparação com a estrutura utilizada pela DFS.

* **Busca em Profundidade (DFS)**

  * Outra estratégia para percorrer grafos.

* **Grafos**

  * Vértices, arestas, caminhos e componentes conexos.

* **Caminhos mínimos**

  * BFS encontra menores caminhos em número de arestas quando as arestas possuem custo uniforme.

* **Bipartição**

  * A BFS pode ser utilizada para verificar se um grafo pode ser dividido em dois conjuntos sem que existam arestas entre vértices do mesmo conjunto.
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