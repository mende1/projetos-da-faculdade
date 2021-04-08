package br.ufba.poo;

import br.ufba.myterminal.MyTerminal;

import java.util.ArrayList;

public class Tela {

    ArrayList<Rotulo> rotulos;
    ArrayList<Retangulo> retangulos;

    public Tela () {
        rotulos = new ArrayList<>();
        retangulos = new ArrayList<>();
    }

    public ArrayList<Rotulo> getRotulos () {
        return (ArrayList<Rotulo>) rotulos.clone();
    }

    public ArrayList<Retangulo> getRetangulos () {
        return (ArrayList<Retangulo>) retangulos.clone();
    }

    public void addRotulo (Rotulo rotulo) {
        rotulos.add(rotulo);
    }

    public void addRetangulo (Retangulo retangulo) {
        retangulos.add(retangulo);
    }

    public void desenha (MyTerminal terminal) {

        terminal.clear();

        for (Rotulo rotulo : rotulos) {
            rotulo.desenha(terminal);
        }

        for (Retangulo retangulo : retangulos) {
            retangulo.desenha(terminal);
        }
    }
}
