package br.ufba.poo;

import br.ufba.myterminal.MyTerminal;

public class Main {

	public static void main(String[] args) {
		MyTerminal terminal = new MyTerminal();
		
		Tela tela1 = new Tela();
		tela1.addRetangulo(new Retangulo(new Ponto(0, 0), 11, 5));
		Retangulo r = new Retangulo(new Ponto(3, 2), 11, 5);
		r.setCaractere('@');
		tela1.addRetangulo(r);
		tela1.addRotulo(new Rotulo(new Ponto(20, 1), "Alo mundo"));

		tela1.desenha(terminal);
		terminal.draw();
	}

}
