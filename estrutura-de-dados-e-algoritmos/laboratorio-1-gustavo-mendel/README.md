[![Work in Repl.it](https://classroom.github.com/assets/work-in-replit-14baed9a392b3a25080506f3b7b6d57f295ec2978f6f33ec97e36a161684cbe9.svg)](https://classroom.github.com/online_ide?assignment_repo_id=3203369&assignment_repo_type=AssignmentRepo)
# Lab 1

## Analise de Complexidade 

### Estudo de Casos 1 - Algoritmos de Busca

Nesse Laboratório vamos tentar analise a complexidade de algoritmos diferentes que abordam o mesmo problema: **Busca**. 

A partir do programa base fornecido pelo professor, voces devem: 

1) Analise o código fonte. Garanta que entende por completo o seu funcionamento e as estruturas da linguagem C++ utilizas antes de prosseguir. Em caso de dúvida, solicite esclarecimentos ao professor/monitor pelo [Discord](https://discord.gg/Aqnd2f)

2) O programa apresenta uma função:

```
bool buscaSeq(std::vector<int> v, int k)
```

  que deverá implementar o algoritmo de **busca sequencial** pela chave `k` em um vetor `v` . Voce deve codificar essa função, que retorna 'true' caso a chave `k` seja encontrada em `v`, e `false` caso contrário.
  
3) Teste sua função executando um loop controlado e sorteando chaves randomicamente para serem passadas para a função. 

4) Analise a complexidade do seu algoritmo.

5) Inclua um controle de número de comparações do algoritmo. Novamente verifique se os valores de melhor caso, pior caso e caso médio batem com a complexidade teórica do algoritmo. 

6) Implemente uma nova função de busca que promova uma **busca binária** no mesmo vetor original. Conforme visto na aula, lembre-se de que esse algoritmo pressupõe que o vetor esteja ordenado. Voce pode utilizar, como apresentado em sala, o algoritmo 'sort' da **STL**.

7) Analise a complexidade do seu algoritmo.

8) Assim como no item 5) e 6) faça uma analise empírica do comportamento da sua função testando o número de comparações do melhor caso, pior caso e caso médio. 

9) Faça uma analise geral do comportamento dos dois algoritmos para vetores de tamanho realmente grande. Perceba a diferença entre os valores de comparações nesses casos e os compare com os resultados teóricos. 
