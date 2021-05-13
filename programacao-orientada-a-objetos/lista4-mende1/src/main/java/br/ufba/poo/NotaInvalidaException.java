package br.ufba.poo;

public class NotaInvalidaException extends RuntimeException {

    public NotaInvalidaException () {
        super("Nota invalida!");
    }
}
