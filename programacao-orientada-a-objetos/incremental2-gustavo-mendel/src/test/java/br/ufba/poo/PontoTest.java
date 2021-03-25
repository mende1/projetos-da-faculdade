package br.ufba.poo;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;

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
}
