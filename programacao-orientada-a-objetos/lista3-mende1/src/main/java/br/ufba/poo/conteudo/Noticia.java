package br.ufba.poo.conteudo;

public class Noticia extends Conteudo {
    private String autor;
    private String data;

    public Noticia (String titulo, String corpo, String autor, String data) {
        super(titulo, corpo);
        this.autor = autor;
        this.data = data;
    }

    public String getAutor() {
        return autor;
    }

    public String getData() {
        return data;
    }
}
