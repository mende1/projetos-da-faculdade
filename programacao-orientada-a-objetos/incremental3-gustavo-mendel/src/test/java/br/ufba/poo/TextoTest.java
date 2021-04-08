package br.ufba.poo;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;

import org.junit.Before;
import org.junit.Test;
import org.mockito.Mockito;

import com.googlecode.lanterna.TextColor;
import com.googlecode.lanterna.terminal.DefaultTerminalFactory;
import com.googlecode.lanterna.terminal.Terminal;
import com.googlecode.lanterna.terminal.virtual.DefaultVirtualTerminal;

import br.ufba.dc.DC;
import br.ufba.dc.DCClass;
import br.ufba.myterminal.MyTerminal;

public class TextoTest {
	private DCClass cRotulo = DC.getClass("br.ufba.poo.Rotulo");
	
	DefaultTerminalFactory defaultTerminalFactory = new DefaultTerminalFactory();
	Terminal lanternaTerminal;
	MyTerminal terminal;
	
	@Before
	public void setup() {
		lanternaTerminal = Mockito.spy(DefaultVirtualTerminal.class);
		terminal = new MyTerminal(lanternaTerminal);
	}
	static String stringAt(MyTerminal terminal, int x, int y, int len) {
		StringBuffer buf = new StringBuffer();
		for (int col = x; col < x + len; col++) {
			buf.append(terminal.getCharacter(col, y));
		}
		return buf.toString();
	}
	
	@Test
	public void possuiMetodos() {
		String[] metodos = {"getOrigem", "setOrigem", "getTexto", "setTexto",
				"getCorDeFrente", "setCorDeFrente", "getCorDeFundo", "setCorDeFundo",
				"desenha"};
	
		for (String metodo : metodos) {
			assertNotNull(cRotulo.getMethod(metodo));
		}
	}
	
	@Test
	public void origem() {
		Rotulo t1 = new Rotulo("");
		
		t1.setOrigem(new Ponto(3, 4));
		
		Ponto p = t1.getOrigem();
		assertEquals(3, p.getX());
		assertEquals(4, p.getY());
	}
	
	@Test
	public void construtorVazio() {
		Rotulo t1 = new Rotulo("");
		assertEquals(TextColor.ANSI.WHITE, t1.getCorDeFrente());
		assertEquals(TextColor.ANSI.BLACK, t1.getCorDeFundo());
		assertEquals("", t1.getTexto());
		assertEquals(new Ponto(0, 0), t1.getOrigem());
	}

	@Test
	public void construtores() {
		Rotulo t1 = new Rotulo("qweasdzxc");
		assertEquals(TextColor.ANSI.WHITE, t1.getCorDeFrente());
		assertEquals(TextColor.ANSI.BLACK, t1.getCorDeFundo());
		assertEquals("qweasdzxc", t1.getTexto());
		assertEquals(new Ponto(0, 0), t1.getOrigem());
		
		Rotulo t2 = new Rotulo(new Ponto(5, 2), "qweasdzxc");
		assertEquals(TextColor.ANSI.WHITE, t2.getCorDeFrente());
		assertEquals(TextColor.ANSI.BLACK, t2.getCorDeFundo());
		assertEquals("qweasdzxc", t2.getTexto());
		assertEquals(new Ponto(5, 2), t2.getOrigem());
		
		TextColor fg = TextColor.ANSI.CYAN_BRIGHT;
		TextColor bg = TextColor.ANSI.RED;
		Rotulo t3 = new Rotulo("qweasdzxc", fg, bg);
		assertEquals(fg, t3.getCorDeFrente());
		assertEquals(bg, t3.getCorDeFundo());
		assertEquals("qweasdzxc", t3.getTexto());
		assertEquals(new Ponto(0, 0), t3.getOrigem());
		
		Rotulo t4 = new Rotulo(new Ponto(5, 2), "qweasdzxc", fg, bg);
		assertEquals(fg, t4.getCorDeFrente());
		assertEquals(bg, t4.getCorDeFundo());
		assertEquals("qweasdzxc", t4.getTexto());
		assertEquals(new Ponto(5, 2), t4.getOrigem());
	}

	@Test
	public void desenhaPreservaCores() {
		TextColor oldFg = TextColor.ANSI.CYAN_BRIGHT;
		TextColor oldBg = TextColor.ANSI.RED;

		TextColor newFg = TextColor.ANSI.GREEN_BRIGHT;
		TextColor newBg = TextColor.ANSI.MAGENTA;

		terminal.setForegroundColor(oldFg);
		terminal.setBackgroundColor(oldBg);
		
		Rotulo texto = new Rotulo("qweqwe", newFg, newBg);
		texto.desenha(terminal);
		
		assertEquals(oldFg, terminal.getForegroundColor());
		assertEquals(oldBg, terminal.getBackgroundColor());
	}
	
	@Test
	public void desenhaEscreveTexto() {
		Ponto p = new Ponto(10, 3);
		terminal.setPosition(p.getX(), p.getY());
		terminal.print("AasdasdB");
		Rotulo texto = new Rotulo(p.comDeslocamento(1, 0), "qweqwe");
		texto.desenha(terminal);
		terminal.draw();
		String x = stringAt(terminal, p.getX(), p.getY(), 8);
		assertEquals("AqweqweB", x);
	}
	
	@Test
	public void desenhaUsaCorCerta() {
		TextColor oldFg = TextColor.ANSI.CYAN_BRIGHT;
		TextColor oldBg = TextColor.ANSI.RED;

		TextColor newFg = TextColor.ANSI.GREEN_BRIGHT;
		TextColor newBg = TextColor.ANSI.MAGENTA;

		terminal.setForegroundColor(oldFg);
		terminal.setBackgroundColor(oldBg);
		
		Rotulo texto = new Rotulo("qweqwe", newFg, newBg);
		texto.desenha(terminal);
		terminal.draw();
		
		assertEquals(newFg, terminal.getCharacterInfo(0, 0).getForegroundColor());
		assertEquals(newBg, terminal.getCharacterInfo(0, 0).getBackgroundColor());
	}
}
