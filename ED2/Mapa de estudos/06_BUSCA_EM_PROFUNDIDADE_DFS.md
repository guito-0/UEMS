# 06_BUSCA_EM_PROFUNDIDADE_DFS.md

# Busca em Profundidade (DFS - Depth-First Search)

## 1. O que é

É um algoritmo de travessia que explora o grafo indo "o mais fundo possível" num caminho antes de voltar (backtracking) para explorar os ramos alternativos. A DFS visita **todos** os vértices do grafo, mesmo aqueles em componentes desconexas, ao contrário da BFS.

## 2. Para que serve

* Encontrar componentes conectados e componentes fortemente conectados.
* Ordenação topológica de um grafo.
* Resolver quebra-cabeças (como labirintos).

## 3. Em qual tipo de grafo é utilizado

Grafos direcionados e não direcionados.

## 4. Ideia intuitiva

A DFS avança por uma aresta e imediatamente chama a si mesma recursivamente para o próximo vértice. Ela só volta para o vértice anterior quando chega a um "beco sem saída" (um vértice sem vizinhos brancos).

## 5. Analogia

Imagine entrar num labirinto e continuar a andar até bater numa parede sem saída (fundo). Só então recua (volta um passo) para apanhar o último corredor que ignorou.

## 6. Conceitos necessários antes de estudar

* Pilhas (LIFO) e Pilha de Chamadas Recursivas.
* Grafos direcionados e não direcionados.

## 7. Variáveis utilizadas

* `cor[u]`: Estado do vértice.
* **Branco:** Não descoberto (antes de `d`).
* **Cinza:** Descoberto, mas os seus vizinhos ainda estão a ser examinados (entre `d` e `f`).
* **Preto:** Vértice e toda a sua subárvore descendente já foram processados (após `f`).


* `d[u]`: Instante de **descoberta** do vértice.
* `f[u]`: Instante de **finalização** do vértice (quando ele vira preto).
* `\pi[u]`: Predecessor (pai) de $u$ na árvore da busca.
* `tempo`: Variável global que é incrementada a cada evento (descoberta ou finalização).

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

* **A função DFS:** Simplesmente zera os relógios (`tempo = 0`), pinta toda a gente de branco, e depois varre a lista de vértices. Se achar um branco, inicia a busca profunda a partir dele chamando `DFS-Visita(u)`. Isto garante que todo o grafo será varrido, criando uma floresta caso haja desconexão.


* **A função DFS-Visita:**
* Pinta de Cinza (descobriu).


* Sobe o relógio e anota a hora de descoberta `d[u]`.
* Olha para os vizinhos: Se o vizinho for Branco, declaro-me pai dele e já chamo a função `DFS-Visita` para ele imediatamente (recursão).
* Depois que todos os vizinhos encerrarem e a recursão voltar, pinto de Preto.
* Sobe o relógio novamente e anota a hora de fim `f[u]`.



## 10. Como executar manualmente

1. Comece no nó raiz indicado (ou iterando pela lista).
2. Pinte de cinza, aumente o tempo `d`.
3. Escolha o primeiro vizinho Branco e vá para ele imediatamente.
4. Repita até o nó não ter mais vizinhos brancos.
5. Se não tiver mais vizinhos brancos, pinte de preto, aumente o tempo `f` e retorne para o nó pai para verificar se ele tem outros vizinhos brancos.

## 11. Exemplo de execução passo a passo

Considere o seguinte grafo:

```text
        A
       / \
      B   C
     / \   \
    D   E   F

```

Vértice inicial: `A` (assumindo que a ordem de vizinhos observada será alfabética).
Todos iniciam Brancos, com $\pi$ = NULO e tempo global = 0.

**Passo 1 — Iniciando em A (Descoberta)**
Chamamos `DFS-Visita(A)`:

```text
tempo = 1
cor[A] = C
d[A] = 1
π[A] = NULO

```

Os vizinhos de A são: B, C. (O primeiro em ordem alfabética é B, que está Branco).

**Passo 2 — Mergulhando em B (Descoberta)**
A partir de A, chamamos imediatamente `DFS-Visita(B)`:

```text
tempo = 2
cor[B] = C
d[B] = 2
π[B] = A

```

Os vizinhos de B são: A, D, E. A já está Cinza. D está Branco.

**Passo 3 — Mergulhando em D (Descoberta)**
A partir de B, chamamos imediatamente `DFS-Visita(D)`:

```text
tempo = 3
cor[D] = C
d[D] = 3
π[D] = B

```

Os vizinhos de D são: B. B já está Cinza.
D não tem mais vizinhos brancos (beco sem saída).

**Passo 4 — Finalizando D (Fundo do poço)**
A função de D encerra.

```text
cor[D] = P
tempo = 4
f[D] = 4

```

A execução (backtracking) volta para `B`.

**Passo 5 — De volta a B, descobrindo E (Descoberta)**
Estamos em B. Vizinhos de B eram A, D, E. D já foi. E está Branco.
Chamamos `DFS-Visita(E)`:

```text
tempo = 5
cor[E] = C
d[E] = 5
π[E] = B

```

Os vizinhos de E são: B. B já está Cinza. Sem vizinhos brancos.

**Passo 6 — Finalizando E**
A função de E encerra.

```text
cor[E] = P
tempo = 6
f[E] = 6

```

Volta para `B`.

**Passo 7 — Finalizando B**
Em B, vizinhos A (Cinza), D (Preto), E (Preto). Sem mais vizinhos brancos.

```text
cor[B] = P
tempo = 7
f[B] = 7

```

Volta para `A`.

**Passo 8 — De volta a A, descobrindo C (Descoberta)**
Em A, os vizinhos eram B e C. B já está Preto. C está Branco.
Chamamos `DFS-Visita(C)`:

```text
tempo = 8
cor[C] = C
d[C] = 8
π[C] = A

```

Os vizinhos de C são: A (Cinza) e F (Branco). Vamos para F.

**Passo 9 — Mergulhando em F (Descoberta)**
A partir de C, chamamos `DFS-Visita(F)`:

```text
tempo = 9
cor[F] = C
d[F] = 9
π[F] = C

```

Vizinhos de F: C (Cinza). Sem vizinhos brancos.

**Passo 10 — Finalizando F**
A função de F encerra.

```text
cor[F] = P
tempo = 10
f[F] = 10

```

Volta para `C`.

**Passo 11 — Finalizando C**
Em C, vizinhos A (Cinza) e F (Preto). Sem mais vizinhos brancos.

```text
cor[C] = P
tempo = 11
f[C] = 11

```

Volta para `A`.

**Passo 12 — Finalizando A**
Em A, vizinhos B (Preto) e C (Preto). A não possui mais vizinhos brancos.

```text
cor[A] = P
tempo = 12
f[A] = 12

```

O algoritmo termina.

**Resumo Final de Tempos (d / f):**

* **A:** 1 / 12
* **B:** 2 / 7
* **C:** 8 / 11
* **D:** 3 / 4
* **E:** 5 / 6
* **F:** 9 / 10

## 12. Comparação BFS x DFS

* **DFS** usa **Pilha** (recursão). Explora até ao fundo e volta (backtracking). Visita **todos** os vértices e componentes. Gera tempos de descoberta e finalização (`d` e `f`).
* **BFS** usa **Fila**. Explora em camadas (largura). Acha o caminho mais curto. Visita apenas a componente conectada na raiz.

## 13. Checklist para prova

* [ ] Sei acompanhar o tempo global sem me perder nas subidas e descidas da recursão.
* [ ] Entendo que o tempo é incrementado tanto na descoberta quanto na finalização.
* [ ] Sei que a cor cinza indica que estou a descer num ramo que ainda não foi concluído.
* [ ] Sei preencher a tabela de teste de mesa com $d$, $f$ e $\pi$.


**Relaciona-se com:**
*   [Revisão Filas e Pilhas](01_REVISAO_FILAS_E_PILHAS.md) (Pilhas Recursivas)
*   [Busca em Largura (BFS)](05_BUSCA_EM_LARGURA_BFS.md)


[Próximo](07_COMPARACAO_BFS_x_DFS.md)

