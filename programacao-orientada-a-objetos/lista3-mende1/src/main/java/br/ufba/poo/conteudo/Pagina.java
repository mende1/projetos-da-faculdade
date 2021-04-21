package br.ufba.poo.conteudo;

public class Pagina extends Conteudo {

    private String endereco;

    public Pagina (String titulo, String corpo, String endereco) {
        super(titulo, corpo);
        this.endereco = endereco;
    }

    public String getEndereco() {
        return endereco;
    } 
}
