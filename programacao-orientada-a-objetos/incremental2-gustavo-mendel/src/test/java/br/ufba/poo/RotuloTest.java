package br.ufba.poo;

import static org.junit.Assert.assertEquals;

import org.junit.Before;
import org.junit.Test;
import org.mockito.Mockito;

import com.googlecode.lanterna.TextColor;
import com.googlecode.lanterna.terminal.DefaultTerminalFactory;
import com.googlecode.lanterna.terminal.Terminal;
import com.googlecode.lanterna.terminal.virtual.DefaultVirtualTerminal;

import br.ufba.myterminal.MyTerminal;

public class RotuloTest {
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
}
