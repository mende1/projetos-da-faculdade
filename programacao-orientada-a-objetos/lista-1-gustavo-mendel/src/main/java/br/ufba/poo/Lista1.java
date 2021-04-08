package br.ufba.poo;

import java.io.File;

/**
 * Primeira lista de exercícios de fixação
 */
public class Lista1 {

	/**
	 * Retorna a média aritmética entre dois números.
	 * 
	 * @param a primeiro número
	 * @param b segundo número
	 * @return a média aritmética entre <code>a</code> e <code>b</code>
	 */
	public static double media (double a, double b) {

		return (a + b) / 2;
	}

	/**
	 * Retorna o maior dos elementos de um array.
	 * 
	 * @param elementos array de números inteiros
	 * @return o valor do maior elemento, ou <code>Integer.MIN_VALUE</code> caso o
	 *         array seja vazio
	 */
	public static int maior(int[] elementos) {

		int max = Integer.MIN_VALUE;

		for (int i : elementos) {
			if (i > max) {
				max = i;
			}
		}

		return max;
	}

	/**
	 * Retorna a primeira letra de um nome.
	 * 
	 * @param nome nome; pode ser <code>null</code>
	 * @return o primeiro caracter de um nome (em letra minúscula), ou espaço em
	 *         branco caso o nome seja <code>null</code> ou uma string vazia
	 */
	public static char primeiraLetra(String nome) {

		if ( nome == null) {
			return ' ';
		}

		else if (nome.length() != 0) {
			return nome.toLowerCase().charAt(0);
		}

		return ' ';
	}

	/**
	 * 
	 * @param nomeDoArquivo nome do arquivo; não pode ser nulo
	 * @return Indica se o nomeDoArquivo representa o nome de um arquivo PDF
	 */
	public static boolean ehPdf(String nomeDoArquivo) {

		if (nomeDoArquivo.length() != 0) {

			String names = nomeDoArquivo.toLowerCase();

			if (names.charAt(names.length() - 1) == 'f') {

				if (names.charAt(names.length() - 2) == 'd') {

					if (names.charAt(names.length() - 3) == 'p') {

						return names.charAt(names.length() - 4) == '.';
					}
				}
			}
		}

		return false;
	}

	/**
	 * Dado um arquivo, torna-o executável. Se o arquivo não existir, não faz nada.
	 * 
	 * @param File Arquivo
	 */
	public static void tornaExecutavel(File arquivo) {

		if (arquivo.exists()) {
			arquivo.setExecutable(true);
		}
	}

	/**
	 * Verifica se a senha digitada está correta.
	 * 
	 * @param senhaCorreta  senha correta
	 * @param senhaDigitada senha digitada pelo usuário
	 * @return <code>true</code> se as duas senhas são iguais; <code>false</code>
	 *         caso contrário
	 */
	public static boolean validaSenha(String senhaCorreta, String senhaDigitada) {

		return senhaCorreta.equals(senhaDigitada);
	}

	public static void main(String[] args) {

		System.out.println(media(2.0, 8.0));
	}
}
