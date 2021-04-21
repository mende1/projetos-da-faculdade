package br.ufba.poo.philmes;

public class FilmeLancamento extends Filme {

    public FilmeLancamento(String titulo) {
        super(titulo);
    }

    @Override
    public int getPreco() {
        return 5;
    }

    @Override
    public int getPrazo() {
        return 1;
    }
}
