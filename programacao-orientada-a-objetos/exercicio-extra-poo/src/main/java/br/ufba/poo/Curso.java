package br.ufba.poo;

import java.util.ArrayList;

public class Curso {

    private int codigo;
    private String nome;
    private ArrayList<Disciplina> disciplinas;

    public Curso (String nome, int codigo) {
        this.nome = nome;
        this.codigo = codigo;
        disciplinas = new ArrayList<Disciplina>();
    }

    public void addDisciplina (Disciplina disciplina) {
        this.disciplinas.add(disciplina);
    }

    public ArrayList<Disciplina> getDisciplinas () {
        return disciplinas;
    }

    public void imprime () {
        System.out.println("\n" + nome);
        System.out.println(codigo + "\t\t Possui " + this.qtdDisciplinas() + " Disciplinas\n");
    }

    public void imprimeTudo () {
        System.out.println("\n" + nome);
        System.out.println(codigo + "\t\t Possui " + this.qtdDisciplinas() + " Disciplinas\n");

        for (Disciplina disciplina : disciplinas) {
            disciplina.imprime();
        }
    }

    public int qtdDisciplinas () {
        return disciplinas.size();
    }
}
