# Exercício incremental - parte 3

Continuando o exercício incremental 2, agora você vai criar uma nova classe, `br.ufba.poo.Tela`. Além disso, você vai implementar um tratamento de erros simples na classe `br.ufba.poo.Retangulo`.

Você vai precisar copiar as classes que você criou no incremental 2 para este projeto.

Use o bom senso e as convenções de codificação da linguagem Java para nomear classes, atributos e métodos. 

## Retangulo

Vamos introduzir uma nova regra: o canto oposto do retângulo pode ser igual à origem, ou pode representar o canto inferior direito do retângulo. Se, no entanto, o canto oposto for um ponto à esquerda ou acima da origem, deve ser lançada uma exceção do tipo `IllegalArgumentException`, com a mensagem `"Dimensoes invalidas"` (assim mesmo, sem acento).

**Atenção**: você vai precisar fazer esse tratamento em vários pontos da sua classe.

## Tela

Você deve criar uma classe `Tela`, que contém um conjunto de retângulos e rótulos.

`Tela` deve implementar os seguinte métodos:

- `addRetangulo(retangulo)` - adiciona um retângulo à tela
- `addRotulo(rotulo)` - adiciona um rótulo à tela
- `getRetangulos()` - retorna uma coleção de retângulos
- `getRotulos()` - retorna uma coleção de rótulos
- `desenha(MyTerminal terminal)` - apaga o conteúdo do terminal e desenha os retângulos e os rótulos. Tanto os retângulos quanto os rótulos devem ser desenhados na ordem em que foram adicionados, de forma que retângulos ou rótulos podem sobrescrever outros retângulos ou rótulos inseridos anteriormente. Você pode desenhar todos os retângulos, depois todos os rótulos, ou vice-versa (isso não é definido na especificação).

Tome cuidado para não vazar referências: o cliente da classe Tela não deve poder modificar diretamente as coleções de retângulos e de rótulos (isso só pode ser feito a partir dos métodos `add*`). O cliente deve poder, no entanto, modificar os próprios retângulos e rótulos que estão na tela.

