# 13_PRIM.md

# Algoritmo de Prim

## 1. O que é
É um algoritmo guloso proposto originalmente em 1930 e redescoberto por Robert C. Prim (1957) e Dijkstra (1959)[cite: 57]. 

## 2. Para que serve
Para determinar a Árvore Geradora Mínima (AGM) incluindo de forma gulosa, um a um, os vértices do grafo[cite: 57].

## 3. Em qual tipo de grafo é utilizado
Grafos conexos e ponderados.

## 4. Ideia intuitiva
O algoritmo parte de qualquer vértice do grafo. A cada passo, ele acrescenta a aresta de menor peso que está conectada aos vértices que já foram selecionados e cuja outra ponta chega em um vértice que ainda não foi selecionado[cite: 57]. 

## 5. Analogia
Imagine plantar uma raiz no chão que vai estendendo raízes em direção à água mais próxima. A raiz principal não solta pedaços isolados, ela cresce continuamente e interligada a partir dos galhos que já existem.

## 6. Conceitos necessários antes de estudar
*   [Árvore Geradora Mínima (AGM)](12_ARVORE_GERADORA_MINIMA_AGM.md)[cite: 54].
*   Noção de subtrações e uniões em conjuntos.

## 7. Variáveis utilizadas pela professora
*   `T_{min}`: Conjunto de arestas que define a árvore geradora mínima.
*   `T`: Conjunto dos vértices já selecionados pelo algoritmo[cite: 58].
*   `N`: Conjunto dos vértices não selecionados pelo algoritmo[cite: 58].
*   `\`: Subtração em conjuntos[cite: 58].

## 8. Pseudocódigo original da professora

```text
PRIM(V, A, w)
1.  Escolha qualquer vértice i ∈ V
2.  T ← {i}
3.  N ← V \ i
4.  T_{min} ← ∅
5.  enquanto |T| ≠ n faça
6.      Encontre a aresta {j, k} ∈ A tal que j ∈ T, k ∈ N e w_jk é mínimo;
7.      T ← T ∪ {k}
8.      N ← N \ {k}
9.      T_{min} ← T_{min} ∪ {j, k}
10. fim
```

## 9. Pseudocódigo traduzido para linguagem simples
*   **Linhas 1-4 (Inicialização):** Comece jogando o primeiro vértice `i` no conjunto dos capturados `T`. Todos os demais vértices ficam no conjunto dos "soltos" `N`. As arestas finais `T_{min}` começam vazias.
*   **Linha 5 (Loop):** Enquanto o número de capturados `|T|` não for igual ao total de vértices do grafo `n`, repita o bloco.
*   **Linha 6 (A busca gulosa):** Olhe para todas as cordas que amarram alguém de dentro de `T` a alguém de fora em `N`. Pegue a corda (aresta) que for mais barata.
*   **Linhas 7-9 (Captura):** Abrace o novo nó `k` movendo-o de `N` para `T`. Guarde a corda escolhida no seu pacote final `T_{min}`.

## 10. Como executar manualmente
Crie três espaços em branco na folha. Insira a raiz escolhida em `T`. Identifique todas as arestas tocando a raiz. Circule a menor. Puxe o destino para o grupo `T`. Agora procure as arestas que tocam TODOS os que estão em `T` e escolha a menor que vai para fora.

## 11. Teste de mesa — método da professora
A cada iteração, mostre a atualização dos conjuntos.   

**Exemplo Inicial (Raiz = s):**
`T = {s}`
`N = {t, u, v, w, x}`
`T_{min} = {}`   

**Primeira Escolha (Menor aresta saindo de s é para u com peso 1):**
`T = {s, u}`
`N = {t, v, w, x}`
`T_{min} = {(s, u)}`   

*(Siga acompanhando a progressão dos vértices sendo chupados do conjunto N para o conjunto T).*

## 12. Exemplo completo passo a passo
Treine com o grafo da [Aula 10, slides 71 a 79], partindo do vértice `s`. O resultado esperado para os conjuntos finais é:
`T = {s, t, v, u, w, x, y}`
`N = {}`
`T_{min} = {(s, t), (t, v), (s, u), (u, w), (w, x), (w, y)}`   

## 13. Como saber qual decisão tomar em cada passo
Basta olhar as extremidades ativas (conjunto `T`). Quais arestas partem delas para vértices que ainda estão em `N`? Compare os pesos e pegue o menor.   

## 14. Resultado final
O conjunto `T_{min}` guardará as arestas de custo global mais barato que conseguem tocar todos os nós sem realizar laços[cite: 58].

## 15. Complexidade
(Depende estritamente da implementação em C).

## 16. Limitações
A árvore é construída sempre de forma anexada e contínua, não permitindo processamento assíncrono de florestas separadas (como o Kruskal faz).

## 17. Erros comuns
Esquecer de analisar as arestas dos nós capturados anteriormente. A fronteira cresce! As arestas válidas são as de todos os nós que estão em `T`.

## 18. Relação com outros algoritmos
O raciocínio de Prim está voltado para a inclusão de vértices um a um na árvore. O Kruskal está voltado para a inclusão de arestas a partir da lista global.   

## 19. Exercícios da lista relacionados
(Teste de código em C): Altere o algoritmo C fornecido para retornar o custo total da AGM somado.   

## 20. Checklist para prova
- [ ] Sei criar os conjuntos `T`, `N` e `T_{min}` vazios.
- [ ] Pego o menor caminho `w` entre um vértice capturado `j ∈ T` e um livre `k ∈ N`.
- [ ] Subtraio o vértice `k` de `N`.
- [ ] Continuo iterando até o tamanho de `T` ser igual a `n`.


[Próximo](14_KRUSKAL.md)