package br.ufba.poo;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;

import org.junit.Before;
import org.junit.Test;
import org.mockito.Mockito;

import com.googlecode.lanterna.TextCharacter;
import com.googlecode.lanterna.TextColor;
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
	public void possuiMetodos() {
		String[] metodos = {"redimensiona", "desloca",
				"getCantoOposto", "setCantoOposto",
				"getOrigem", "setOrigem",
				"getLargura", "setLargura",
				"getAltura", "setAltura",
				"getCaractere", "setCaractere",
				"getCorDeFrente", "setCorDeFrente",
				"getCorDeFundo", "setCorDeFundo",
				"desenha"};
	
		for (String metodo : metodos) {
			assertNotNull(cRetangulo.getMethod(metodo));
		}
	}

	@Test
	public void construtores() {
		Retangulo r = new Retangulo(new Ponto(1, 2), new Ponto(11, 22));
		assertEquals(new Ponto(11, 22), r.getCantoOposto());
		assertEquals(11, r.getLargura());
		assertEquals(21, r.getAltura());
		
		Retangulo r2 = new Retangulo(new Ponto(1, 2), 11, 21);
		assertEquals(new Ponto(11, 22), r2.getCantoOposto());
		assertEquals(11, r2.getLargura());
		assertEquals(21, r2.getAltura());
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
	public void desloca() {
		Retangulo r = new Retangulo(new Ponto(2, 3), 11, 12);
		r.desloca(-1, -1);
		assertEquals(new Ponto(1, 2), r.getOrigem());
		assertEquals(11, r.getLargura());
		assertEquals(12, r.getAltura());
		assertEquals(new Ponto(11, 13), r.getCantoOposto());
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
	
	@Test
	public void desenhaPreservaCores() {
		TextColor oldFg = TextColor.ANSI.CYAN_BRIGHT;
		TextColor oldBg = TextColor.ANSI.RED;

		TextColor newFg = TextColor.ANSI.GREEN_BRIGHT;
		TextColor newBg = TextColor.ANSI.MAGENTA;

		terminal.setForegroundColor(oldFg);
		terminal.setBackgroundColor(oldBg);
		
		Retangulo retangulo = new Retangulo(new Ponto(0, 0), 3, 3);
		retangulo.setCorDeFrente(newFg);
		retangulo.setCorDeFundo(newBg);
		retangulo.desenha(terminal);
		
		assertEquals(oldFg, terminal.getForegroundColor());
		assertEquals(oldBg, terminal.getBackgroundColor());
	}
	
	@Test
	public void desenhaRetangulo() {
		TextColor oldFg = TextColor.ANSI.CYAN_BRIGHT;
		TextColor oldBg = TextColor.ANSI.RED;

		TextColor newFg = TextColor.ANSI.GREEN_BRIGHT;
		TextColor newBg = TextColor.ANSI.MAGENTA;

		terminal.setForegroundColor(oldFg);
		terminal.setBackgroundColor(oldBg);
		
		Retangulo retangulo = new Retangulo(new Ponto(0, 0), new Ponto(2, 3));
		retangulo.setCorDeFrente(newFg);
		retangulo.setCorDeFundo(newBg);
		retangulo.setCaractere('@');
		retangulo.desenha(terminal);
		terminal.draw();
		
		for (int y = 0; y <= 3; y++) {
			for (int x = 0; x <= 4; x++) {
				if (x <= 2 && y <= 3) {
					TextCharacter info = terminal.getCharacterInfo(x, y);
					assertEquals("@", info.getCharacterString());
					assertEquals(newFg, info.getForegroundColor());
					assertEquals(newBg, info.getBackgroundColor());
				} else {
					assertEquals(" ", terminal.getCharacter(x, y));
				}
			}
		}
	}
}
