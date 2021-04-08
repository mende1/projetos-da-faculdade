package br.ufba.poo;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    /**
     * 
     * Faz a abertura de algum arquivo
     * Pronto para fazer a análise do arquivo
     * 
     * @param path String
     * @return Scanner com arquivo já aberto
     */
    public static Scanner lerArquivo (String path) {

        try {
            File file = new File(path);

            return new Scanner(file);

        } catch (FileNotFoundException e) {
            System.out.println("\nArquivo não encontrado!");
            return null;
        }
    }

    /**
     * 
     * Recebe o leitor do arquivo, e a partir dele faz a leitura
     * Criando os objetos da Universidade, Cursos e Disciplinas
     * 
     * @param reader Scanner
     * @param nomeDaUniversidade String
     * @return Universidade criada
     */
    public static Universidade criaUniversidade (Scanner reader, String nomeDaUniversidade) {

        Universidade universidade = new Universidade(nomeDaUniversidade);
        
        int qntCursos = Integer.parseInt(reader.nextLine());
        for (int i=0; i<qntCursos; i++) {
            
            String nome = reader.nextLine();
            int codigo = Integer.parseInt(reader.nextLine());
            Curso curso = new Curso(nome, codigo);
            
            int qntDisciplinas = Integer.parseInt(reader.nextLine());
            
            for (int j=0; j<qntDisciplinas; j++) {
                
                String nomeDisc = reader.nextLine();
                String info = reader.nextLine();
                String[] separador = info.split(" ");
                
                String codigoDisc = separador[0];
                int semestre = Integer.parseInt(separador[1]);
                String natureza = separador[2];
                int ch = Integer.parseInt(separador[3]);
                String curriculo = separador[4];
                
                Disciplina disciplina = new Disciplina(nomeDisc, codigoDisc, semestre, natureza, ch, curriculo);
                
                curso.addDisciplina(disciplina);
            }

            universidade.addCurso(curso);
        }

        reader.close();

        return universidade;
    }

    public static void main (String[] args) {
 
        Scanner leitor = lerArquivo("./src/main/resources/dados.txt");

        try {
            Universidade ufba = criaUniversidade(leitor, "Universidade Federal da Bahia (UFBA)");

            // Posso imprimir apenas a faculdade com imprime();
            // E também imprimir todos os cursos e matérias dessa faculdade com imprimeTudo();
    
            //ufba.imprimeTudo();
            ufba.imprime();
    
            ArrayList<Curso> cursos = ufba.getCursos();
    
            for (Curso curso : cursos) {
                curso.imprime();
                ArrayList<Disciplina> disciplinas = curso.getDisciplinas();
    
                for (Disciplina disciplina : disciplinas) {
                    disciplina.imprime();
                }
            }
    
        }
        catch (Throwable e) {
            System.out.println("Erro encontrado... Fechando o programa...\n");
            return;
        }

    }
}
        