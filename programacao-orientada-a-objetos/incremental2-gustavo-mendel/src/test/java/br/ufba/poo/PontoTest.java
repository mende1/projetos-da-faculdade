package br.ufba.poo;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertNull;
import static org.junit.Assert.assertTrue;

import java.util.ArrayList;

import org.junit.Test;

import br.ufba.dc.DC;
import br.ufba.dc.DCClass;
import br.ufba.dc.DCConstructor;

public class PontoTest {
	DCClass cPonto = DC.getClass("br.ufba.poo.Ponto");
	
	@Test
	public void possuiClassePonto() {
		assertNotNull(cPonto);
	}
	
	@Test
	public void possuiConstrutorCorreto() throws ClassNotFoundException {
		ArrayList<DCConstructor> construtores = cPonto.getContructors();
		assertEquals(1, construtores.size());
		
		Class c = Class.forName("br.ufba.poo.Ponto");
		assertEquals(2, c.getDeclaredConstructors()[0].getParameterCount());
	}
	
	@Test
	public void possuiGetters() {
		assertNotNull(cPonto.getMethod("getX"));
		assertNotNull(cPonto.getMethod("getY"));
	}
	
	@Test
	public void classeEhImutavel() {
		assertNull(cPonto.getMethod("setX"));
		assertNull(cPonto.getMethod("setY"));
		assertTrue(cPonto.getAttributes().stream().filter(a -> a.getName().equals("x")).findFirst().orElse(null).isPrivate());
		assertTrue(cPonto.getAttributes().stream().filter(a -> a.getName().equals("y")).findFirst().orElse(null).isPrivate());
	}
	
	@Test
	public void classeDefineComparacaoDeIgualdade() {
		assertTrue(cPonto.getMethods().stream().anyMatch(m -> m.getName().equals("equals")));
		assertTrue(cPonto.getMethods().stream().anyMatch(m -> m.getName().equals("hashCode")));
	}
	
	@Test
	public void comDeslocamento() {
		Ponto p1 = new Ponto(3, 5);
		Ponto p2 = p1.comDeslocamento(1, 2);
		assertEquals(3, p1.getX());
		assertEquals(5, p1.getY());
		assertEquals(4, p2.getX());
		assertEquals(7, p2.getY());
	}
	
	@Test
	public void metodoEquals() {
		Ponto p1 = new Ponto(3, 5);
		Ponto p2 = new Ponto(3, 5);
		Ponto p3 = new Ponto(4, 5);
		Ponto p4 = new Ponto(3, 6);
		
		assertEquals(p1, p1);
		assertEquals(p1, p2);
		assertNotEquals(p1, p3);
		assertNotEquals(p1, p4);
		assertNotEquals(p1, null);
		assertNotEquals(null, p1);
		assertNotEquals(p1, "ponto");
	}
	
	@Test
	public void metodoHashCode() {
		Ponto p1 = new Ponto(3, 5);
		Ponto p2 = new Ponto(3, 5);
		
		assertEquals(p1.hashCode(), p2.hashCode());
	}
}
