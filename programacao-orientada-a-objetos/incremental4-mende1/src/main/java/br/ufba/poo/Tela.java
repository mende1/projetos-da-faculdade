package br.ufba.poo;

import br.ufba.myterminal.MyTerminal;
import java.util.ArrayList;
 
public class Tela {

    private ArrayList<Componente> componentes;

    public Tela () {
        componentes = new ArrayList<>();
    }

    public ArrayList<Componente> getComponentes () {
        return (ArrayList<Componente>) componentes.clone();
    }

    public void addComponente (Componente componente) {
        componentes.add(componente);
    }

    public void desenha (MyTerminal terminal) {

        terminal.clear();

        for (Componente componente : componentes) {
            componente.desenha(terminal);
        }
    }
}
