package br.ufba.poo;

import com.googlecode.lanterna.TextColor;

import br.ufba.myterminal.MyTerminal;

public class Rotulo extends Componente {

    private String texto;

    public Rotulo (String texto) {
        this.texto = texto;
        this.origem = new Ponto(0, 0);
        this.corDeFrente = TextColor.ANSI.WHITE;
        this.corDeFundo = TextColor.ANSI.BLACK;
    }

    public Rotulo (Ponto origem, String texto) {
        this.origem = origem;
        this.texto = texto;
        this.corDeFrente = TextColor.ANSI.WHITE;
        this.corDeFundo = TextColor.ANSI.BLACK;
    }

    public Rotulo (String texto, TextColor corDeFrente, TextColor corDeFundo) {
        this.texto = texto;
        this.origem = new Ponto(0, 0);
        this.corDeFundo = corDeFundo;
        this.corDeFrente = corDeFrente;
    }

    public Rotulo (Ponto origem, String texto, TextColor corDeFrente, TextColor corDeFundo) {
        this.origem = origem;
        this.texto = texto;
        this.corDeFundo = corDeFundo;
        this.corDeFrente = corDeFrente;
    }

    public String getTexto() {
        return texto;
    }

    public void setTexto(String texto) {
        this.texto = texto;
    }

    @Override
    public void desenha (MyTerminal terminal) {

        TextColor corAnteriorFrente = terminal.getForegroundColor();
        TextColor corAnteriorFundo = terminal.getBackgroundColor();

        terminal.setPosition(origem.getX(), origem.getY());

        terminal.setForegroundColor(corDeFrente);
        terminal.setBackgroundColor(corDeFundo);

        terminal.println(texto);

        terminal.setForegroundColor(corAnteriorFrente);
        terminal.setBackgroundColor(corAnteriorFundo);
    }
}
