# POO - Lista 2 de Exercícios de Fixação

Para os exercícios a seguir, crie classes no pacote `br.ufba.poo`. Use boas práticas de programação orientada a objetos em Java.

## Contador

Crie uma classe `Contador`, com um método `getContagem()`, que retorna o número de vezes em que a classe foi instanciada.

## Pedido

Crie a classe `Pedido`, com os atributos `valor`, do tipo `double`, e `situacao`, do tipo `Situacao`, que pode receber os valores `PENDENTE`, `EM_ENTREGA` e `FINALIZADO`. Considere:

- Todo pedido é criado com a situação `PENDENTE`
- A situação pode ser atualizada, mas o valor não

## Aluno

Crie a classe `Aluno`, que possui os atributos `matricula` e `nome` (ambos do tipo `String`), além dos métodos e construtores relevantes de acordo com a seguinte especificação:

- O nome do aluno pode ser alterado, mas nunca o seu número de matrícula
- Duas instâncias de `Aluno` são consideradas iguais se possuem o mesmo número de matrícula

Assuma, para este exercício, que a classe `Aluno` sempre será instanciada com um número de matrícula e um nome válidos, passados nessa ordem.

## Conta

Crie uma classe `Conta` para representar uma conta bancária. Toda conta possui um código que a identifica, do tipo `String`, e um saldo, do tipo `double`. Ao criar uma conta, deve-se sempre informar o código e, opcionalmente, o saldo; se o saldo não for informado, ele deve ser zero. Ao movimentar dinheiro na conta, o saldo nunca deve ser negativo.

+ Considere que a classe deve possuir os seguintes atributos privados:
    - `double saldo`
    - `String codigo`
+ Considere que a classe deve possuir os seguintes métodos:
    - `boolean retira(double quantia)`: subtrai a quantia do saldo da conta, a menos que o saldo seja insuficiente (isto é, menor que a quantia). Retorna `true` se a quantia foi retirada, `false` caso contrário
    - `void deposita(double quantia)`: adiciona a quantia ao saldo da conta.
    - `boolean transfere(double quantia, Conta beneficiario)`: transfere a quantia da conta atual para a conta do beneficiário, a menos que o saldo da conta atual seja insuficiente (ou ainda se o parâmetro `beneficiario` for `null`). Retorna `true` se a transferência foi realizada, `false` caso contrário
