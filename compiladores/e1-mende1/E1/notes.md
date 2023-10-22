# Minhas notas sobre o exercício

Copiei o código flex do livro na página 3 para o arquivo `mywc.l`

Passei pelo flex e compilei o arquivo C para um executável `mywc`:

```bash
flex mywc.l
cc lex.yy.c -o mywc -lfl
```

Rodei o meu executável com entrada o arquivo `mywc.l` para a saída `mywc.output` através do comando:

```bash
./mywc < mywc.l > mywc.output
```

E também o executável `wc` do linux com entrada o arquivo `mywc.l` para a saída `mywc.output` através do comando:

```bash
wc < mywc.l >> mywc.output
```

Gerando o `mywc.output`:

```
# output do meu ./mywc
      20      35     283
 
# output do wc do linux 
 20  49 283
```

E com o mesmo estilo dos comando acima, fiz o mesmo procedimento com o arquivo `README.md`, gerando o resultado `README.output`:

```
# output do meu ./mywc
      20     204    1101

# output do wc do linux 
  20  192 1101
```

## Por que há a diferença entre as entradas?

Pois o programa copiado do livro para o arquivo `mywc.l` não usa a mesma implementação que o comando `wc` do Linux utiliza, como mesmo explicado no livro.
O programa `mywc.l` usa os padrões:
```
[a-zA-Z]+   { words++; chars += strlen(yytext); }
\n          { chars++; lines++; }
.           { chars++; }
```

Enquanto o `wc` do Linux utiliza os padrões:
```
[^ \t\n\r\f\v]+   { words++; chars += strlen(yytext); }
```

Substituindo em meu novo programa `mywc-linux.l`, obti os outputs iguais esperados:

### mywc-linux.output:
```
      20      49     283
 20  49 283
```

### README-linux.output:
```
      20     192    1101
  20  192 1101
```

Resultados esperados.

---
