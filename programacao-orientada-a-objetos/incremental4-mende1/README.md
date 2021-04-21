# Exercício incremental - parte 4

Você já reparou que `Retangulo` e `Rotulo` possuem muita coisa em comum? Continuando o exercício incremental 3, você vai usar mecanismos de programação orientada a objetos para reduzir a duplicação de código.

Crie uma classe `Componente`, e mova para essa classe todos os atributos e métodos comuns entre `Retangulo` e `Rotulo`, inclusive aqueles métodos que são implementados de forma diferente de uma classe para outra. Nesse caso, use o bom senso para escolher uma das implementações ou para deixar uma implementação vazia.

Reescreva a classe `Tela` de forma a não fazer referência às classes `Retangulo` e `Rotulo`. Você precisará implementar os métodos `addComponente()` e `getComponentes()`, em substituição aos métodos específicos de `Retangulo` e `Rotulo`.
