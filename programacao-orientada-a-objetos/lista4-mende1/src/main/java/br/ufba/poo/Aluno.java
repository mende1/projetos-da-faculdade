package br.ufba.poo;

public class Aluno {

	private String nome;
	private double nota;

	public Aluno (String nome, double nota) {
		this.nome = nome;
		if (nota < 0 || nota > 10) {
			throw new NotaInvalidaException();
		}
		else {
			this.nota = nota;
		}
	}

	public String getNome() {
		return nome;
	}

	public double getNota() {
		return nota;
	}
}
