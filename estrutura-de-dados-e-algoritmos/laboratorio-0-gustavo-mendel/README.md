[![Work in Repl.it](https://classroom.github.com/assets/work-in-replit-14baed9a392b3a25080506f3b7b6d57f295ec2978f6f33ec97e36a161684cbe9.svg)](https://classroom.github.com/online_ide?assignment_repo_id=3166338&assignment_repo_type=AssignmentRepo)
# Lab 0

## Analise de Complexidade 

### Estudo de Casos 0 - Exemplos da aula

Nesse primeiro Laboratório vamos tentar concretizar os exemplos de analise de funções de custo, testando na prática as funções vistas na ultima aula. 

A partir do programa base fornecido pelo professor, voces devem: 

1) Analise o código fonte. Garanta que entende por completo o seu funcionamento e as estruturas da linguagem C++ utilizas antes de prosseguir. Em caso de dúvida, solicite esclarecimentos ao professor/monitor pelo [Discord](https://discord.gg/Aqnd2f)

2) Sua primeira tarefa será codificar as 3 versões da função MaxMin analisadas na aula passada (dúvidas consulte os [slides da aula] (https://docs.google.com/presentation/d/12ZpCjS_s-ztEqvlsTdNiMqiPreSgvyYugQR74p4bH-U/edit?usp=sharing). 
   Um protótipo geral foi usado para definir as 3 funções no programa de teste, sem código e com retorno 0. Voce pode alterar esses protótipos para executar esse Lab. 
  
3) Uma vez codificadas as 3 funções, teste seu funcionamento, executando o programa com diferentes conjuntos de valores. As 3 funções devem retornar sempre os mesmo valores, correspondentes ao maior e menor valor daquele conjunto. 

4) Sabendo da teoria que os algoritmos podem ter melhor e pior caso, em função da organização dos dados de entrada, simule essas condições e confirme se há ou não variação no numero de comparações nos 3 algoritmos testados. 

5) Que tal agora fazer uma analise empírica do custo computacional das 3 implementações da função minMax()? 
   Modifique seu programa para que contabilize quantas comparações são efetuadas com os elementos do vetor em cada função.
   Apresente esse resultado juntamente com os valores encontrados de maior e menor elementos do conjunto. 
   
6) Para que a analise do comportamento assintótico do algoritmos seja melhor caracterizado empiricamente seria interessante executar uma bateria de testes com diversos conjuntos de numeros diferentes, e em quantidade razoavelmente grande de elementos. 
   Modifique seu programa para executar seus algoritmos várias vezes e faça uma analise estatistica do seu comportamento, calculando os  valores máximo, mínimo e medio (com desvio padrão) do numero de comparações do total de execuções. 
