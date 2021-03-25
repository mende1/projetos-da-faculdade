# Exercício incremental - parte 2

Agora você criará classes no pacote `br.ufba.poo` para representar um ponto, um retângulo e um rótulo. Use o bom senso e as convenções de codificação da linguagem Java para nomear classes, atributos e métodos. Por exemplo, o ponto deve ser descrito em uma classe chamada `Ponto`. Observe os textos em negrito no texto: eles podem indicar atributos das classes.

## Ponto

Um ponto possui duas coordenadas, ambas inteiras: **x** e **y**. Ao se criar um ponto, necessariamente as duas coordenadas devem ser informadas. 

Um ponto deve ser imutável: após criado, não deve ser permitido alterar suas coordenadas.

A classe deve possuir um método, `comDeslocamento(dx, dy)`, que retorna o ponto resultante do deslocamento do ponto atual em `dx` unidades na coordenada x e `dy` unidades na coordenada y.

Implemente os métodos necessários para permitir que dois pontos sejam comparados através dos métodos `equals` e `hashCode`.

## Rótulo

Um rótulo representa uma linha de **texto** que pode ser desenhada no terminal, em um determinado ponto de **origem**, com determinadas cores (**cor de fundo** e **cor de frente**).

Ao se criar um rótulo, as seguintes informações podem ser passadas, nesta ordem:

- origem (opcional; por padrão, o ponto `(0, 0)`)
- texto (obrigatório)
- cor de frente e cor de fundo (opcional; por padrão possuem os valores `TextColor.ANSI.WHITE` e `TextColor.ANSI.BLACK`, respectivamente)

A origem, o texto e as cores podem ser consultados ou alterados a qualquer momento.

O método `desenha(MyTerminal terminal)` é responsável por desenhar o texto no terminal (sem chamar `terminal.draw()`). Ao terminar de executar, esse método deve restaurar as cores (de frente e de fundo) que estavam definidas no terminal antes do início da execução do método.

## Retângulo

Um retângulo representa um retângulo que pode ser desenhado no terminal, preenchido por um **caractere** (que pode ser configurado), usando uma **cor de frente** e uma **cor de fundo**.

Há duas formas de se criar um retângulo:

- passando uma **origem** (canto superior esquerdo) e um **canto oposto** (canto inferior direito);
- passando uma **origem** (canto superior esquerdo), uma **largura** e uma **altura** (ambos inteiros).

Dica: você não precisa armazenar simultaneamente canto oposto e largura/altura. Uma informação pode ser calculada a partir da outra.

Por padrão o caractere é o `#`. As cores padrão são as mesmas definidas para rótulos.

O método `desenha(MyTerminal terminal)` é responsável por desenhar o retângulo no terminal (sem chamar `terminal.draw()`). Ao terminar de executar, esse método deve restaurar as cores (de frente e de fundo) que estavam definidas no terminal antes do início da execução do método. Exemplo de retângulo com 4 unidades de largura e 2 unidades de altura, usando o caractere 'X':

```
XXXX
XXXX
```

O retângulo deve responder à mensagem `desloca(int dx, int dy)`, que desloca a origem do retângulo em `dx` unidades na coordenada x e `dy` unidades na coordenada `y`, preservando as suas dimensões.

Além disso, o retângulo deve responder à mensagem `redimensiona(int largura, int altura)`, que altera as duas dimensões do retângulo, preservando a sua origem.

Todas as características do retângulo podem ser consultadas ou alteradas a qualquer momento através de métodos apropriados.
