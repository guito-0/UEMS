# 08_CAMINHOS_MINIMOS_CONCEITOS.md

# Conceitos Básicos de Caminhos Mínimos

## 1. O Problema
Muitas vezes, não basta saber a menor distância em "saltos" entre dois vértices, queremos saber o **menor caminho** considerando custos[cite: 213]. Para isso, utilizamos grafos ponderados[cite: 214].

## 2. A Função de Peso
O grafo possui uma função de peso $w: A \rightarrow \mathbb{R}$ (mapeando as arestas em valores reais)[cite: 214]. Para um caminho $p = (v_0, v_1, ..., v_k)$, o seu peso total $w(p)$ é o somatório dos pesos de todas as suas arestas[cite: 214]:
$w(p) = \sum_{i=1}^{k} w(v_{i-1}, v_i)$[cite: 214]

## 3. Vetores Auxiliares
Dado um grafo com vértices $V = \{1, 2, ..., n\}$, os algoritmos de caminho mínimo utilizam dois vetores fundamentais:
*   `ω[1...n]`: Guarda uma estimativa do menor caminho entre a fonte `s` e cada vértice `i`[cite: 215].
*   `π[1...n]`: Guarda o predecessor (pai) de cada vértice `i` no menor caminho de `s` até `i`[cite: 215].

## 4. Inicialização (Initialize-Single-Source)
Antes de qualquer busca, as estimativas e os predecessores são inicializados.

```text
Initialize-Single-Source (V, A, s)
1. para cada vértice v em V
2.     ω[v] = ∞
3.     π[v] = ⊥
4. ω[s] = 0
```

## 5. Relaxamento (Relax)
Técnica utilizada pelos algoritmos de Dijkstra e Bellman-Ford. Relaxar uma aresta $(u, v)$ significa testar se é possível melhorar o caminho mínimo atual até o vértice `v` passando através de `u`.   

```text
Relax (u, v, w)
1. se ω[v] > ω[u] + w(u,v) então
2.     ω[v] = ω[u] + w(u,v)
3.     π[v] = u
```