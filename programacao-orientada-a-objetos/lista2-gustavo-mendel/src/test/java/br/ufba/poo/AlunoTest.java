package br.ufba.poo;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertNull;
import static org.junit.Assert.assertTrue;

import java.lang.reflect.InvocationTargetException;
import java.util.ArrayList;

import org.junit.Test;

import br.ufba.dc.DC;
import br.ufba.dc.DCClass;
import br.ufba.dc.DCConstructor;
import br.ufba.dc.DCMethod;

public class AlunoTest {
	DCClass cAluno = DC.getClass("br.ufba.poo.Aluno");
	
	@Test
	public void atributos() {
		assertTrue(cAluno.hasAttribute("matricula"));
		assertTrue(cAluno.hasAttribute("nome"));
	}
	
	@Test
	public void atributosSaoPrivados() {
		// cAluno.attributes().allMatch(x -> x.isPrivate())
		assertTrue(cAluno.getAttributes().parallelStream()
				.filter(x -> !x.getName().startsWith("$"))
				.allMatch(x -> x.isPrivate()));
	}
	
	@Test
	public void implementaEquals() {
		// cAluno.method("asd").shouldExist()
		DCMethod m = cAluno.getMethod("equals");
		DCMethod n = cAluno.getMethod("hashCode");
		assertNotNull(m);
		assertNotNull(n);
	}
	
	@Test
	public void gettersESetters() {
		assertNotNull(cAluno.getMethod("getMatricula"));
		assertNotNull(cAluno.getMethod("getNome"));
		assertNull(cAluno.getMethod("setMatricula"));
		assertNotNull(cAluno.getMethod("setNome"));
	}
	
	@Test
	public void construtores() throws ClassNotFoundException {
		ArrayList<DCConstructor> ctors = cAluno.getContructors();
		assertEquals(1, ctors.size());
		
//		DCConstructor ctor = ctors.get(0);
		Class c = Class.forName("br.ufba.poo.Aluno");
		assertEquals(2, c.getDeclaredConstructors()[0].getParameterCount());
	}

	@Test
	public void igualdade1() throws InstantiationException, IllegalAccessException, ClassNotFoundException, IllegalArgumentException, InvocationTargetException, SecurityException {
		Class c = Class.forName("br.ufba.poo.Aluno");
		Object a1 = c.getDeclaredConstructors()[0].newInstance("123", "abc");
		Object a2 = c.getDeclaredConstructors()[0].newInstance("123", "abc");
		assertTrue(a1.equals(a2));
	}

	@Test
	public void igualdade2() throws InstantiationException, IllegalAccessException, ClassNotFoundException, IllegalArgumentException, InvocationTargetException, SecurityException {
		Class c = Class.forName("br.ufba.poo.Aluno");
		Object a1 = c.getDeclaredConstructors()[0].newInstance("123", "abc");
		Object a2 = c.getDeclaredConstructors()[0].newInstance("123", "defgh");
		assertTrue(a1.equals(a2));
	}

	@Test
	public void igualdade3() throws InstantiationException, IllegalAccessException, ClassNotFoundException, IllegalArgumentException, InvocationTargetException, SecurityException {
		Class c = Class.forName("br.ufba.poo.Aluno");
		Object a1 = c.getDeclaredConstructors()[0].newInstance("123", "abc");
		Object a2 = c.getDeclaredConstructors()[0].newInstance("456", "abc");
		assertFalse(a1.equals(a2));
	}

	@Test
	public void igualdade4() throws InstantiationException, IllegalAccessException, ClassNotFoundException, IllegalArgumentException, InvocationTargetException, SecurityException {
		Class c = Class.forName("br.ufba.poo.Aluno");
		Object a1 = c.getDeclaredConstructors()[0].newInstance("123", "abc");
		String x = "12";
		x += "3";
		Object a2 = c.getDeclaredConstructors()[0].newInstance(x, "qwe");
		assertTrue(a1.equals(a2));
	}

}
