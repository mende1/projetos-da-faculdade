package br.ufba.poo;

import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class MaiorTest {
	@Test
	public void arrayVazio() {
		int[] array = {};
		int maior = Lista1.maior(array);
		assertEquals(Integer.MIN_VALUE, maior);
	}
	
	@Test
	public void ultimoEhMaior() {
		int[] array = {3, 5, 7, 3, 99};
		int maior = Lista1.maior(array);
		assertEquals(99, maior);
	}

}
