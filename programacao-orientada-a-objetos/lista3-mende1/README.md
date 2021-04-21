# POO - Lista 3 de Exercícios de Fixação

Use boas práticas de programação orientada a objetos em Java.

## Gerenciador de conteúdo

Para este exercício, crie classes no pacote `br.ufba.poo.conteudo`.

Você e alguns colegas decidiram criar um sistema de gerenciamento de conteúdo para competir com o Wordpress. Neste momento, vocês estão discutindo como serão implementadas as principais classes desse sistema: `Conteudo`, `Pagina` e `Noticia`. Uma página possui **título**, **corpo** e **endereço**. Uma notícia possui **título**, **corpo**, **autor** e **data**. `Conteudo` é uma classe que generaliza `Pagina` e `Noticia`, possuindo os atributos comuns entre eles.

Todos os atributos serão privados, e cada classe deve possuir um único construtor, que recebe como parâmetros valores para todos os seus atributos (na ordem em que aparecem neste texto) e atribui os valores para os atributos correspondentes.

Crie as classes, os atributos e os construtores, usando herança para evitar código repetido. Crie também *getters* públicos para todos os atributos.

## Philmes

Para este exercício, crie classes no pacote `br.ufba.poo.philmes`.

A empresa Philmes anunciou um novo serviço de aluguel de filmes via *streaming*, com preços competitivos para o mercado brasileiro. 

Os lançamentos (filmes recém-lançados) custam R$ 5,00 e devem ser assistidos em até 24 horas. Já os filmes infantis custam R$ 4,00 e ficam disponíveis por 4 dias. Os demais filmes estão disponíveis por R$ 3,00 para assistir em um prazo de 2 dias.

Você ficou responsável por criar o programa que processa os pedidos de aluguel:

- A classe `Filme` deve possuir os métodos `getTitulo()`, que retorna uma `String`, `getPreco()`, que retorna um `int`, e `getPrazo()`, que retorna um `int` representando o número de dias em que o filme fica disponível para ser assistido. Além disso, você deve sobrepor o método `toString()` para retornar três informações separadas por ponto-e-vírgula: `título;preço;prazo`. Exemplo: `Titanic;3;2`.
- Você deve criar as classes `FilmeLancamento` e `FilmeInfantil`.
- Crie uma classe `CarrinhoDeCompras`, com os seguintes métodos:
  - `insereFilme(Filme filme)`: insere o filme no carrinho de compras
  - `getPrecoTotal()`: retorna a soma dos preços dos filmes que foram inseridos no carrinho (`int`)
  - `imprimeRecibo()`: imprime o retorno do método toString() de cada filme inserido, um filme em cada linha, na ordem de inserção. Seu código deve ser o seguinte: 

```java
for (Filme filme : filmes) {
  System.out.println(filme);
}
```

- Seu programa não deve usar a instrução `if`, operador ternário (`?:`) ou qualquer instrução condicional.
- Você deve usar os mecanismos de programação orientada a objetos para evitar duplicação de código.
- Sua classe `Filme` deve ter um único atributo, `titulo`. As classes `FilmeLancamento` e `FilmeInfantil` não devem possuir atributos. Use sobreposição para garantir que cada tipo de filme tenha preços e prazos diferentes.
- Seu programa deve funcionar com esse código:

```java
CarrinhoDeCompras carrinho = new CarrinhoDeCompras();
carrinho.insereFilme(new Filme("Titanic"));
carrinho.insereFilme(new FilmeInfantil("Big Hero 6"));
carrinho.insereFilme(new FilmeLancamento("Capita Marvel"));
carrinho.imprimeRecibo();
System.out.println(carrinho.getPrecoTotal());
/* Saída esperada:
	Titanic;3;2
	Big Hero 6;4;4
	Capita Marvel;5;1
	12
*/
```
