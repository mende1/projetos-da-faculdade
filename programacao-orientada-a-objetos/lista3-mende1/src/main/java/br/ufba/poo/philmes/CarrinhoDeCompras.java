package br.ufba.poo.philmes;

import java.util.ArrayList;

public class CarrinhoDeCompras {
	private ArrayList<Filme> filmes = new ArrayList<>();

	public void insereFilme(Filme filme) {
		filmes.add(filme);
	}
	
	public void imprimeRecibo() {
		for (Filme filme : filmes) {
			System.out.println(filme);
		}
	}

	public int getPrecoTotal() {
		int precoTotal = 0;
		for (Filme filme : filmes) {
			precoTotal += filme.getPreco();
		}

		return precoTotal;
	}
	
	public static void main(String[] args) {

		CarrinhoDeCompras carrinho = new CarrinhoDeCompras();
		carrinho.insereFilme(new Filme("Titanic"));
		carrinho.insereFilme(new FilmeInfantil("Big Hero 6"));
		carrinho.insereFilme(new FilmeLancamento("Capita Marvel"));
		carrinho.imprimeRecibo();
		System.out.println(carrinho.getPrecoTotal());
		/* Saída esperada:
			Titanic;3;2
			Big Hero 6;4;4
			Capita Marvel;5;1
			12
		 */
	}
}
