package br.ufba.poo.philmes;

public class FilmeInfantil extends Filme {

    public FilmeInfantil(String titulo) {
        super(titulo);
    }

    @Override
    public int getPreco() {
        return 4;
    }

    @Override
    public int getPrazo() {
        return 4;
    }
}
