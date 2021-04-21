package br.ufba.poo.conteudo;

public class Conteudo {

    private String titulo;
    private String corpo;

    public Conteudo (String titulo, String corpo) {
        this.titulo = titulo;
        this.corpo = corpo;
    }

    public String getTitulo() {
        return titulo;
    }

    public String getCorpo() {
        return corpo;
    }
}
