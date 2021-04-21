package br.ufba.poo;

import com.googlecode.lanterna.TextColor;

import br.ufba.myterminal.MyTerminal;

public class Componente {
    
    protected Ponto origem;
    protected TextColor corDeFrente;
    protected TextColor corDeFundo;

    public Ponto getOrigem() {
        return origem;
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

    public void setCorDeFrente(TextColor corDeFrente) {
        this.corDeFrente = corDeFrente;
    }

    public void setCorDeFundo(TextColor corDeFundo) {
        this.corDeFundo = corDeFundo;
    }

    public void desenha(MyTerminal terminal) {
    }

}
