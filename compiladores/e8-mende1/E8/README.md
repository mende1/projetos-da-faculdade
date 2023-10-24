# Exercício E8 (2023.2) - Individual

__Atenção__: 
Este exercício tem como objetivo implementar com Bison e ações semânticas em C, um avaliador para uma linguagem de expressões aritméticas.
Para uma expressão aritmética sintaticamente correta, constrói a árvore sintática abstrata (AST),  
percorre a AST a partir da sua raiz, avaliando seus nós,
e mostra o resultado da expressão da saída padrão. 
Em caso de erro sintático, a mensagem "syntax error" deve mostrada na saída padrão.

## Especificação

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

Lembre-se de que a pasta de trabalho é ```E8```.

- Usar o arquivo lex.cc.o (cuidado para não apagar);
- Adaptar E8/main.c para chamar a função ```int expr_evaluate```, com argumento do tipo ```struct expr *e```  
para percorrer a AST gerada e mostrar o resultado da expressão; 
em caso de erro sintático, mostrar a mensagem de ```syntax error```;
- Utilizar o arquivo E8/e8.y para colocar a sua gramática livre de contexto com ações semânticas;
- Copiar (adaptar, se necessário) o código para manipulação de AST para expressões mostrado no capítulo 5 do livro do Douglas Thain 
(ver Seção 5.4 - Expression Trees);
- Os arquivos de teste estão na pasta ```E8/tests```. 

### Execução e teste

Ao executar o analisador, 
todos os testes disponibilizados ```E8/tests``` devem passar (PASS).
O analisador deve reconhecer expressões sintaticamente válidas,
interpretá-las e mostrar o resultado na saída padrão ou
reportar a mensagem ```syntax error```.

#### Em sua máquina (local)

_Obs._: Teste localmente antes de subir sua resposta para o servidor.

- Para executar apenas, faça um```make compile``` ,
execute ```./avalia``` e digite uma expressão aritmética.
- Para testar o analisador com os testes fornecidos, 
faça um ```make compile``` seguido por um ```make test```;

#### No servidor (remoto)
- Quando fizer o ```push``` para subir a sua resposta,
todos os testes na pasta ```\tests``` serão executados.
Clique em ```details``` para ver os resultados.


## Entrega

Arquivos-fonte no GitHub.
Programa bison ```E8/e8.y```, contendo uma gramática livre de contexto não-ambígua com regras de produção para o avaliador de expressões,
```E8/main.c``` modificado e arquivos ```E8/ast.h``` e ```E8/ast.c``` para manipulação de AST para expressões aritméticas.





