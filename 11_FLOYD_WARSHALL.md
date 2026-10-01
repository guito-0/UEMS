# 11_FLOYD_WARSHALL.md

# Algoritmo de Floyd-Warshall

## 1. O que é
É um algoritmo que calcula os caminhos mais curtos entre **todos os pares** de vértices de um grafo direcionado e ponderado[cite: 86].

## 2. Para que serve
Para obter uma matriz consolidada que responde diretamente a menor distância entre qualquer ponto A e qualquer ponto B do grafo simultaneamente[cite: 86]. 

## 3. Em qual tipo de grafo é utilizado
Grafos direcionados e ponderados que eventualmente possuam arestas com pesos negativos, mas que **não** possuam ciclos de custo negativo[cite: 86].

## 4. Ideia intuitiva
O algoritmo utiliza uma abordagem parecida com a de relaxação, mas em três dimensões. Ele compara todos os caminhos possíveis entre os vértices `i` e `j` utilizando um vértice intermediário (ponte) `k` (sendo $k=1...n$)[cite: 87].

## 5. Analogia
Imagine que você tem uma tabela direta de voos entre cidades. O algoritmo passa cidade por cidade `k` e pergunta: "Se eu usar a cidade `k` como escala, o voo entre as cidades `i` e `j` fica mais barato do que o voo direto ou da escala que eu já conheço?". Ele reescreve a tabela inteira a cada nova cidade testada como escala.

## 6. Conceitos necessários antes de estudar
*   Noções de Matrizes.
*   Inicialização matricial ALL-SOURCES[cite: 88].

## 7. Variáveis utilizadas pela professora
*   `ω[i,j]`: Valor do caminho mais curto entre os vértices `i` e `j`[cite: 87].
*   `π[i,j]`: Predecessor no caminho mais curto[cite: 87].
*   `k`: O vértice avaliado como intermediário na iteração atual[cite: 89].

## 8. Pseudocódigo original da professora

```text
INITIALIZE ALL-SOURCE (V, A, w)
1. para cada vértice i em V
2.     para cada vértice j em V
3.         ω[i,j] = w[i,j]
4.         se ω[i,j] < ∞ então
5.             π[i,j] = i
6.         senão
7.             π[i,j] = ⊥

FLOYD-WARSHALL (V, A, w)
1. INITIALIZE ALL-SOURCES (V, A, w)
2. para cada vértice k em V
3.     para cada vértice i em V
4.         para cada vértice j em V
5.             se ω[i,j] > ω[i,k] + ω[k,j]
6.                 ω[i,j] = ω[i,k] + ω[k,j]
7.                 π[i,j] = k
```

## 9. Pseudocódigo traduzido para linguagem simples
*   **A rotina de inicialização:** Preenche a matriz de distâncias copiando diretamente os pesos que estão no desenho do grafo. Se houver uma linha direta entre dois pontos, anota-se que o pai de `j` é `i`. Se não houver linha direta, coloca-se infinito e pai nulo.
*   **O loop triplo de Floyd-Warshall:**
    *   O laço mais externo seleciona o vértice `k` como "ponto de parada" (intermediário).
    *   Os laços internos `i` e `j` varrem todas as posições da matriz.
    *   A verificação central (Linhas 5-7): "O valor que eu tenho agora para ir de `i` até `j` é maior (mais caro) do que ir de `i` até `k` e depois de `k` até `j`?". Se sim, atualize o custo com essa nova soma, e atualize o pai `π[i,j]` para passar por `k`.

## 10. Como executar manualmente
1. Desenhe as matrizes `ω` e `π` preenchidas com os custos diretos.
2. Defina o primeiro vértice `k=s`.
3. Varra as linhas e colunas cruando `ω[i,j]` contra a soma `ω[i,k] + ω[k,j]`. Se for menor, substitua `ω` e atualize `π`.
4. Mude o intermediário `k` para o próximo vértice (ex: `t`) e repita a varredura usando os valores atualizados na matriz.
5. Siga até todos os vértices terem servido como `k`.

## 11. Teste de mesa — método da professora
A professora exige a representação visual dupla das matrizes Vértice x Vértice para `ω` e `π` a cada iteração individual, declarando explicitamente a matemática aplicada para cada posição que muda.   

**Exemplo de notação exigida nos cálculos (Slide 9):**
$k = s$
$i = s$
$j = s$
$\omega[i,j] > \omega[i,k] + \omega[k,j]$
$\omega[s,s] > \omega[s,s] + \omega[s,s]$

**Estrutura das matrizes (exemplo):**

| Vértices | s | t | u |
| :--- | :--- | :--- | :--- |
| **s** | 0 | 8 | 5 |
| **t** | 3 | 0 | ∞ |
| **u** | ∞ | 2 | 0 |

## 12. Exemplo completo passo a passo
(Ver [Aula 9, slides 90 a 124] para treinar as transposições matriciais com as arestas $s \rightarrow t (8)$, $s \rightarrow u (5)$, etc). Dica de prova: As linhas e colunas correspondentes ao índice do intermediário `k` atual nunca se alteram durante aquele passo `k`.   

## 13. Como saber qual decisão tomar em cada passo
Olhe fixamente para os valores de $\omega[i,k]$ e $\omega[k,j]$. Some-os. Se for menor que a célula $\omega[i,j]$ atual, faça a troca.

## 14. Resultado final
Duas matrizes consolidadas: $\omega$ com as distâncias mínimas exatas de qualquer lugar para qualquer lugar, e $\pi$ pronta para guiar o caminho passo a passo.

## 15. Complexidade
**Tempo:** $\Theta(\vert{}V\vert{}^3)$ (três laços de repetição aninhados varrendo os vértices).   

## 16. Limitações
A complexidade cúbica é muito pesada computacionalmente, tornando-o proibitivo para grafos extremamente grandes.

## 17. Erros comuns
Ignorar a diagonal principal. Durante a execução, caso haja valores negativos na diagonal principal da matriz `ω`, isso atesta a presença de um ciclo de custo negativo.   

## 18. Relação com outros algoritmos
É a versão "Todos contra Todos" (All-Sources) em oposição ao Dijkstra e Bellman-Ford (Single-Source). Tipicamente mais rápido que múltiplas execuções do Dijkstra em grafos densos.   

## 19. Exercícios da lista relacionados
(Testar a implementação que verifica se existe um ciclo negativo).   

## 20. Checklist para prova
- [ ] Sei montar a matriz base de INITIALIZE ALL-SOURCES.
- [ ] Sei que a repetição tripla é composta pelos loops `k`, `i` e `j`.
- [ ] Sei aplicar a soma de relaxação matricial `ω[i,j] > ω[i,k] + ω[k,j]`.
- [ ] Sei reescrever a matriz `π` registrando o vértice `k`.
- [ ] Lembro de verificar ciclos negativos através da observação de valores negativos gerados na diagonal principal da matriz `ω`.