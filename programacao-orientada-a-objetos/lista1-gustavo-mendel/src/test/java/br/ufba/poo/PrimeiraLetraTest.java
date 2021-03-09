package br.ufba.poo;

import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class PrimeiraLetraTest {
	@Test
	public void letraMaiuscula() {
		String nome = "Alvaro";
		assertEquals('a', Lista1.primeiraLetra(nome));
	}

	@Test
	public void letraMinuscula() {
		String nome = "beatriz";
		assertEquals('b', Lista1.primeiraLetra(nome));
	}
}
