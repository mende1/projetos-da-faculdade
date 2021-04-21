package br.ufba.poo.philmes;

public class Filme {

    private String titulo;

    public Filme() {
    }

    public Filme (String titulo) {
        this.titulo = titulo;
    }

    public String getTitulo() {
        return titulo;
    }

    public int getPreco() {
        return 3;
    }

    public int getPrazo() {
        return 2;
    }

    @Override
    public String toString() {
        return titulo + ";" + getPreco() + ";" + getPrazo();
    }
}
