package br.ufba.poo;

public class Disciplina {

    private String nome;
    private String codigo;
    private String natureza;
    private String curriculo;
    private int semestre;
    private int ch;

    public Disciplina (String nome, String codigo, int semestre, String natureza, int ch, String curriculo) {
        this.nome = nome;
        this.codigo = codigo;
        this.semestre = semestre;
        this.natureza = natureza;
        this.ch = ch;
        this.curriculo = curriculo;
    }

    public void imprime () {
        System.out.println(nome);
        System.out.println(codigo + " " + semestre + " " + natureza + " " + ch + " " + curriculo);
    }

}
