package br.ufba.poo;

public class Par<T> {

    private T valor1;
    private T valor2;

    public Par (T valor1, T valor2) {
        this.valor1 = valor1;
        this.valor2 = valor2;
    }

    public void combina (Combinador<T> c) {
        this.valor1 = c.combina(this);
    }

    public void setValor1 (T valor) {
        this.valor1 = valor;
    }

    public void setValor2 (T valor) {
        this.valor1 = valor;
    }

    public T getValor1 () {
        return valor1;
    }

    public T getValor2 () {
        return valor2;
    }
}
