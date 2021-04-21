package br.ufba.poo.conteudo;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import java.lang.reflect.Constructor;
import java.lang.reflect.Modifier;

import org.junit.Test;

public class ConteudoTest {

	@Test
	public void existemAsTresClasses() throws ClassNotFoundException {
		Class.forName("br.ufba.poo.conteudo.Conteudo");
		Class.forName("br.ufba.poo.conteudo.Pagina");
		Class.forName("br.ufba.poo.conteudo.Noticia");
	}
	
	@Test
	public void asClassesNaoPossuemAtributosAMais() {
		assertEquals(2, Conteudo.class.getDeclaredFields().length);
		assertEquals(2, Noticia.class.getDeclaredFields().length);
		assertEquals(1, Pagina.class.getDeclaredFields().length);
	}
		
	@Test
	public void asClassesPossuemOsConstrutoresCorretos() {
		for (Constructor<?> ctor : Conteudo.class.getDeclaredConstructors()) {
			assertEquals(2, ctor.getParameterCount());
			break;
		}
		
		for (Constructor<?> ctor : Noticia.class.getDeclaredConstructors()) {
			assertEquals(4, ctor.getParameterCount());
			break;
		}
		
		for (Constructor<?> ctor : Pagina.class.getDeclaredConstructors()) {
			assertEquals(3, ctor.getParameterCount());
			break;
		}
	}	
}
