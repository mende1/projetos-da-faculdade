package br.ufba.poo;

import java.util.ArrayList;

public class ListaDobrada<T> {

    private ArrayList<T> lista;

    public ListaDobrada () {
        this.lista = new ArrayList<T>();
    }

    public int obtemTamanho () {
        return lista.size();
    }

    public void insereElemento (T valor) {
        lista.add(valor);
        lista.add(valor);
    }

    public T obtemElemento (int i) {
        try {
            return lista.get(i);
        }
        catch (Exception e) {
            return null;
        }
    }

    public ArrayList<T> getLista () {
        return lista;
    }
}
