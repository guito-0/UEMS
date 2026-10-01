# 10_BELLMAN_FORD.md

# Algoritmo de Bellman-Ford

## 1. O que é
É um algoritmo para caminhos mínimos que examina todos os vértices de um grafo orientado repetidas vezes por iteração, até que atualizações não sejam mais possíveis[cite: 137].

## 2. Para que serve
Para calcular caminhos mínimos em cenários que necessitam de arestas com peso negativo[cite: 135].
**Aplicações reais:**
*   Movimentações financeiras com lucros ou prejuízos (uso de câmbio)[cite: 135].
*   Um taxista que gasta combustível rodando vazio (prejuízo) vs rodando cheio (lucro)[cite: 135].
*   Entregador cruzando um pedágio caro[cite: 135].
*   Energia gerada e consumida em reações químicas[cite: 135].

## 3. Em qual tipo de grafo é utilizado
Grafos orientados ponderados com **arestas de peso negativo**[cite: 137].

## 4. Ideia intuitiva
Ao invés de fechar um vértice definitivamente por iteração (como o Dijkstra), ele processa relaxamentos em todo o grafo. Em um grafo com $n$ vértices, qualquer caminho ótimo tem no máximo $n-1$ arestas. Por isso, cada vértice é examinado no máximo $n-1$ vezes[cite: 137].

## 5. Analogia
Você repassa as estimativas de distâncias sobre todas as estradas repetidas vezes, permitindo que a propagação da informação sobre rotas negativas percorra todo o mapa em até $n-1$ "ondas" de atualização. Se após essas ondas os valores ainda continuarem diminuindo, é porque você encontrou um poço sem fundo (um ciclo negativo infinito).

## 6. Conceitos necessários antes de estudar
*   [Relaxamento](08_CAMINHOS_MINIMOS_CONCEITOS.md)[cite: 217].
*   Ciclos de peso negativo.

## 7. Variáveis utilizadas pela professora
*   `ω[v]`: Estimativa do caminho.
*   `π[v]`: Predecessor.
*   **Ordem das arestas:** É crucial para o teste de mesa da professora. A lista de arestas é avaliada em uma ordem estritamente definida.

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

## 9. Pseudocódigo traduzido para linguagem simples
*   **Linhas 1-4:** Prepara todos os nós com distância `ω = ∞` e pai `π = ⊥`. A distância do vértice inicial `s` recebe 0.
*   **Linha 5:** Inicia um super-loop que se repetirá $n-1$ vezes (onde $n$ é a quantidade total de nós).
*   **Linhas 6-9:** Dentro do super-loop, ele varre a lista completa de todas as arestas. Faz a checagem clássica de relaxamento: "A distância atual para $v$ é pior que a distância para $u$ somada ao custo da aresta de $u$ até $v$?". Se sim, ele atualiza `ω[v]` e anota `π[v] = u`.
*   **Linhas 10-12:** A fase de auditoria. Ele varre as arestas mais uma vez inteira. Se, mesmo depois de rodar tudo $n-1$ vezes, ele ainda achar uma aresta que permite diminuir o custo de um nó, significa que há um ciclo infinito sugando o peso para o negativo. O algoritmo devolve FALSE avisando do erro.   
*   **Linha 13:** Se a fase de auditoria passou limpa, o caminho mínimo é validado e retorna TRUE.

## 10. Como executar manualmente
1. Anote a ordem das arestas que a professora exigiu.   
2. Inicie a tabela zerando a origem e setando os demais como infinito.
3. Desça a lista de arestas verificando o relaxamento de forma rigorosamente sequencial. Atualize a tabela na hora.
4. Repita a descida na lista de arestas o número de vezes igual ao total de vértices menos 1 ($n-1$).
5. Faça uma última descida na lista. Se algum cálculo der menor, decrete falha por ciclo negativo.

## 11. Teste de mesa — método da professora
A professora define a "Ordem das arestas" explicitamente e preenche os vetores `ω` e `π` com os resultados a cada passagem completa pelo conjunto de arestas.   

**Exemplo de layout base exigido:**

**Ordem das arestas:**
$1^a$: `e→f` | $2^a$: `b→e` | $3^a$: `a→c` | $4^a$: `b→c` | $5^a$: `a→b` | $6^a$: `c→e` | $7^a$: `c→f`

| Vértice | a | b | c | e | f |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **ω** | 0 | 4 | 3 | 6 | 9 |
| **π** | ⊥ | a | a | c | c |

Se houver ciclo negativo, mostrar a verificação na Etapa de verificação (linhas 5-7) explicitamente. Exemplo: `bc` -> `ω(c) > ω(b) + w(b,c)` -> `-4 > 3 + (-8)` -> `-4 > -5` -> `FALSE`.   

## 12. Exemplo completo passo a passo
(Para treinar, monte a tabela seguindo a evolução visual exibida na [Aula 8, slides 144 a 170]).   

## 13. Como saber qual decisão tomar em cada passo
Diferente de algoritmos gulosos, você não toma decisões ativas escolhendo caminhos. Você é forçado a percorrer a lista inteira de arestas na ordem pré-definida e apenas checar a fórmula de relaxamento cegamente.   

## 14. Resultado final
Uma tabela consolidada de `ω` e `π` se retornar `TRUE`. Se retornar `FALSE`, fica provada a impossibilidade da solução por conta de ciclos negativos.   

## 15. Complexidade
**Tempo:** $O(V \times A)$ (onde V são vértices e A são arestas).   

## 16. Limitações
A principal desvantagem é a velocidade. Ele é significativamente mais lento do que o Dijkstra e do que o Floyd-Warshall na maioria dos casos comuns.

## 17. Erros comuns
*   Esquecer a verificação extra da última iteração, que é a única forma de atestar ciclos negativos[cite: 138].
*   No teste de mesa, relaxar arestas fora da ordem estrita determinada pela lista enumerada[cite: 144].

## 18. Relação com outros algoritmos
Ao contrário do Dijkstra que falha com arestas negativas e possui complexidade $O((A+V)\log V)$, o Bellman-Ford identifica ciclos negativos e funciona com arestas negativas a uma velocidade $O(V \times A)$.   

## 19. Exercícios da lista relacionados
(Replicar a Etapa de verificação para encontrar ciclos negativos no papel).   

## 20. Checklist para prova
- [ ] Sei que a repetição deve ocorrer $n-1$ vezes.
- [ ] Crio a tabela com a ordem exata das arestas ditada pela prova.
- [ ] Sei atualizar a tabela realizando a fórmula de relaxamento linha por linha.
- [ ] Após as $n-1$ rodadas, lembro de fazer mais uma rodada completa testando a linha 11 do pseudocódigo.
- [ ] Sei demonstrar analiticamente o ciclo negativo (Ex: `-4 > -5 → FALSE`).


[Próximo](11_FLOYD_WARSHALL.md)