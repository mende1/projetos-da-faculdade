package br.ufba.poo;

import static org.junit.Assert.assertEquals;

import org.junit.Before;
import org.junit.Test;
import org.mockito.Mockito;

import com.googlecode.lanterna.TextCharacter;
import com.googlecode.lanterna.TextColor;
import com.googlecode.lanterna.terminal.DefaultTerminalFactory;
import com.googlecode.lanterna.terminal.Terminal;
import com.googlecode.lanterna.terminal.virtual.DefaultVirtualTerminal;

import br.ufba.myterminal.MyTerminal;

public class UtilsTest {
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
	public void aloMundoImprimeTextoCorreto() {
		terminal.setPosition(2, 2);
		Utils.aloMundo(terminal);
		terminal.draw();
		String expected = "Alo mundo ";
		String actual = stringAt(terminal, 2, 2, 10);
		assertEquals(expected, actual);
	}
	
	@Test
	public void aloMundoMoveCursorParaBaixo() {
		terminal.setPosition(10, 3);
		Utils.aloMundo(terminal);
		terminal.draw();
		assertEquals(4, terminal.getY());
		assertEquals(10, terminal.getX());
	}
	
	@Test
	public void desenhaRetanguloImprimeTextoCorreto() {
		int x = 2;
		int y = 3;
		int w = 5;
		int h = 3;
		terminal.setPosition(10, 3);
		Utils.desenhaRetangulo(terminal, x, y, w, h, TextColor.ANSI.WHITE);
		terminal.draw();
		
		for (int i = x - 1; i < x + w + 1; i++) {
			for (int j = y - 1; j < y + h + 1; j++) {
				if (i == x - 1 || i == x + w || j == y - 1 || j == y + h) {
					assertEquals(" ", terminal.getCharacter(i, j));
				} else {
					assertEquals("#", terminal.getCharacter(i, j));
				}
			}
		}
	}
	
	@Test
	public void desenhaRetanguloUsaCorCorreta() {
		int x = 2;
		int y = 3;
		int w = 5;
		int h = 3;
		terminal.setPosition(10, 3);
		Utils.desenhaRetangulo(terminal, x, y, w, h, TextColor.ANSI.MAGENTA);
		terminal.draw();
		
		for (int i = x; i < x + w; i++) {
			for (int j = y; j < y + h; j++) {
				TextCharacter c = terminal.getCharacterInfo(i, j);
				assertEquals(TextColor.ANSI.MAGENTA, c.getForegroundColor());
			}
		}
	}
	
	@Test
	public void desenhaRetanguloRestauraCor() {
		terminal.setForegroundColor(TextColor.ANSI.GREEN);
		Utils.desenhaRetangulo(terminal, 3, 4, 5, 6, TextColor.ANSI.MAGENTA);
		terminal.draw();
		assertEquals(TextColor.ANSI.GREEN, terminal.getForegroundColor());
	}

}
