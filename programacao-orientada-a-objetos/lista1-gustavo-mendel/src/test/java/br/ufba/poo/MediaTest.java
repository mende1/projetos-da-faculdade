package br.ufba.poo;

import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class MediaTest {
	public static final double delta = 0.001;
	
	@Test
	public void doisValoresIguais() {
		assertEquals(3.0, Lista1.media(3.0, 3.0), delta);
	}
	
	@Test
	public void mediaZero() {
		assertEquals(0.0, Lista1.media(-3.0, 3.0), delta);
	}
}
