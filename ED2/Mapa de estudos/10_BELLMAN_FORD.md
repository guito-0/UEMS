# 10_BELLMAN_FORD.md

# Algoritmo de Bellman-Ford

## 1. O que é

É um algoritmo para caminhos mínimos que examina todos os vértices de um grafo orientado repetidas vezes por iteração, até que atualizações não sejam mais possíveis.

---

## 2. Para que serve

Para calcular caminhos mínimos em cenários que necessitam de arestas com peso negativo.

**Aplicações reais:**

- Movimentações financeiras com lucros ou prejuízos (uso de câmbio).
- Um taxista que gasta combustível rodando vazio (prejuízo) vs. rodando cheio (lucro).
- Entregador cruzando um pedágio caro.
- Energia gerada e consumida em reações químicas.

---

## 3. Em qual tipo de grafo é utilizado

Grafos orientados ponderados com **arestas de peso negativo**.

---

## 4. Ideia intuitiva

Ao invés de fechar um vértice definitivamente por iteração (como o Dijkstra), ele processa relaxamentos em todo o grafo.

Em um grafo com $n$ vértices, qualquer caminho ótimo tem no máximo $n-1$ arestas. Por isso, cada vértice é examinado no máximo $n-1$ vezes.

---

## 5. Analogia

Você repassa as estimativas de distâncias sobre todas as estradas repetidas vezes, permitindo que a propagação da informação sobre rotas negativas percorra todo o mapa em até $n-1$ "ondas" de atualização.

Se após essas ondas os valores ainda continuarem diminuindo, é porque você encontrou um poço sem fundo (um ciclo negativo infinito).

---

## 6. Conceitos necessários antes de estudar

- [Relaxamento](08_CAMINHOS_MINIMOS_CONCEITOS.md).
- Ciclos de peso negativo.

---

## 7. Variáveis utilizadas pela professora

- `ω[v]`: Estimativa do caminho (distância acumulada).
- `π[v]`: Predecessor (pai).
- **Ordem das arestas:** É crucial para o teste de mesa da professora. A lista de arestas é avaliada em uma ordem estritamente definida.

---

## 8. Pseudocódigo original da professora

```text
BELLMAN-FORD(V, A, w, s)

1.  para cada vértice v ∈ V
2.      ω[v] = ∞
3.      π[v] = ⊥
4.  ω[s] = 0
5.  de i=1 até n-1 faça
6.      para toda aresta uv ∈ A faça
7.          se ω[v] > ω[u] + w(u,v) então
8.              ω[v] = ω[u] + w(u,v)
9.              π[v] = u
10. para toda aresta uv ∈ A faça:
11.     se ω[v] > ω[u] + w(u,v) então
12.         devolve FALSE
13. devolve TRUE

(Onde n = |V|)
```

---

## 9. Pseudocódigo traduzido para linguagem simples

### Linhas 1–4

Prepara todos os nós com distância `ω = ∞` e pai `π = ⊥`.

A distância do vértice inicial `s` recebe `0`.

### Linha 5

Inicia um super-loop que se repetirá $n-1$ vezes, onde $n$ é a quantidade total de nós.

### Linhas 6–9

Dentro do super-loop, ele varre a lista completa de todas as arestas.

Faz a checagem clássica de relaxamento:

> "A distância atual para `v` é pior que a distância para `u` somada ao custo da aresta de `u` até `v`?"

Se sim, ele atualiza `ω[v]` e anota `π[v] = u`.

### Linhas 10–12

A fase de auditoria.

Ele varre as arestas mais uma vez inteira. Se, mesmo depois de rodar tudo $n-1$ vezes, ele ainda achar uma aresta que permite diminuir o custo de um nó, significa que há um ciclo de peso negativo.

O algoritmo devolve `FALSE` avisando do erro.

### Linha 13

Se a fase de auditoria passou limpa, o caminho mínimo é validado e retorna `TRUE`.

---

## 10. Como executar manualmente

1. Anote a ordem das arestas que a professora exigiu.
2. Inicie a tabela zerando a origem e setando os demais como infinito.
3. Desça a lista de arestas verificando o relaxamento de forma rigorosamente sequencial.
4. Atualize a tabela na hora.
5. Repita a descida na lista o número de vezes igual ao total de vértices menos 1 ($n-1$).
6. Faça uma última descida na lista.
7. Se algum cálculo der menor, decrete falha por ciclo negativo.

---

## 11. Teste de mesa — método da professora

Vamos aplicar o Bellman-Ford no mesmo grafo utilizado como exemplo na BFS.

Para isso, atribuímos direção (de cima para baixo) e peso `1` em todas as arestas, já que a BFS calcula distância em "número de saltos".

### Grafo de exemplo

```text
        A
       / \
      B   C
     / \   \
    D   E   F
```

**Vértice inicial (`s`):** `A`

**Total de vértices (`n`):** 6 (`A`, `B`, `C`, `D`, `E`, `F`)

**Número de iterações do laço principal:**

$$
n - 1 = 5
$$

### Ordem das arestas fixada para o teste

Para demonstrar o algoritmo propagando as distâncias em "ondas", definimos a ordem das arestas de baixo para cima:

1. `C → F` | peso `1`
2. `B → E` | peso `1`
3. `B → D` | peso `1`
4. `A → C` | peso `1`
5. `A → B` | peso `1`

---

# 12. Exemplo completo passo a passo

## Estado Inicial — Linhas 1 a 4

A distância da origem para ela mesma é zero:

$$
\omega[A] = 0
$$

O resto é infinito:

$$
\omega[B] = \omega[C] = \omega[D] = \omega[E] = \omega[F] = \infty
$$

O predecessor de todos é nulo:

$$
\pi[v] = \perp
$$

### Tabela inicial

| Vértice | A | B | C | D | E | F |
|---|---:|---:|---:|---:|---:|---:|
| **ω** | 0 | ∞ | ∞ | ∞ | ∞ | ∞ |
| **π** | ⊥ | ⊥ | ⊥ | ⊥ | ⊥ | ⊥ |

---

## Iteração 1 — Onda 1

Varremos todas as arestas na ordem estrita e aplicamos a regra:

$$
\omega[\text{destino}] >
\omega[\text{origem}] + \text{peso}
$$

### 1. `C → F`

$$
\omega[F] > \omega[C] + 1
$$

$$
\infty > \infty + 1
$$

**Falso.**

Nenhuma alteração.

### 2. `B → E`

$$
\omega[E] > \omega[B] + 1
$$

$$
\infty > \infty + 1
$$

**Falso.**

Nenhuma alteração.

### 3. `B → D`

$$
\omega[D] > \omega[B] + 1
$$

$$
\infty > \infty + 1
$$

**Falso.**

Nenhuma alteração.

### 4. `A → C`

$$
\omega[C] > \omega[A] + 1
$$

$$
\infty > 0 + 1
$$

**Verdadeiro!**

Atualização:

$$
\omega[C] = 1
$$

$$
\pi[C] = A
$$

### 5. `A → B`

$$
\omega[B] > \omega[A] + 1
$$

$$
\infty > 0 + 1
$$

**Verdadeiro!**

Atualização:

$$
\omega[B] = 1
$$

$$
\pi[B] = A
$$

### Tabela ao final da Iteração 1

A informação saiu de `A` e alcançou apenas `B` e `C`.

| Vértice | A | B | C | D | E | F |
|---|---:|---:|---:|---:|---:|---:|
| **ω** | 0 | 1 | 1 | ∞ | ∞ | ∞ |
| **π** | ⊥ | A | A | ⊥ | ⊥ | ⊥ |

---

## Iteração 2 — Onda 2

Repetimos a lista inteira na mesma ordem.

### 1. `C → F`

$$
\omega[F] > \omega[C] + 1
$$

$$
\infty > 1 + 1
$$

**Verdadeiro!**

Atualização:

$$
\omega[F] = 2
$$

$$
\pi[F] = C
$$

### 2. `B → E`

$$
\omega[E] > \omega[B] + 1
$$

$$
\infty > 1 + 1
$$

**Verdadeiro!**

Atualização:

$$
\omega[E] = 2
$$

$$
\pi[E] = B
$$

### 3. `B → D`

$$
\omega[D] > \omega[B] + 1
$$

$$
\infty > 1 + 1
$$

**Verdadeiro!**

Atualização:

$$
\omega[D] = 2
$$

$$
\pi[D] = B
$$

### 4. `A → C`

$$
\omega[C] > \omega[A] + 1
$$

$$
1 > 0 + 1
$$

**Falso.**

Nenhuma alteração.

### 5. `A → B`

$$
\omega[B] > \omega[A] + 1
$$

$$
1 > 0 + 1
$$

**Falso.**

Nenhuma alteração.

### Tabela ao final da Iteração 2

A informação dos nós `B` e `C` propagou para `D`, `E` e `F`.

| Vértice | A | B | C | D | E | F |
|---|---:|---:|---:|---:|---:|---:|
| **ω** | 0 | 1 | 1 | 2 | 2 | 2 |
| **π** | ⊥ | A | A | B | B | C |

---

## Iterações 3, 4 e 5

O algoritmo é "cego"; ele não sabe que o grafo já está resolvido.

Ele cumprirá rigorosamente o laço de $n-1$ vezes.

Ao testar a mesma lista de arestas nas rodadas finais, nenhuma condição de relaxamento será atendida.

Por exemplo:

$$
2 > 1 + 1
$$

é **falso**.

A tabela permanece inalterada.

---

## Etapa de Verificação — Linhas 10 a 12

Para garantir que não existem ciclos de peso negativo, o algoritmo faz uma última varredura na lista de arestas.

### `C → F`

$$
2 > 1 + 1
$$

**Falso.**

### `B → E`

$$
2 > 1 + 1
$$

**Falso.**

### `B → D`

$$
2 > 1 + 1
$$

**Falso.**

### `A → C`

$$
1 > 0 + 1
$$

**Falso.**

### `A → B`

$$
1 > 0 + 1
$$

**Falso.**

Nenhuma distância diminuiu.

Portanto, o algoritmo retorna:

```text
TRUE
```

---

# 13. Como saber qual decisão tomar em cada passo

Diferente de algoritmos gulosos, como o Dijkstra, você **não toma decisões ativas escolhendo caminhos**.

Você é forçado a:

1. Percorrer a lista inteira de arestas.
2. Seguir a ordem pré-definida.
3. Aplicar a fórmula de relaxamento.
4. Atualizar imediatamente quando a condição for verdadeira.
5. Continuar até terminar a lista.

A regra fundamental é:

$$
\omega[v] > \omega[u] + w(u,v)
$$

Se for **verdadeira**:

$$
\omega[v] = \omega[u] + w(u,v)
$$

e:

$$
\pi[v] = u
$$

Se for **falsa**, não faça nada.

---

# 14. Resultado final

Se o algoritmo retornar `TRUE`, teremos uma tabela consolidada de `ω` e `π`, representando as menores distâncias encontradas e seus respectivos predecessores.

Se retornar `FALSE`, significa que existe um **ciclo de peso negativo alcançável a partir da origem**, impedindo a existência de um caminho mínimo finito para os vértices afetados.

---

# 15. Complexidade

A complexidade de tempo do Bellman-Ford é:

$$
O(V \times A)
$$

onde:

- `V` = número de vértices.
- `A` = número de arestas.

Também pode ser escrita como:

$$
O(VE)
$$

quando `E` representa o número de arestas.

---

# 16. Limitações

A principal desvantagem é a velocidade.

Ele é significativamente mais lento que algoritmos como Dijkstra na maioria dos casos em que não existem pesos negativos.

Sua principal vantagem é justamente permitir **arestas com peso negativo** e detectar **ciclos de peso negativo alcançáveis a partir da origem**.

---

# 17. Erros comuns

- Esquecer a verificação extra da última iteração, que é utilizada para detectar ciclos de peso negativo.
- No teste de mesa, relaxar arestas fora da ordem estrita determinada pela lista enumerada.
- Esquecer que as atualizações acontecem **imediatamente** durante a varredura.
- Confundir `ω[v]` (distância) com `π[v]` (predecessor).
- Continuar usando um valor antigo depois que ele já foi atualizado durante a mesma iteração.
- Esquecer que o laço principal executa exatamente $n-1$ vezes.

---

# 18. Relação com outros algoritmos

## Com Dijkstra

O Dijkstra não funciona corretamente com arestas de peso negativo.

O Bellman-Ford, por outro lado, permite arestas negativas e também consegue detectar ciclos de peso negativo alcançáveis a partir da origem.

| Algoritmo | Pesos negativos | Detecta ciclo negativo | Ideia principal |
|---|---|---|---|
| **Dijkstra** | Não | Não | Escolha gulosa do próximo vértice |
| **Bellman-Ford** | Sim | Sim | Relaxamento repetido de todas as arestas |

A complexidade do Bellman-Ford é:

$$
O(VE)
$$

Enquanto a complexidade do Dijkstra depende da estrutura de dados utilizada. Com fila de prioridade e representação adequada, uma forma comum é:

$$
O((V+E)\log V)
$$

---

## Com BFS

Em grafos onde todas as arestas possuem custo unitário (peso `1`) ou quando o objetivo é encontrar o menor número de arestas, a BFS e o Bellman-Ford podem encontrar as mesmas distâncias mínimas.

A diferença está na mecânica:

- **BFS:** utiliza uma fila e explora o grafo por camadas.
- **Bellman-Ford:** testa todas as arestas repetidamente.
- **BFS:** é mais adequada para grafos sem pesos ou com peso unitário.
- **Bellman-Ford:** é necessária quando existem pesos negativos e não existem ciclos negativos alcançáveis a partir da origem.

---

# 19. Exercícios da lista relacionados

- Replicar a etapa de verificação para encontrar ciclos negativos no papel.
- Fazer um teste de mesa respeitando rigorosamente a ordem das arestas.
- Identificar quais valores de `ω` e `π` são alterados em cada iteração.
- Identificar se o grafo possui um ciclo de peso negativo alcançável a partir da origem.

## 20. Checklist para prova
- [ ] Sei que a repetição deve ocorrer $n-1$ vezes.
- [ ] Crio a tabela com a ordem exata das arestas ditada pela prova.
- [ ] Sei atualizar a tabela realizando a fórmula de relaxamento linha por linha.
- [ ] Após as $n-1$ rodadas, lembro de fazer mais uma rodada completa testando a linha 11 do pseudocódigo.
- [ ] Sei demonstrar analiticamente o ciclo negativo (Ex: `-4 > -5 → FALSE`).


[Próximo](11_FLOYD_WARSHALL.md)
