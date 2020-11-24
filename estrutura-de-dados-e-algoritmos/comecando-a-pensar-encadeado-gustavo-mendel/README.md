[![Work in Repl.it](https://classroom.github.com/assets/work-in-replit-14baed9a392b3a25080506f3b7b6d57f295ec2978f6f33ec97e36a161684cbe9.svg)](https://classroom.github.com/online_ide?assignment_repo_id=3416083&assignment_repo_type=AssignmentRepo)
# Começando A Pensar de Forma Encadeada

## Objetivos:

- Reforçar o conceito de Tipo Abstrato de Dados (TAD);
- Compreender de forma prática o conceito de encadeamento;
- Implementar, em linguagem C++, o conceito de encadeamento, em uma estrutura de dados baseada em arranjo (vetor);

## Conceitos básicos:

A implementação do TAD `VetorDin` é baseada no fato de que as relações de precedência e sucessão dos elementos são resolvidas pela estrutura de armazenamento do arranjo, ou seja, há a presunção de que elementos consecutivos ocupam posições consecutivas na memória.

No entanto, tal fato faz com que operações com a de `remoção` de um elemento necessitem movimentar todos os elementos restantes, a partir da posição do elemento removido, para que esse deixe de pertencer ao arranjo e as relações de precedencia e sucessão voltem a ter uma relação um para um com as posições dos elementos dentro do arranjo. 

Uma possibilidade para evitar esses movimentos de elementos dentro do arranjo é praticar o que se poderia chamar de uma `remoção lógica`. A idéia é que, diferentemente da `remoção fisica` implementada em aula, onde a posição do elemento removido é reutilizada de imediato por outro elemento do arranjo, a `remoção lógica` apenas marca aquela posição removida como *disponível*. Dessa forma, nenhuma movimentação de elementos do arranjo é necessária. 

Se por um lado a operação de `remoção` se torna mais simples e com menor custo computacional, todas as demais operações deverão ser ajustadas a essa nova possibilidade. Entre as várias questões que se colocam com a `remoção lógica` podemos citar:

1. Como sinalizar que um elemento do arranjo está removido lógicamente? 
2. Como inserir novos elementos aproveitando as posições removidas lógicamente? 
3. Como manter o controle dos limites do arranjo? Ou seja, os elementos iniciais/finais do arranjo já não terão uma relação direta com os indices inicial e mais a direita do arranjo.  

### Seu trabalho:

1. Analise a questão 1) apresentada acima e proponha mudanças na estrutura da classe e/ou na função de `remoção` que possibilitem a `remoção lógica` das chaves armazenadas na classe `cVetorDin`;
2. Resolvida a questão da `remoção lógica` avalie como essa mudança influência os demais métodos da classe `cVetorDin`, considerando as questões colocadas nos itens 2) e 3) acima. 
3. Modifique e teste se sua solução para o método de `remoção lógica` funciona de forma adequada;

### Desafios:

Implemente outros métodos na classe `cVetorDin`, tais como: 

1. Inserir elementos no inicio do vetor;
2. Inserir elementos de forma ordenada dentro do vetor (essa operação não ordena o vetor, mas presume que ele é um vetor ordenado desde a sua criação, e, portanto, leva isso em conta para incluir um novo elemento em sua posição correta na estrutura.);
3. Considerando que possa haver repetição dos elementos no vetor: 
* Busca e retorna o número de ocorrências de um dado do vetor;
* Remove todas as ocorrencias de um dado do vetor.

## Referência Bibliográfica:

Varsha H. Patil, **Data Structures using C++**, OUP India, 2012.

