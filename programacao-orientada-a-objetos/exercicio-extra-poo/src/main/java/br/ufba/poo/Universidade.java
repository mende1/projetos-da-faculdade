package br.ufba.poo;

import java.util.ArrayList;

public class Universidade {

    private String nome;
    private ArrayList<Curso> cursos;

    public Universidade (String nome) {
        this.nome = nome;
        cursos = new ArrayList<Curso>();
    }

    public void addCurso (Curso curso) {
        cursos.add(curso);
    }

    public ArrayList<Curso> getCursos () {
        return cursos;
    }

    public void imprime () {
        System.out.println("\nFaculdade: " + nome);
        System.out.println("Possui " + this.qtdCursos() + " Cursos\t Um total de " + this.qntDisciplinas() + " Disciplinas\n");
    }

    public void imprimeTudo () {
        System.out.println("\nFaculdade: " + nome);
        System.out.println("Possui " + this.qtdCursos() + " Cursos\t Um total de " + this.qntDisciplinas() + " Disciplinas\n");

        for (Curso curso : cursos) {
            curso.imprimeTudo();
        }
    }

    public int qtdCursos () {
        return cursos.size();
    }

    public int qntDisciplinas () {
        int qnt = 0;

        for (Curso curso : cursos) {
            qnt += curso.qtdDisciplinas();
        }

        return qnt;
    }
}
