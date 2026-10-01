# 14_KRUSKAL.md

# Algoritmo de Kruskal

## 1. O que é
É um algoritmo guloso proposto em 1956 por Joseph Bernard Kruskal Jr. para encontrar a Árvore Geradora Mínima (AGM).

## 2. Para que serve
Para montar a rede mais barata sem focar na ordem dos vértices.
**Aplicações Práticas**[cite: 24]:
*   Transporte aéreo (mapa de conexões de voo).
*   Transporte terrestre (rodovias com menor uso de material).
*   Redes de computadores (fibra ótica) e Telefonia[cite: 25].
*   Circuitos integrados e Análise de clusters.

## 3. Em qual tipo de grafo é utilizado
Grafos ponderados, voltado para a formação de árvores independentes (floresta) que se interligam.

## 4. Ideia intuitiva
Inicialmente, cada vértice é uma árvore independente (floresta isolada). A cada iteração, procura-se a aresta global de "menor peso" que conecte duas árvores diferentes. Os vértices unidos passam a ser a mesma árvore. Isso é processado por $n-1$ iterações[cite: 8, 9]. O processo termina quando todos fazem parte de uma mesma árvore[cite: 9].

## 5. Analogia
Imagine ter várias casinhas isoladas em um mapa de condomínio[cite: 25]. Em vez de partir a rua central de um lugar só, você pede cotação de todas as ruas de ligação do condomínio. Você constrói a mais barata. Depois constrói a segunda mais barata, e assim vai. O único cuidado é: se duas casas já dão a volta e se conectam, você não constrói rua entre elas porque seria desperdício (ciclo).

## 6. Conceitos necessários antes de estudar
*   [Árvore Geradora Mínima (AGM)](12_ARVORE_GERADORA_MINIMA_AGM.md).
*   União em conjuntos (Union-Find).

## 7. Variáveis utilizadas pela professora
*   `H`: Vetor de arestas, ordenadas de acordo com os pesos (Crescente)[cite: 10].
*   `T`: Conjunto de arestas que define a árvore geradora mínima[cite: 10].
*   `U`: União em conjuntos[cite: 10].
*   `n`: Número de iterações necessárias ($n-1$)[cite: 8].

## 8. Pseudocódigo original da professora

```text
Kruskal(V, A, w)
1  Ordene as arestas em ordem crescente de pesos w_ij no vetor H;
2  T ← h_1
3  i ← 2, j ← 1;
4  enquanto j < n - 1 faça
5      se T ∪ h_i é um grafo acíclico então;
6          T ← T ∪ h_i
7          j ← j + 1;
8      fimse
9      i ← i + 1;
10 fimenquanto
11 fim
```

## 9. Pseudocódigo traduzido para linguagem simples
*   **Linha 1:** Coloque TODAS as arestas numa lista `H` ordenada da mais barata para a mais cara.
*   **Linha 2-3:** Como o primeiro item da lista já é o mais barato e não tem perigo de ciclo, coloque ele direto no resultado `T`. Configure contadores.
*   **Linhas 4-5:** Fique descendo a lista de arestas `H`. Para cada aresta nova, faça a pergunta de ouro: "Se eu colocar essa aresta no meu resultado `T`, ela forma um ciclo de caminhos fechados?".
*   **Linhas 6-8:** Se for seguro (grafo acíclico), abrace a aresta e some o contador `j`.
*   **Linha 9:** Se não for seguro, pule a aresta rejeitada (`i = i + 1`) sem somar `j`. Vá para a próxima.

## 10. Como executar manualmente
1. Crie uma tabela extraindo as arestas do desenho ordenadas do menor peso para o maior. Essa etapa é obrigatória para começar.   
2. Acompanhe o vetor ordenado item por item.
3. Teste se as pontas do vértice de `h_i` já estão na mesma árvore.
4. Registre explicitamente se a aresta entrará na árvore ou se será descartada.

## 11. Teste de mesa — método da professora
A professora exige que a extração do Vetor `H` ordenado fique listado visivelmente logo abaixo do algoritmo na folha.   

**Vetor H ordenado:**
`h1 - (u,x) = 1`
`h2 - (v,y) = 1`
`h3 - (w,x) = 2`
`h4 - (t,u) = 3`...   

**Exemplo do procedimento:**
A professora não faz as marcações analíticas completas, mas desenha em vermelho e cruza/exclui no vetor as arestas que formam ciclo.   

## 12. Exemplo completo passo a passo
(Siga o exercício resolvido do slide 23 a 34 da Aula 11 para notar a criação progressiva da árvore sem nós enraizados fixos).   

## 13. Como saber qual decisão tomar em cada passo
Teste de ciclo: olhe graficamente. A aresta nova liga duas ilhas separadas? Sim -> aprova. Ela amarra duas peças da mesma ilha grande? Sim -> Rejeita[cite: 9].

## 14. Resultado final
A Árvore Geradora Mínima graficamente estabelecida.   

## 15. Complexidade
(Não detalhada matematicamente nos slides fornecidos).

## 16. Limitações
A eficiência depende do pré-ordenamento das arestas.

## 17. Erros comuns
Errar a ordenação prévia do vetor `H` e estragar todo o resto do algoritmo por conta de um "guloso cego".   

## 18. Relação com outros algoritmos
O raciocínio de Kruskal está voltado para a inclusão de arestas. O algoritmo de Prim está voltado para a inclusão de vértices (crescendo gradualmente uma única árvore base)[cite: 8].

## 19. Exercícios da lista relacionados
Teste na linguagem C: Altere a implementação enviada para retornar o Custo total da AGM.   

## 20. Checklist para prova
- [ ] Lembro de ordenar TODAS as arestas antes de começar.
- [ ] Anoto a aresta `h_1` obrigatoriamente logo no começo.
- [ ] Sei avaliar visualmente a condição matemática $T \cup h_i$ (verificar se é acíclico).
- [ ] Descarto as arestas que formam ciclos fechados.