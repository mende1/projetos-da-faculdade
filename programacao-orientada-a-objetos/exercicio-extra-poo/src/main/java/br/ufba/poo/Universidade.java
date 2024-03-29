package br.ufba.poo;

import java.util.ArrayList;

public class Universidade {

    private String nome;
    private ArrayList<Curso> cursos;

    /**
     * 
     * Construtor
     * 
     * @param nome String
     */
    public Universidade (String nome) {
        this.nome = nome;
        cursos = new ArrayList<>();
    }

    /**
     * 
     * Adiciona um curso para a Universidade
     * 
     * @param curso Curso
     */
    public void addCurso (Curso curso) {
        cursos.add(curso);
    }

    /**
     * 
     * @return ArrayList com todos os objetos Curso da Universidade
     */
    public ArrayList<Curso> getCursos () {
        return cursos;
    }

    /**
     * Imprime as informações somente da Universidade
     */
    public void imprime () {
        System.out.println("\n" + nome);
        System.out.print("Possui " + this.qtdCursos() + " Cursos");
        System.out.println("\t Um total de " + this.qntDisciplinas() + " Disciplinas");
    }

    /**
     * Imprime informações da Universidade e de todos os Cursos e Disciplicas que lhes pertence
     */
    public void imprimeTudo () {
        System.out.println("\n" + nome);
        System.out.print("Possui " + this.qtdCursos() + " Cursos");
        System.out.println("\t Um total de " + this.qntDisciplinas() + " Disciplinas");

        for (Curso curso : cursos) {
            curso.imprimeTudo();
        }
    }

    /**
     * 
     * @return a quantidade de cursos que possui a universidade
     */
    public int qtdCursos () {
        return cursos.size();
    }

    /**
     * 
     * @return a quantidade de disciplinas que possui a universidade
     */
    public int qntDisciplinas () {
        int qnt = 0;

        for (Curso curso : cursos) {
            qnt += curso.qtdDisciplinas();
        }

        return qnt;
    }
}
