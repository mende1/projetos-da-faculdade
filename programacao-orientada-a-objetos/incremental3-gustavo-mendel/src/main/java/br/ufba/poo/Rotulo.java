package br.ufba.poo;

import br.ufba.myterminal.MyTerminal;
import com.googlecode.lanterna.TextColor;

public class Rotulo {

    private Ponto origem;
    private String texto;
    private TextColor corDeFrente;
    private TextColor corDeFundo;

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

    public Ponto getOrigem() {
        return origem;
    }

    public String getTexto() {
        return texto;
    }

    public TextColor getCorDeFrente() {
        return corDeFrente;
    }

    public TextColor getCorDeFundo() {
        return corDeFundo;
    }

    public void setOrigem(Ponto origem) {
        this.origem = origem;
    }

    public void setTexto(String texto) {
        this.texto = texto;
    }

    public void setCorDeFrente(TextColor corDeFrente) {
        this.corDeFrente = corDeFrente;
    }

    public void setCorDeFundo(TextColor corDeFundo) {
        this.corDeFundo = corDeFundo;
    }

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
