[![Work in Repl.it](https://classroom.github.com/assets/work-in-replit-14baed9a392b3a25080506f3b7b6d57f295ec2978f6f33ec97e36a161684cbe9.svg)](https://classroom.github.com/online_ide?assignment_repo_id=3509606&assignment_repo_type=AssignmentRepo)
# Lista Simplesmente Encadeada baseada em Apontadores

O TAD *Lista Simplesmente Encadeada* representa uma estrutura de dados linear e sequencial, onde o elementos da estrutura, seus **nos**, armazenam informações e relações de sucessão entre os elementos. 

Conforme discutido na aula de 27/10, o uso de *alocação dinâmica* permite criar sob demanda (em tempo de execução) a área de memória que cada **nó** da estrutura irá ocupar. Da mesma forma, é possível desalocar os **nos** a qualquer momento durante a execução do programa. 

Com base na estrutura de classes apresentada na aula de 27/10 e reproduzida nesse repositório, voce deve tentar codificar o conjunto de operações básicas de um TAD *Lista Simplesmente Encadeada*: 
~~~
1. Inserir um novo nó;
  1.1 no final da lista;
  1.2 no inicio da lista;
2. Remover um nó;
3. Buscar uma chave na lista;
4. Imprimir o conteúdo da lista;
5. Construtor cópia de uma lista.
~~~
Após implementar essa operações básicas, tente implementar operações mais complexas como: 
~~~
1. Inserir, de forma ordenada, novos nos (nesse caso apenas esse tipo de inserção deve ser usado);
2. Concatenar duas listas (conectando o inicio da segunda lista ao final da primeira lista);
3. Dividir uma lista em duas, a partir de um certo nó (especificado por sua posição e/ou chave);
4. Misturar duas listas:
  4.1 Intercalando seus nos;
  4.2 Fusão dos nos (usado para listas ordenadas); 
5. Buscar todas as ocorrencias de uma chave (considerando a possibilidade de repetição);
6. Remover todas as ocorrencias de uma chave. 
~~~
