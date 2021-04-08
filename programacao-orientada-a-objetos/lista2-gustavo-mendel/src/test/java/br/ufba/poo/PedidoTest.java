package br.ufba.poo;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertNull;
import static org.junit.Assert.assertTrue;

import java.lang.reflect.InvocationTargetException;

import org.junit.Test;

import br.ufba.dc.DC;
import br.ufba.dc.DCClass;

public class PedidoTest {
	private DCClass cPedido = DC.getClass("br.ufba.poo.Pedido");

	@Test
	public void atributosSaoPrivados() {
		assertTrue(cPedido.getAttributes().parallelStream()
				.filter(x -> !x.getName().startsWith("$"))
				.allMatch(x -> x.isPrivate()));
	}	
	@Test
	public void gettersESetters() {
		assertNotNull(cPedido.getMethod("getValor"));
		assertEquals("double", cPedido.getMethod("getValor").getReturnType().getName());
		assertNotNull(cPedido.getMethod("getSituacao"));
		assertEquals("br.ufba.poo.Situacao", cPedido.getMethod("getSituacao").getReturnType().getName());	
		
		assertNotNull(cPedido.getMethod("setSituacao"));
		assertEquals("void", cPedido.getMethod("setSituacao").getReturnType().getName());
		assertNull(cPedido.getMethod("setValor"));
	}

	@Test
	public void construtor() throws ClassNotFoundException, InstantiationException, IllegalAccessException, IllegalArgumentException, InvocationTargetException, SecurityException, NoSuchMethodException {
		Class c = Class.forName("br.ufba.poo.Pedido");
		assertEquals(1, c.getDeclaredConstructors().length);
		assertNotNull(c.getDeclaredConstructor(double.class));
		Pedido p = (Pedido)c.getDeclaredConstructors()[0].newInstance(123);
		
	}
	
	@Test
	public void valoresIniciais() throws ClassNotFoundException, InstantiationException, IllegalAccessException, IllegalArgumentException, InvocationTargetException, SecurityException, NoSuchMethodException {
		Class c = Class.forName("br.ufba.poo.Pedido");
		Pedido p = (Pedido)c.getDeclaredConstructors()[0].newInstance(123.4);
		assertEquals(123.4, p.getValor(), 0.0001);
		assertEquals(Situacao.PENDENTE, p.getSituacao());
	}

}
