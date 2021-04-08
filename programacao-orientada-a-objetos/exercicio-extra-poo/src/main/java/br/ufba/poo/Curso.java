package br.ufba.poo;

import java.util.ArrayList;

public class Curso {

    private final int codigo;
    private String nome;
    private ArrayList<Disciplina> disciplinas;

    /**
     * 
     * Construtor
     * 
     * @param nome String
     * @param codigo int
     */
    public Curso (String nome, int codigo) {
        this.nome = nome;
        this.codigo = codigo;
        disciplinas = new ArrayList<>();
    }

    /**
     * 
     * Adiciona uma Disciplina para o Curso
     * 
     * @param disciplina Disciplina
     */
    public void addDisciplina (Disciplina disciplina) {
        this.disciplinas.add(disciplina);
    }

    /**
     * 
     * @return um ArrayList com as Disciplinas do Curso
     */
    public ArrayList<Disciplina> getDisciplinas () {
        return disciplinas;
    }

    /**
     * Imprime as informações apenas do Curso
     */
    public void imprime () {
        System.out.println("\n" + nome);
        System.out.println(codigo + "\t\t Possui " + this.qtdDisciplinas() + " Disciplinas\n");
    }

    /**
     * Imprime as informações do Curso e todas as Disciplinas que lhes pertence
     */
    public void imprimeTudo () {
        System.out.println("\n" + nome);
        System.out.println(codigo + "\t\t Possui " + this.qtdDisciplinas() + " Disciplinas\n");

        for (Disciplina disciplina : disciplinas) {
            disciplina.imprime();
        }
    }

    /**
     * 
     * @return a quantidade de disciplinas que possui o curso
     */
    public int qtdDisciplinas () {
        return disciplinas.size();
    }
}
