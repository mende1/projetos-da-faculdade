[![Work in Repl.it](https://classroom.github.com/assets/work-in-replit-14baed9a392b3a25080506f3b7b6d57f295ec2978f6f33ec97e36a161684cbe9.svg)](https://classroom.github.com/online_ide?assignment_repo_id=3535839&assignment_repo_type=AssignmentRepo)
# Atividade - Listas Encadeadas - As Variantes

Conforme vimos nas últimas aulas, *Listas Simplesmente Encadeadas - LSE* são o tipo mais simples de lista baseada em encadeamentos. Nesse tipo de lista os nos armazenam apenas as relações de sucessão, ou seja, apenas um apontador para o próximo elemento. 

Uma variante bastante comum as *LSEs* são as *Listas Duplamente Encadeadas - LDEs*, onde não só a relação de sucessão mas também a relação de predecessão. Portanto, seus nos possuem dois apontadores: um proximo e um anterior. A grande vantagem nesse tipo de lista é permitir que a movimentação na lista possa ser feita em duas direções, para frente e para tras. No entanto, as operações agora precisam gerenciar de maneira consistente mais apontadores. 

Outra variante da *LSE* são as *Listas Circulares - LCs*. Como o próprio nome indica, em uma *LC* o ultimo elemento da lista aponta para o primeiro no da lista, formando assim um ciclo fechado. Em várias situações práticas, como as listas de processos em um sistema operacional *time-sharing* mantem listas circulares para repetir os processos em um laço contínuo. 

Claramente as operações básicas de qualquer lista encadeada são as mesmas: Inserir, Remover, Buscar, Listar, etc. Porém seus algoritmos são diferentes, em função do lista esta sendo implementada.

Nessa atividade sua tarefa será criar dois Tipos Abstratos de Dados que implementem uma *LDE* e uma *LC*, e dois programas que testem suas operações. Esses programas de testes devem ser capazes de receber seus dados via arquivos, cujos nomes serão fornecidos pelo usuário na chamada do programa. Para facilitar considere que as informações dos nos são valores inteiros. 

Após codificação e teste, analise a complexidade das listas construídas, comparando-as com as *LSE*. Faça uma breve analise das vantagens e desvantagens que voce detectou na implementação das operações básicas de cada lista encadeada. 

***Importante: Edite o arquivo README.md para colocar as informações suas (seu nome completo) e sobre seu trabalho (a analise dos algoritmos e informações relevantes). Verifique também os itens que serão pontuados para não perder pontos. Forneça um Makefile para a compilação dos seus programas de teste.***
