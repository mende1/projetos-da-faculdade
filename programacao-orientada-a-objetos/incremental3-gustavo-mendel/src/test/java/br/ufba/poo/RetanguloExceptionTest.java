package br.ufba.poo;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.fail;

import org.junit.Test;

public class RetanguloExceptionTest {
	
	@Test
	public void criarRetanguloComCantoOpostoValido() {
		new Retangulo(new Ponto(5, 5), new Ponto(8, 9));
		new Retangulo(new Ponto(5, 5), new Ponto(6, 6));
	}

	@Test
	public void criarRetanguloComLarguraAlturaValidos() {
		new Retangulo(new Ponto(5, 5), 1, 1);
		new Retangulo(new Ponto(5, 5), 3, 4);
	}

	
	@Test
	public void aoCriarRetanguloComCantoOpostoInvalidoDeveLancarExcecao() {
		try {
			new Retangulo(new Ponto(5, 5), new Ponto(4, 5));
			fail();
		} catch (IllegalArgumentException e) {
		}
		
		try {
			new Retangulo(new Ponto(5, 5), new Ponto(5, 2));
			fail();
		} catch (IllegalArgumentException e) {
		}
		
		try {
			new Retangulo(new Ponto(5, 5), new Ponto(1, 3));
			fail();
		} catch (IllegalArgumentException e) {
		}
	}
	
	@Test
	public void aoCriarRetanguloComLarguraOuAlturaValidaDeveLancarExcecao() {
		try {
			new Retangulo(new Ponto(5, 5), 0, 0);
			fail();
		} catch (IllegalArgumentException e) {
		}
		
		try {
			new Retangulo(new Ponto(5, 5), 0, 10);
			fail();
		} catch (IllegalArgumentException e) {
		}
		
		try {
			new Retangulo(new Ponto(5, 5), -3, -2);
			fail();
		} catch (IllegalArgumentException e) {
		}
	}
	
	@Test
	public void redimensionarComLarguraOuAlturaValida() {
		Retangulo r = new Retangulo(new Ponto(5, 5), 2, 2);
		r.redimensiona(1, 1);
	}
	
	@Test
	public void aoRedimensionarComLarguraOuAlturaInvalidaDeveLancarExcecao() {
		try {
			Retangulo r = new Retangulo(new Ponto(5, 5), 1, 1);
			r.redimensiona(0, 0);
			fail();
		} catch (IllegalArgumentException e) {
		}
		
		try {
			Retangulo r = new Retangulo(new Ponto(5, 5), 1, 1);
			r.redimensiona(0, 10);
			fail();
		} catch (IllegalArgumentException e) {
		}
		
		try {
			Retangulo r = new Retangulo(new Ponto(5, 5), 1, 1);
			r.redimensiona(-3, -2);
			fail();
		} catch (IllegalArgumentException e) {
		}
	}
	
	@Test
	public void checaSeOutrosMetodosEstaoTratandoDimensoesInvalidas() {
		try {
			Retangulo r = new Retangulo(new Ponto(5, 5), 1, 1);
			r.setLargura(0);
			fail();
		} catch (IllegalArgumentException e) {
		}

		try {
			Retangulo r = new Retangulo(new Ponto(5, 5), 1, 1);
			r.setAltura(-1);
			fail();
		} catch (IllegalArgumentException e) {
		}

		try {
			Retangulo r = new Retangulo(new Ponto(5, 5), 1, 1);
			r.setCantoOposto(new Ponto(4, 5));
			fail();
		} catch (IllegalArgumentException e) {
		}
	}

	@Test
	public void checaOutrosMetodosComDimensoesValidas() {
		Retangulo r1 = new Retangulo(new Ponto(5, 5), 1, 1);
		r1.setLargura(1);
		
		Retangulo r2 = new Retangulo(new Ponto(5, 5), 1, 1);
		r2.setCantoOposto(new Ponto(5, 5));
	}
	
	@Test
	public void checaMensagemDeExcecao() {
		try {
			new Retangulo(new Ponto(5, 5), new Ponto(4, 5));
			fail();
		} catch (IllegalArgumentException e) {
			assertEquals("Dimensoes invalidas", e.getMessage());
		}		
	}
}
