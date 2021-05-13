package br.ufba.poo;

import static org.junit.Assert.assertTrue;

import java.lang.reflect.Method;
import java.lang.reflect.Modifier;

import org.junit.Test;

public class AlunoTest {
  @Test
  public void ehImpossivelAlterarANotaAposInstanciacao() {
    try {
      assertTrue(Modifier.isPrivate(Aluno.class.getDeclaredField("nota").getModifiers()));
    } catch (NoSuchFieldException | SecurityException e) {
      throw new RuntimeException(e);
    }

    try {
      Method m = Aluno.class.getDeclaredMethod("setNota", double.class);
      assertTrue(Modifier.isPrivate(m.getModifiers()));
    } catch (NoSuchMethodException | SecurityException e) {
    }
  }


  @Test
  public void testaComNotaValida() {
    new Aluno("abc", 0.0);
    new Aluno("abc", 10.0);
    new Aluno("abc", 5.0);
  }

  @Test
  public void todasAsClassesForamCriadas() {
    try {
      Class.forName("br.ufba.poo.NotaInvalidaException");
    } catch (ClassNotFoundException e) {
      throw new RuntimeException("Classe NotaInvalidaException não encontrada.");
    }
    try {
      Class.forName("br.ufba.poo.Aluno");
    } catch (ClassNotFoundException e) {
      throw new RuntimeException("Classe Aluno não encontrada.");
    }
  }
}