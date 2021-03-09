package br.ufba.poo;

import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import org.junit.Test;

public class EhPdfTest {
	@Test
	public void extensaoPDF() {
		assertTrue(Lista1.ehPdf("arquivo.PDF"));
	}
		
	@Test
	public void extensaoTxt() {
		assertFalse(Lista1.ehPdf("anotacoes.txt"));
	}
	
	@Test
	public void nomeVazio() {
		assertFalse(Lista1.ehPdf(""));
	}
}
