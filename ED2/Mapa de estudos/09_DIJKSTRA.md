# 09_DIJKSTRA.md

# Algoritmo de Dijkstra

## 1. O que é
É um algoritmo que encontra o menor caminho entre um vértice de origem e todos os demais vértices em um grafo ponderado.

## 2. Para que serve
Para calcular rotas de menor custo em aplicações práticas, como encontrar o menor caminho entre cidades em um mapa de rodovias[cite: 213].

## 3. Em qual tipo de grafo é utilizado
Grafos orientados ou não orientados, ponderados **somente com pesos positivos** (não possuem ciclos de peso negativo).

## 4. Ideia intuitiva
O algoritmo é estruturalmente semelhante à Busca em Largura (BFS)[cite: 223]. Ele calcula a menor distância do vértice inicial aos seus vizinhos, depois dos vizinhos aos seus próprios vizinhos, e assim sucessivamente, atualizando as distâncias sempre que descobre uma menor através da técnica de relaxamento[cite: 223].

## 5. Analogia
Imagine estar em uma cidade e ir marcando definitivamente a distância mais curta para os bairros vizinhos. A cada bairro que você chega com certeza absoluta da menor rota, você olha para as ruas saindo dele para ver se encontra atalhos para bairros ainda não fechados.

## 6. Conceitos necessários antes de estudar
*   [Vetores de estimativa e predecessor](08_CAMINHOS_MINIMOS_CONCEITOS.md)[cite: 215].
*   Técnica de **Relaxamento**[cite: 217].

## 7. Variáveis utilizadas pela professora
*   `S`: Conjunto de vértices cuja menor caminho para a raiz já é conhecida (definitiva)[cite: 224].
*   `V - S`: Vértices em que o menor caminho conhecido ainda é uma estimativa (provisória)[cite: 224].
*   `Q`: Uma fila de prioridade mínima de vértices com o menor caminho provisório[cite: 224].
*   `ω[v]`: Estimativa atual do custo do caminho da origem até `v`[cite: 215].
*   `π[v]`: Predecessor de `v` no caminho[cite: 215].

## 8. Pseudocódigo original da professora

```text
DIJKSTRA (V, A, w, s)
1.  para cada vértice v em V
2.      ω[v] = ∞
3.      π[v] = ⊥
4.  ω[s] = 0
5.  S ← {}
6.  Q ← V
7.  enquanto Q não está vazia faça
8.      u ← EXTRACT_MIN(Q)
9.      S ← S ∪ {u}
10.     para cada vértice v em Adj[u] faça
11.         se ω[v] > ω[u] + w(u,v) então
12.             ω[v] = ω[u] + w(u,v)
13.             π[v] = u
```

## 9. Pseudocódigo traduzido para linguagem simples
*   **Linhas 1-4:** Prepara todos os vértices definindo a distância `ω` como infinito (`∞`) e o pai `π` como nulo (`⊥`). A distância do ponto de partida `s` para ele mesmo é 0.
*   **Linhas 5-6:** O conjunto de vértices resolvidos `S` começa vazio. Todos os vértices do grafo são colocados na fila de prioridade `Q`.
*   **Linhas 7-9:** Enquanto a fila `Q` não estiver vazia, tire de lá o vértice `u` que tiver o menor valor de distância `ω` (usando `EXTRACT_MIN`). Coloque esse vértice `u` no grupo dos resolvidos `S`.
*   **Linhas 10-13:** Olhe todos os vizinhos diretos de `u`. Faça o teste de relaxamento: a distância atual do vizinho é maior que a distância de `u` somada ao peso da rua entre eles? Se for, achamos um atalho! Atualize a distância `ω` do vizinho e diga que agora o pai `π` dele é `u`.

## 10. Como executar manualmente
1. Inicialize a tabela com a origem valendo `0` e o restante `∞`[cite: 216].
2. Olhe a fila `Q` e escolha o vértice com o menor `ω`. Passe-o para o conjunto `S`.
3. Verifique as arestas que saem desse vértice para vizinhos que ainda estão em `Q`.
4. Aplique a fórmula do relaxamento: se for mais barato chegar no vizinho por essa aresta, atualize o custo `ω` do vizinho e marque quem foi o vértice pai `π`.   
5. Repita até a fila `Q` ficar vazia.   

## 11. Teste de mesa — método da professora
A professora exige que os conjuntos `S` e `Q` sejam acompanhados a cada iteração, juntamente com a atualização matricial dos vetores `ω` e `π`.   

**Tabela de Exemplo:**

| Vértice | a | b | c | d | e | f | g | h |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **ω** | 0 | 4 | 3 | ∞ | ∞ | ∞ | ∞ | ∞ |
| **π** | ⊥ | a | a | ⊥ | ⊥ | ⊥ | ⊥ | ⊥ |

`S = {a}`
`Q = {b, c, d, e, f, g, h}`
   
## 12. Exemplo completo passo a passo
(Para praticar, use os valores gerados na [Aula 7, slides 227-254], atualizando a tabela com a extração sucessiva dos nós com menor `ω`).   

## 13. Como saber qual decisão tomar em cada passo
Utilize a operação `EXTRACT_MIN(Q)`: sempre olhe apenas para os vértices presentes na lista `Q` e escolha aquele que tiver o menor número anotado na linha `ω`.   

## 14. Resultado final
Os vetores `ω` contendo as distâncias mínimas exatas de `s` para todos os vértices e `π` permitindo reconstituir os caminhos traçando os predecessores[cite: 215].

## 15. Complexidade
**Tempo:** $O((A + V) \log V)$ (Dependendo da estrutura usada para a fila de prioridade).   

## 16. Limitações
Funciona somente em grafos com pesos positivos[cite: 223]. Falha completamente se houver ciclos de peso negativo.   

## 17. Erros comuns
Tentar aplicar o algoritmo em redes que possuem modelagem de prejuízo financeiro (arestas negativas). Nesses casos, o Dijkstra irá falhar.   

## 18. Relação com outros algoritmos
O Dijkstra é essencialmente idêntico estruturalmente à Busca em Largura (BFS)[cite: 223], porém projetado para lidar com arestas de pesos variáveis.
Enquanto o Dijkstra resolve uma única fonte em $O((A + V) \log V)$ para pesos $\ge 0$, o Bellman-Ford resolve em $O(V \times A)$ aceitando pesos negativos.   

## 19. Exercícios da lista relacionados
Pratique extrair o caminho mínimo analisando os vetores no formato exigido pela professora.

## 20. Checklist para prova
- [ ] Sei inicializar `ω` e `π`.
- [ ] Sei administrar os conjuntos `S` e `Q`.
- [ ] Sei selecionar o nó com a operação `EXTRACT_MIN(Q)`.
- [ ] Sei aplicar a fórmula de relaxamento `ω[v] > ω[u] + w(u,v)`.
- [ ] Sei preencher a tabela iterativa acompanhando a evolução dos vetores a cada nó fechado.

[Próximo](10_BELLMAN_FORD.md)