package br.ufba.poo;

import static org.junit.Assert.assertEquals;

import org.junit.Before;
import org.junit.Test;
import org.mockito.Mockito;

import com.googlecode.lanterna.terminal.DefaultTerminalFactory;
import com.googlecode.lanterna.terminal.Terminal;
import com.googlecode.lanterna.terminal.virtual.DefaultVirtualTerminal;

import br.ufba.myterminal.MyTerminal;

public class TelaTest {
	DefaultTerminalFactory defaultTerminalFactory = new DefaultTerminalFactory();
	Terminal lanternaTerminal;
	MyTerminal terminal;
	
	@Before
	public void setup() {
		lanternaTerminal = Mockito.spy(DefaultVirtualTerminal.class);
		terminal = new MyTerminal(lanternaTerminal);
	}

	@Test
	public void aoAdicionarDoisRetangulosOUltimoEhDesenhadoPorCima() {
		Tela tela1 = new Tela();
		Retangulo r1 = new Retangulo(new Ponto(0, 0), 11, 5);
		tela1.addRetangulo(r1);
		Retangulo r2 = new Retangulo(new Ponto(3, 2), 11, 5);
		r2.setCaractere('@');
		tela1.addRetangulo(r2);
		tela1.addRotulo(new Rotulo(new Ponto(20, 1), "Alo mundo"));
		tela1.desenha(terminal);
		terminal.draw();
		
		assertEquals("" + r1.getCaractere(), terminal.getCharacter(0, 0));
		assertEquals("" + r2.getCaractere(), terminal.getCharacter(3, 2));
	}
	
	@Test
	public void listaDeRetangulosNaoPodeSerModificada() {
		Tela tela1 = new Tela();
		try {
			tela1.getRetangulos().add(new Retangulo(new Ponto(0, 0), 2, 2));
		} catch (Throwable e) {
		}
		assertEquals(0, tela1.getRetangulos().size());
	}
	
	@Test
	public void listaDeRotulosEhInicialmenteVazia() {
		assertEquals(0, new Tela().getRotulos().size());
	}
	
	@Test
	public void aoTrocarDeTelaATelaAnteriorEhApagada() {
		Tela tela1 = new Tela();
		tela1.addRotulo(new Rotulo(new Ponto(0, 0), "alo"));
		tela1.desenha(terminal);
		terminal.draw();
		
		Tela tela2 = new Tela();
		tela2.addRotulo(new Rotulo(new Ponto(0, 1), "zzz"));
		tela2.desenha(terminal);
		terminal.draw();
		
		assertEquals(" ", terminal.getCharacter(0, 0));
	}
}
