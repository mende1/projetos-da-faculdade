package br.ufba.poo;

public class Aluno {
    
    private String nome;
    private String matricula;

    public Aluno ( String matricula, String nome ) {
        this.matricula = matricula;
        this.nome = nome;
    }

    public String getNome () {
        return nome;
    }

    public String getMatricula () {
        return matricula;
    }

    public void setNome ( String nome ) {
        this.nome = nome;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Aluno)) return false;

        Aluno aluno = (Aluno) o;

        return matricula.equals(aluno.matricula);
    }

    @Override
    public int hashCode() {
        return matricula.hashCode();
    }
}
