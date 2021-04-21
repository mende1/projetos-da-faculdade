package br.ufba.poo.philmes;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import org.junit.Test;

public class PhilmesTest {
	
	@Test
	public void existemAsClassesDaEspecificacao() throws ClassNotFoundException {
		Class.forName("br.ufba.poo.philmes.CarrinhoDeCompras");
		Class.forName("br.ufba.poo.philmes.Filme");
		Class.forName("br.ufba.poo.philmes.FilmeLancamento");
		Class.forName("br.ufba.poo.philmes.FilmeInfantil");
	}
		
	@Test
	public void oNumeroDeAtributosSegueAEspecificacao() {
		assertEquals(1, Filme.class.getDeclaredFields().length);
		assertEquals(0, FilmeInfantil.class.getDeclaredFields().length);
		assertEquals(0, FilmeLancamento.class.getDeclaredFields().length);
	}
}
