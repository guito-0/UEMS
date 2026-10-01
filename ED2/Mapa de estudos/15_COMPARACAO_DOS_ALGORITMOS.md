# 15_COMPARACAO_DOS_ALGORITMOS.md

# Comparação entre Algoritmos de Caminhos Mínimos

Uma das tabelas comparativas definitivas fornecidas pela disciplina sumariza a aplicação, os custos e as restrições dos algoritmos clássicos de caminhos mínimos[cite: 129]:

|  | Dijkstra | Bellman-Ford | Floyd-Warshall |
| :--- | :--- | :--- | :--- |
| **Complexidade de tempo** | $O((A+V)\log V)$ ou $O(A+V \log V)$ | $O(V \times A)$ | $O(V^3)$ |
| **Única fonte** | Sim | Sim | Não |
| **Todas as fontes** | Sim | Não | Sim |
| **Aresta negativa** | Não | Sim | Sim |
| **Ciclo negativo** | Falha | Identifica | Identifica |

### Notas Extras
*   **Floyd-Warshall** é tipicamente mais rápido que executar múltiplas vezes o Dijkstra, caso se queira testar a rota a partir de "todas as fontes"[cite: 129].
*   Na presença de prejuízos ou custos sob taxa cambial negativa, **Bellman-Ford** ou **Floyd-Warshall** devem ser escolhidos em detrimento do Dijkstra[cite: 135].


[Próximo](16_IMPLEMENTACOES_EM_C.md)