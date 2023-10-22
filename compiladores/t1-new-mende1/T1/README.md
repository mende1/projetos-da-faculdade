# Projeto de um Compilador

## Trabalho 1 (T1): Análise Léxica

Nesta parte do projeto, você irá implementar um analisador léxico
para a [linguagem B-Lite](../B-Lite/MANUAL.md).

O analisador léxico do trabalho T1 deve receber como entrada 
um programa fonte em B-Lite e retornar um sequência _tokens_, 
um a um, cada _token_ anotado com as seguintes informações:
- classe do _token_ (identificador, constante inteira, símbolo, etc)
- lexema do _token_ (cadeia de caracteres), 
no caso de identificadores e constantes inteiras.

Se uma entrada incorreta for encontrada, o analisador léxico 
retornar o token __ERROR__.
O analisador léxico deve reportar todos os erros léxicos presentes 
no programa fonte analisado, ou seja, após identificar e reportar o erro, 
a análise léxica deve prosseguir até o final do programa fonte.

## Classes de _tokens_

Em sua implementação do analisador léxico, considere as seguintes classes de _tokens_ da linguagem:

__ID__     Identificador

__NUM__    Literal decimal (inteiro)

__STR__    Literal string

__KEY__    Keyword (palavra-chave)

__SYM__    Símbolo especial simples

__SYMC__   Símbolo especial composto

__ERROR__  Erro léxico

Comentários e caracteres de espacejamento (_white space_) devem ser descartados durante a fase de análise léxica do compilador.

## Entrada

O analisador léxico deverá ler um arquivo de entrada (com extensão _.bm_),
contendo um programa fonte em B-Lite.

```
// main.bm 
main: function integer () =
{
    a: integer;
    read(a);
    if (a <= 0) 
       a = 1;
    print("saida: ",a);
}
```
 
## Saída 

O analisador léxico deve gerar um arquivo de saída (com extensão _.out_).
Para cada chamada do analisador léxico, a saída deve mostrar 
um _token_ e seus atributos, um _token_ por linha, 
no formato especificado a seguir:

```(line_num,token_class,"lexeme") ``` (_lexeme_ entre aspas)

onde ```line_num``` é o número da linha no arquivo de entrada 
em que  _token_ aparece,
 ```token_class``` é a classe do _token_ válido ou __ERROR__,  
no caso de erro léxico, e
```lexeme``` é o lexema disponibilizado pelo Flex na variável _yytext_,
reportado na saída entre aspas duplas.

Para o programa fonte em _main.bm_ (acima), 
a saída gerada em _main.out_ será:
```
(2,ID,"main")
(2,SYM,":")
(2,KEY,"function")
(2,KEY,"integer")
(2,SYM,"(")
(2,SYM,")")
(2,SYM,"=")
(3,SYM,"{")
(4,ID,"a")
(4,SYM,":")
(4,KEY,"integer")
(4,SYM,";")
(5,ID,"read")
(5,SYM,"(")
(5,ID,"a")
(5,SYM,")")
(5,SYM,";")
(6,KEY,"if")
(6,SYM,"(")
(6,ID,"a")
(6,SYMC,"<=")
(6,NUM,"0")
(6,SYM,")")
(7,ID,"a")
(7,SYM,"=")
(7,NUM,"1")
(7,SYM,";")
(8,KEY,"print")
(8,SYM,"(")
(8,STR,""saida: "")
(8,SYM,",")
(8,ID,"a")
(8,SYM,")")
(8,SYM,";")
(9,SYM,"}")
```

## Como executar

O nome do analisador léxico (executável) deve ser _blite_.
O programa _blite_ deve ler a entrada a partir de um arquivo 
com extensão _.bm_ e escrever a saída em outro arquivo,
preferencialmente com extensão _.out_.

Use o script ```run.sh``` para  executar _blite_ passando apenas
o nome do arquivo de entrada _.bm_. A saída será gerada em 
um arquivo com o mesmo nome e extensão  _.out_.

```
$ ./run.sh exemplo.bm    # cria exemplo.out
```

Para executar _blite_ sem o script, fornecer 
os nomes dos arquivos de entrada e de saída, explicitamente:

```
$ ./bison exemplo.bm exemplo.out
```

## Como testar

Use o script ```run_tests.sh```. 
Os testes fornecidos estão na pasta ```tests/inputs```.
Se quiser, crie outros testes nessa pasta.
O oráculo fornecido está na pasta ```tests/oracle```.

$ ./run_tests.sh  # roda os casos de testes em /tests

## Entrega

A entrega do T1 deve ser feita no repositório individual 
criado pelo GitHub Classroom. 
O repositório tem duas pastas, ```src``` e ```tests```.
A pasta _tests_ contém arquivos _.bm_ com programas em BLite.

Os arquivos na pasta _src_ são 
```blite.l```, ```blite.y``` e ```main.c```. 
Idealmente, você só deve modificar _blite.l_ 
para especificar seus padrões regulares e ações para
a análise léxica de  programas _BLite_ e, em seguida,
rodar ```run_tests.sh```.

_Não_ incluir outros arquivos na pasta _src_.

A entrega deverá ser feita em duas etapas:

- Entrega parcial (7 dias) 

Para acompanhamento: Subir uma versão incompleta de blite.l
com especificação de padrões e ações para desconsiderar caracteres 
de espacejamento e comentários, e para reconhecer 
identificadores (ID) e números (NUM).

- Entrega final (15 dias) 

Subir a versão completa do programa flex para BLite (```blite.l```)
com todos os padrões regulares e ações implementados. 

