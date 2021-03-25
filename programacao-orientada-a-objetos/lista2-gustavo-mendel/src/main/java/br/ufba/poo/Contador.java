package br.ufba.poo;

public class Contador {
    
    private static int contador = 0;

    public Contador () {
        contador++;
    }

    public static int getContagem() {
        return contador;
    }
}
