# Problema 0

## Análise do aluno
> Por Gustavo Mendel

***Banco de dados***

Foi feito um gerador de banco de dados de placas pedido pelo problema no padrão *Mercosul* - 4 letras e 3 números - ABC1D23.

O programa conta também com um verificador de placas iguais, para não ter o azar de geral placas repetidas, já que ocorria muito isso quando se tratava de grandes números de placas geradas, algo em torno de 10 mil ou 100 mil já ocorria bastante.

Então ao gerar as placas, guardamos tua string em um vetor com único intuito de analisar as repetições. Quando o programa gerar uma nova placa, ele vai percorrer todo este vetor e verificar se há ou não iguais. Caso haja, ele vai ignorar esta placa, voltar uma posição no loop, e gerar uma nova.

Este mecanismo deixou o gerador muito custoso quando se tratava de grandes quantidades de dados gerados, algo em torno de mil ou 10 mil placas, meu Linux bem otimizado com um hardware considerável gerava no mesmo instante. Quando aumentava para 100 mil, já percebemos o aumento para uns 30-40 segundos na minha máquina. Quando testei 1 milhão ficou praticamente inviável o gerador.

> Já que este não era o problema principal, ficou com esse algoritmo muito custoso mesmo, para poder ter um foco maior no que interessava.

Mas enfim, para gerar novas placas, vá no arquivo `src/sortAlg.h` e mude o valor da constante `TAMANHO` para a quantidade de placas desejada. Apenas com essa mudança todo o código, inclusive da ordenação, vai está preparada para entrar em ação com este novo valor. Feito isso, compile e execute o arquivo `src/gerarPlacas.cpp` ou simplesmente use o comando do Makefile que já deixei pronto, que ele vai fazer todo o trabalho:
```
make gerarPlacas
```
Que ele vai gerar o arquivo `placas.txt` na pasta database. Caso haja outro arquivo com o mesmo nome, ele será removido para o novo que será gerado.

---

Deixado claro sobre o banco de dados, vamos ao que interessa!

***A ordenação***

Se trata de um problema, no mínimo curioso e envolvente, o que foi pedido foi a ordenação de um arquivo de texto contendo uma quantidade de placas de automóveis geradas aleatoriamente e sem repetições, placas essas no padrão *Mercosul* se tratando do *patter* ABC1D23 - 4 letras e 3 números - e gerado um novo arquivo com a ordenação já feita.

Tal desafio foi no entanto bem desafiador e que gerou muitas noites em claro pesquisando algoritmos de ordenação e me perguntando qual deles seria o ideal. Existe sim muitos algoritmos para ordenação de strings, contendo caracteres e números - chamada de ordenação lexicográfica. Porém bem custos quando se tratava de grandes quantidades de dados.

A solução - sugerida também pelo professor, quando indicou a existência de **_algoritmos de ordenação em tempo linear_**. Que quando se tratava de grandes quantidades de dados - que era o propósito do problema - se saia muito bem.

---

***O Algoritmo***

Então, o escolhido foi um algoritmo que ordenava de acordo com cada digito da string, podendo ser números ou caracteres. O que era perfeito para nosso caso.

> Radix Sort

Ele ordena todo um vetor analisando seu digito menos significativo - aquele que em termos matemáticos seria o menos valioso - o digito mais a direita. Partindo daí, ordenando o vetor analisando digito a digito em cada passada, terminando no digito mais significativo, aquele mais a direita.

Utiliza também um algoritmo auxiliar para fazer a ordenação digito a digito, a `Ordenação por Contagem`, também em tempo linear, o que era perfeito.

O famoso `Counting Sort` considera que cada item do vetor é um inteiro entre `0 e K`. O algoritmo vai contar para cada digito quantas vezes ele aparece, e faz essa contagem em um vetor de tamanho `K`, adicionando o valor de 1 unidade na posição de seu próprio indície. A partir daí, com algumas manipulações de vetores e valores, ele faz um novo vetor já com os valores ordenados. Esta é a sua característica, ele é mais eficiente em termos de complexidade, porém exige mais espaço em máquina, por manter uma cópia do seu próprio vetor em memória.

O que o torna tão eficiente é que ele não faz verificações e comparações entre posições do vetor para fazer a ordenação, ele apenas faz uma contagem dos elementos, por um vetor de contagem auxiliar e a partir daí faz todo o trabalho.

Sua complexidade (CountingSort), seria de `O(n + K)`, K sendo o intervalo que ele considera, e n o tamanho do vetor. Fica melhor ainda quando `K = O(n)`, pois assim, sua complexidade final será de `O(n)` - o que é perfeito para nosso caso, já que vamos trabalhar com grandes quantidades de dados, que algoritmos não lineares não custosos com complexidade de `O(n.log n)`, ou então `O(n²)` teria muito mais dificuldade para tratar grandes quantidades.

Quando se juntam o Counting Sort e o Radix sort, temos o seguinte:

Para cada passada de digitos `d`, ele custará `O(n+K)`, como já visto antes. Quando considerado para todas as passadas temos algo em torno de `O(dn + dK)`, ou em evidência, `O(d(n+K))`. Ele terá custo constante quando d é constante, que é nosso caso já que sempre vamos analisar placas de 7 digitos, e também quando `K = O(n)`.

---

***Sobre a tabela ASCII***

Neste caso, teríamos que considerar até o *Z*, ja que precisamos analisar números de *0 - 9*, e letras maiúsculas de *A - Z*. O menor correspondente na tabela *ASCII* seria o *zero* `(048)`, e o maior a letra *Z* `(090)`. Toda a tabela *ASCII* tem ao todo 256 itens, poderiamos usar todo esse intervalo, porém o programa seria mais custoso, sendo que podemos reduzir ao analisar que só precisamos do intervalo de `0 (048) até Z (090)`, tendo um total de 42 de diferença.

Dito isso, teríamos então que considerar o intervalo de char `000 até 090` correto? Negativo. Considerando todos os char e reduzindo um valor de 48 deles, temos então o intervalo `000 - 042`, tendo em vista nosso intervalo original `048 - 090`, um total de **42** de diferença, que vamos aumentar em 1, ficando **43** nosso intervalo (por motivos de evitar um Segmentation Fault) de números analisados, ou K, reduzindo ao máximo o custo tendo em vista este caso em específico das placas.

Sendo assim, temos nossa ordenação feita, e após gerar as placas aleatoriamente com o comando make, podemos compilar e executar os arquivos `src/main.cpp e src/sortAlg.cpp`, ou então para facilitar, use o Makefile que já deixei pronto pra fazer todo o trabalho.
```
make
```

Após isso, será gerado o arquivo `database/dbsort.txt`, que contém todas as placas analisadas ordenadas perfeitamente.

---