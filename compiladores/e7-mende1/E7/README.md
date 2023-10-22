# Exercício E7 (2023.2)

__Atenção__: 
Este exercício tem como objetivo implementar com Bison
e ações semânticas  um interpretador para uma linguagem de expressões aritméticas, mostrando o resultado da expressão.

## Especificação

Escrever um programa Bison com uma gramática livre de contexto para 
expressões aritméticas e ações semânticas para interpretá-las.
Expressões válidas incluem números inteiros não-negativos,
e operações de adição, subtração e multiplicação com tais números (não incluir divisão).
As expressões aritméticas podem conter parênteses: ```( e )```.

#### Exemplos

- Entradas e saídas correspondentes:

```
6 * 8 + 2 - 3 - 4 * 5      27
40 * 5 + 1                 201
(1099 + 7) * 54            59724
60 2 - 3                   syntax error
7112 * (12341 + 8090       syntax error
576 * * 89                 syntax error
2 - 3 - 4 * 5              -21
```

### Arquivos

Lembre-se de que a pasta de trabalho é ```E7```.

- Adaptar o arquivo E7/e7.l para converter o lexema de NUMBER em um valor inteiro; 
- Adaptar E7/main.c para reportar resultado ou mensagem de "syntax error";
- Utilizar o arquivo E7/e7.y para colocar a sua  gramática livre de contexto com ações semânticas.
- Os arquivos de teste estão na pasta ```E7/tests```. 

### Execução e teste

Ao executar o analisador, 
todos os testes disponibilizados ```E7/tests``` devem passar (PASS).
O analisador deve reconhecer expressões sintaticamente válidas,
interpretá-las e mostrar o resultado na saída padrão ou
reportar a mensagem "syntax error".

#### Em sua máquina (local)

_Obs._: Teste localmente antes de subir sua resposta para o servidor.

- Para executar apenas, faça um```make compile``` ,
execute ```./interpreta``` e digite uma expressão aritmética.
- Para testar o analisador com os testes fornecidos, 
faça um ```make compile``` seguido por um ```make test```;

#### No servidor (remoto)
- Quando fizer o ```push``` para subir a sua resposta,
todos os testes na pasta ```\tests``` serão executados.
Clique em ```details``` para ver os resultados.


## Entrega

No GitHub.
Programa bison E7/e7.y contendo uma gramática livre de contexto não-ambígua com regras de produção para o interpretador de expressões ("interpreta"), arquivos E7/e2.l e E7/main.c modificados.





