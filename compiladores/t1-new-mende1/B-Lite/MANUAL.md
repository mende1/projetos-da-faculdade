# B-Lite

A linguagem B-Lite é uma linguagem de programação adaptada da linguagem B- (usada para o ensino de compiladores em cursos de graduação). 

B-Lite inclui expressões, fluxo de controle básico, funções recursivas e 
verificação de tipos. O código-objeto é compatível com C e, portanto, 
algumas bibliotecas C padrão podem ser usadas para os tipos definidos na linguagem.

Descreveremos a linguagem através de exemplos, deixando para você ler com atenção, fazer perguntas no Fórum e então extrair as especificações formais necessárias para desenvolver os trabalhos do curso.

## Aspectos Léxicos

### 1. Caracteres de espacejamento (_whitespace_)

Os caracteres de espacejamento são _blank_ (' '), _newline_ ('\n'),  _tab_ ('\t') e _carriage return_ ('\r').

Os caracteres de espacejamento não têm papel significativo em programas B-Lite 
e devem ser desconsiderados pelo analisador léxico.

### 2. Comentários de uma linha

Comentários de uma linha (_single-line comments_) sempre são iniciados por ```//``` e se estendem até o final da linha.
Comentários devem ser desconsiderados.

- Exemplo: ```a=5; // comentário no estilo C++```

### 3. Identificadores

Identificadores são usados como nomes de variáveis e funções. 
São compostos por letras maiúsculas e minúsculas, dígitos decimais e _underscores_.
Identificadores devem começar com uma letra e podem ter até 256 caracteres.
Caracteres maiúsculos e minúsculos em identificadores são diferenciados.

- Exemplo: ```i x9 x9_ my_str name4you  NomeCompleto``` são identificadores válidos. 
- Exemplo: ```x9``` e ```X9``` são dois identificadores distintos.

### 4. Palavras-chave (_keywords_)

```
boolean  else  false  function  if   integer  
print  return  string   true   void   while
``` 

As palavras-chave, sempre escritas em letras minúsculas, são reservadas 
e não podem ser usadas como identificadores. 

- Exemplo: ```integer``` é palavra reservada, porém  ```IntegeR``` não é.

Três palavras reservadas representam tipos da linguagem:

```integer```, ```boolean ```, e ```string```

### 5. Símbolos especiais

#### Símbolos simples

```
  +  -  *  /  %  !  <  >  =  : ; ,  (  )  {  } "
```

#### Símbolos compostos

```
  <=  >=  ==  !=  &&  ||
```

### 6. Literais 

#### Tipo ```integer```

Uma constante inteira é uma sequência não-vazia de dígitos decimais.

#### Tipo ```boolean```

Há duas constantes válidas para o tipo ```boolean```: ```false``` e ```true```.

#### Tipo ```string```

Uma constante do tipo string é uma sequência de caracteres entre aspas duplas,
terminada por NULL e que não pode ser modificada.

Uma string pode conter os seguintes códigos de ```\```:
```\n```, indica avanço de linha (valor ASCII 10) e ```\0```, indica NULL (valor ASCII zero). 
Uma barra invertida seguida por outro caracter representa o caractere que a segue. 
Uma string pode ter até 256 caracteres.
Uma string não pode ser iniciada em uma linha e fechada em outra, por exemplo:
```
"hello
hello"
```

### 6. Erros Léxicos

- símbolo desconhecido
- string mal-formada

### Exemplos

```
x: integer;
y: integer = 123;
b: boolean = false;
s: string  = "hello world\n";
```

```
x: integer = 65;
y: boolean = true;
if(x?y) ... etc. // símbolo desconhecido
```

```
f: integer = 0;
if(f<100) ...  etc.
```

```
writenum: function void ( b: integer );
a: integer = 99;
s: string  = "hello world; // string mal-formada
writenum(a); 
```

```
s: string  = "hello 
              world";  // string mal-formada
main: function integer () = {
    i: integer = 10;
    while (i > 0) ... etc.  
}
```


