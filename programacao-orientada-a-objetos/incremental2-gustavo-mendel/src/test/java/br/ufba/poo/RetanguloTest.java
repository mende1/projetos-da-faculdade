package br.ufba.poo;

import static org.junit.Assert.assertEquals;

import org.junit.Before;
import org.junit.Test;
import org.mockito.Mockito;

import com.googlecode.lanterna.terminal.DefaultTerminalFactory;
import com.googlecode.lanterna.terminal.Terminal;
import com.googlecode.lanterna.terminal.virtual.DefaultVirtualTerminal;

import br.ufba.dc.DC;
import br.ufba.dc.DCClass;
import br.ufba.myterminal.MyTerminal;

public class RetanguloTest {
	DCClass cRetangulo = DC.getClass("br.ufba.poo.Retangulo");
	
	DefaultTerminalFactory defaultTerminalFactory = new DefaultTerminalFactory();
	Terminal lanternaTerminal;
	MyTerminal terminal;
	
	@Before
	public void setup() {
		lanternaTerminal = Mockito.spy(DefaultVirtualTerminal.class);
		terminal = new MyTerminal(lanternaTerminal);
	}

	@Test
	public void redimensiona() {
		Retangulo r = new Retangulo(new Ponto(1, 2), 5, 5);
		r.redimensiona(6, 7);
		assertEquals(6, r.getLargura());
		assertEquals(7, r.getAltura());
		assertEquals(new Ponto(6, 8), r.getCantoOposto());
	}
	
	@Test
	public void settersCantoOposto() {
		Retangulo r = new Retangulo(new Ponto(1, 2), new Ponto(1, 1));
		r.setCantoOposto(new Ponto(11, 22));
		assertEquals(new Ponto(11, 22), r.getCantoOposto());
		assertEquals(11, r.getLargura());
		assertEquals(21, r.getAltura());
		
		Retangulo r2 = new Retangulo(new Ponto(1, 2), 5, 5);
		r2.setLargura(11);
		r2.setAltura(21);
		assertEquals(new Ponto(11, 22), r2.getCantoOposto());
		assertEquals(11, r2.getLargura());
		assertEquals(21, r2.getAltura());
	}
	
}
