package br.ufba.poo;

public class Pedido {
    
    private double valor;
    private Situacao situacao;

    public Pedido ( double valor ) {

        this.valor = valor;
        this.situacao = Situacao.PENDENTE;
    }

    public double getValor() {
        return valor;
    }

    public Situacao getSituacao() {
        return situacao;
    }

    public void setSituacao ( Situacao sit ) {
        situacao = sit;
    }
}
