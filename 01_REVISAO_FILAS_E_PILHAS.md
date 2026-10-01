# Revisão: Filas e Pilhas

## 1. Filas (Queues)
Uma Fila é uma sequência de elementos onde o primeiro a entrar é o primeiro a sair (regra FIFO - *First In, First Out*)[cite: 2].

*   **Para que serve:** Gerenciamento de tarefas, e, no contexto de grafos, é a estrutura fundamental para a **Busca em Largura (BFS)**.
*   **Operações Básicas:** Criação, Inserção no final, Remoção no início, Consulta do início e Destruição[cite: 2].
*   **Alocação Estática:** Usa arrays. Exige definição do número máximo (`MAX`). O índice `final` avança de forma circular usando resto da divisão: `fi->final = (fi->final + 1) % MAX;`[cite: 2].
*   **Alocação Dinâmica:** Usa ponteiros (`prox`). O nó descritor contém ponteiros para o `início` e `final`[cite: 2].

## 2. Pilhas (Stacks)
Uma Pilha é um tipo especial de lista onde inserções e exclusões ocorrem apenas no início/topo (regra LIFO - *Last In, First Out*)[cite: 2].

*   **Para que serve:** Avaliação de expressões matemáticas, recursão e, no contexto de grafos, é a estrutura fundamental (implícita via recursão ou explícita) para a **Busca em Profundidade (DFS)**[cite: 2, 6].
*   **Alocação Estática:** O elemento entra e sai na posição do vetor indicada pelo índice `qtd`[cite: 2].
*   **Alocação Dinâmica:** Usa nó descritor que aponta para o `Topo`. A inserção/remoção manipula diretamente este ponteiro[cite: 2].

Relaciona-se com:
- [Busca em Largura (BFS)](05_BUSCA_EM_LARGURA_BFS.md) (Utiliza Filas)
- [Busca em Profundidade (DFS)](06_BUSCA_EM_PROFUNDIDADE_DFS.md) (Utiliza Pilhas)