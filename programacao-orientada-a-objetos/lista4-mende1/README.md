# POO - Lista 4 de Exercícios de Fixação

Use boas práticas de programação orientada a objetos em Java.
Crie classes no pacote `br.ufba.poo`.

## Alunos e notas inválidas

Crie uma exceção, `NotaInvalidaException`, que estende `RuntimeException`, cuja mensagem de erro é `"Nota invalida!"` (sem acento). Crie também um classe `Aluno`, com atributos `nome` (String) e `nota` (double), e um construtor público que recebe `nome` e `nota` (nessa ordem). Crie o construtor de forma que seja impossível instanciar objetos com uma nota inválida. Considere que uma nota só é válida se estiver entre `0.0` e `10.0`. Também deve ser impossível alterar a nota de um objeto `Aluno` após sua criação.

## Lista dobrada

Crie uma classe, `ListaDobrada`, que guarda uma lista de valores do mesmo tipo (especificado durante a instanciação) em um `ArrayList`. A diferença é que, ao adicionar um item, ele é inserido duas vezes na lista no final da lista. A classe deve conter os seguintes métodos (considere que `T` é o tipo dos elementos):

- `int obtemTamanho()`: retorna o número de elementos guardados na lista. Por exemplo, ao inserir dois elementos em uma lista vazia, `obtemTamanho()` deve retornar 4.
- `void insereElemento(T valor)`: insere o valor no final da lista duas vezes.
- `T obtemElemento(int i)`: retorna o valor armazenado no índice `i`; se o índice for inválido, deve retornar `null`.

## Par e Combinador

Crie uma classe `Par`, com dois atributos, `valor1` e `valor2`, do mesmo tipo genérico, juntamente com construtor, *getters* e *setters*. Crie também um interface, `Combinador<T>`, com um único método, `combina`, que recebe um par (do tipo `Par<T>`, onde `T` é um tipo genérico) e retorna um valor do tipo genérico `T`. Crie, na classe `Par`, um método `combina`, que recebe um combinador e chama o método `combina` do combinador passando a si próprio como parâmetro, e atribui o retorno do método `combina` ao atributo `valor1`.

Exemplo de código:

```java
Par<Integer> par = new Par<>(3, 5);
par.combina(new Combinador<Integer>() {
    public Integer combina(Par<Integer> p) {
        return p.getValor1() + p.getValor2();
    }
});
System.out.println(par.getValor1()); // 8
System.out.println(par.getValor2()); // 5
```