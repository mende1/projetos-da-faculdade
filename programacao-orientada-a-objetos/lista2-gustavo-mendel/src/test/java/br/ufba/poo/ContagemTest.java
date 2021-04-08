package br.ufba.poo;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import java.lang.reflect.InvocationTargetException;

import org.junit.Test;

import br.ufba.dc.DC;
import br.ufba.dc.DCMethod;

public class ContagemTest {
	@Test
	public void metodo() {
		DCMethod m = DC.getClass("br.ufba.poo.Contador").getMethod("getContagem");
		assertTrue(m.isStatic());
	}
	
	@Test
	public void construtor() throws ClassNotFoundException {
		Class<?> c = Class.forName("br.ufba.poo.Contador");
		assertEquals(1, c.getDeclaredConstructors().length);
	}
	
	@Test
	public void contagem() throws ClassNotFoundException, InstantiationException, IllegalAccessException, IllegalArgumentException, InvocationTargetException, SecurityException {
		Class<?> c = Class.forName("br.ufba.poo.Contador");
		
		assertEquals(0, Contador.getContagem());
		
		c.getDeclaredConstructors()[0].newInstance();
		assertEquals(1, Contador.getContagem());
		
		c.getDeclaredConstructors()[0].newInstance();
		assertEquals(2, Contador.getContagem());
		
		c.getDeclaredConstructors()[0].newInstance();
		assertEquals(3, Contador.getContagem());
	}
}
