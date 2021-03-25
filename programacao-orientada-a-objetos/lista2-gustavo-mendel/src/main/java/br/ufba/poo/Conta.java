package br.ufba.poo;

public class Conta {
    
    private String codigo;
    private double saldo;

    public Conta ( String cod ) {
        this.codigo = cod;
        this.saldo = 0;
    }

    public Conta ( String cod, double valor ) {
        this.codigo = cod;
        this.saldo = valor;
    }

    public String getCodigo () {
        return codigo;
    }

    public double getSaldo () {
        return saldo;
    }

    public boolean retira ( double quantia ) {

        if (this.saldo >= quantia) {

            this.saldo -= quantia;
            return true;
        }

        return false;
    }

    public void deposita ( double quantia ) {
        this.saldo += quantia;
    }

    public boolean transfere ( double quantia, Conta beneficiario ) {

        if (beneficiario != null) {

            if (this.saldo >= quantia) {

                this.saldo -= quantia;
                beneficiario.deposita(quantia);

                return true;
            }
        }

        return false;
    }
}
