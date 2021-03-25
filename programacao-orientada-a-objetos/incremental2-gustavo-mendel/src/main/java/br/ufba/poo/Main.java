package br.ufba.poo;

import br.ufba.myterminal.MyTerminal;

public class Main {

    public static void main(String[] args) {

        MyTerminal terminal = new MyTerminal();

        Ponto origem = new Ponto(4, 4);
        Ponto destino = new Ponto(8,8);

        Retangulo ret = new Retangulo(origem, destino);

        System.out.println(ret.getLargura());
        System.out.println(ret.getAltura());

        ret.desenha(terminal);

        ret.desloca(1, 1);

        System.out.println(ret.getLargura());
        System.out.println(ret.getAltura());
        ret.desenha(terminal);

        terminal.draw();
    }
}
