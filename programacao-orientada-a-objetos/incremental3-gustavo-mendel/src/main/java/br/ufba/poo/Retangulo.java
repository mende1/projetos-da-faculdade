package br.ufba.poo;

import br.ufba.myterminal.MyTerminal;
import org.apache.commons.lang3.StringUtils;

import com.googlecode.lanterna.TextColor;

public class Retangulo {

    private Ponto origem;
    private Ponto cantoOposto;

    private TextColor corDeFrente;
    private TextColor corDeFundo;
    private char caractere;

    public Retangulo (Ponto origem, Ponto cantoOposto) {

        if (cantoOposto.getX() < origem.getX() || cantoOposto.getY() < origem.getY()) {
            throw new IllegalArgumentException("Dimensoes invalidas");
        }

        this.origem = origem;
        this.cantoOposto = cantoOposto;
        this.corDeFrente = TextColor.ANSI.WHITE;
        this.corDeFundo = TextColor.ANSI.BLACK;
        this.caractere = '#';
    }

    public Retangulo (Ponto origem, int largura, int altura) {

        if (largura < 1 || altura < 1) {
            throw new IllegalArgumentException("Dimensoes invalidas");
        }

        this.origem = origem;
        this.cantoOposto = new Ponto(origem.getX() + largura - 1, origem.getY() + altura - 1);
        this.corDeFrente = TextColor.ANSI.WHITE;
        this.corDeFundo = TextColor.ANSI.BLACK;
        this.caractere = '#';
    }

    public Retangulo (Ponto origem, Ponto cantoOposto, TextColor corDeFrente, TextColor corDeFundo, char caractere) {

        if (cantoOposto.getX() < origem.getX() || cantoOposto.getY() >  origem.getY()) {
            throw new IllegalArgumentException("Dimensoes invalidas");
        }

        this.origem = origem;
        this.cantoOposto = cantoOposto;
        this.corDeFrente = corDeFrente;
        this.corDeFundo = corDeFundo;
        this.caractere = caractere;
    }

    public Ponto getOrigem () {
        return origem;
    }

    public void setOrigem (Ponto origem) {
        this.origem = origem;
    }

    public Ponto getCantoOposto() {
        return cantoOposto;
    }

    public void setCantoOposto(Ponto cantoOposto) {

        if (cantoOposto.getX() < origem.getX() || cantoOposto.getY() < origem.getY()) {
            throw new IllegalArgumentException("Dimensoes invalidas");
        }

        this.cantoOposto = cantoOposto;
    }

    public int getLargura () {
        return cantoOposto.getX() - origem.getX() + 1;
    }

    public void setLargura (int largura) {

        if (largura < 1) {
            throw new IllegalArgumentException("Dimensoes invalidas");
        }

        this.cantoOposto = new Ponto(origem.getX()+largura-1, this.cantoOposto.getY());
    }

    public int getAltura () {
        return cantoOposto.getY() - origem.getY() + 1;
    }

    public void setAltura (int altura) {

        if (altura < 1) {
            throw new IllegalArgumentException("Dimensoes invalidas");
        }

        this.cantoOposto = new Ponto(this.cantoOposto.getX(), origem.getY()+altura-1);
    }

    public TextColor getCorDeFrente() {
        return corDeFrente;
    }

    public void setCorDeFrente(TextColor corDeFrente) {
        this.corDeFrente = corDeFrente;
    }

    public TextColor getCorDeFundo() {
        return corDeFundo;
    }

    public void setCorDeFundo(TextColor corDeFundo) {
        this.corDeFundo = corDeFundo;
    }

    public char getCaractere() {
        return caractere;
    }

    public void setCaractere(char caractere) {
        this.caractere = caractere;
    }

    public void desloca (int dx, int dy) {

        if (origem.getX()+dx > cantoOposto.getX() || origem.getY()+dy > cantoOposto.getY()) {
            throw new IllegalArgumentException("Dimensoes invalidas");
        }

        int larguraAntiga = getLargura();
        int alturaAntiga = getAltura();

        this.origem = new Ponto(origem.getX()+dx, origem.getY()+dy);

        this.setLargura(larguraAntiga);
        this.setAltura(alturaAntiga);
    }

    public void redimensiona (int largura, int altura) {

        if (origem.getX()+largura-1 < origem.getX() || origem.getY()+altura-1 < origem.getY()) {
            throw new IllegalArgumentException("Dimensoes invalidas");
        }

        this.cantoOposto = new Ponto(origem.getX()+largura-1, origem.getY()+altura-1);
    }

    public void desenha (MyTerminal terminal) {

        TextColor corAnteriorFrente = terminal.getForegroundColor();
        TextColor corAnteriorFundo = terminal.getBackgroundColor();

        terminal.setPosition(origem.getX(), origem.getY());

        terminal.setForegroundColor(corDeFrente);
        terminal.setBackgroundColor(corDeFundo);

        int altura = this.getAltura();
        int largura = this.getLargura();

        for (int i=0; i<altura; i++) {
            terminal.println(StringUtils.repeat(caractere, largura));
        }

        terminal.setForegroundColor(corAnteriorFrente);
        terminal.setBackgroundColor(corAnteriorFundo);
    }
}