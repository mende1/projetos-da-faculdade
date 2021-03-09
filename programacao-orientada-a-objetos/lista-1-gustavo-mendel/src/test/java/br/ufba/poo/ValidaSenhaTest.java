package br.ufba.poo;

import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import org.junit.Test;

public class ValidaSenhaTest {
	@Test
	public void objetosIdenticos() {
		assertTrue(Lista1.validaSenha("abcd", "abcd"));
	}
	
	@Test
	public void objetosDiferentes() {
		assertFalse(Lista1.validaSenha("abcd", "qwerty"));
	}
}
