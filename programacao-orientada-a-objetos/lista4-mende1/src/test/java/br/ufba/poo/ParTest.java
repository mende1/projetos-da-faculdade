package br.ufba.poo;

import static org.junit.Assert.assertTrue;

import org.junit.Test;

public class ParTest {
  @Test
  public void combinadorEhDoTipoCorreto() {
    try {
      Class<?> c = Class.forName("br.ufba.poo.Combinador");
      assertTrue(c.isInterface());
    } catch (ClassNotFoundException e) {
      throw new RuntimeException("Combinador não encontrado.");
    }
  }

  @Test
  public void todasAsClassesEInterfacesForamCriadas() {
    try {
      Class.forName("br.ufba.poo.Par");
    } catch (ClassNotFoundException e) {
      throw new RuntimeException("Par não encontrado.");
    }
    try {
      Class.forName("br.ufba.poo.Combinador");
    } catch (ClassNotFoundException e) {
      throw new RuntimeException("Combinador não encontrado.");
    }
  }

  @Test
  public void checaUsoDeTiposGenericos() {
    try {
      Class<?> c = Class.forName("br.ufba.poo.Combinador");
      String assinatura = c.toGenericString();
      assertTrue("Combinador deve usar generics.", assinatura.matches("^.*interface\\s+br.ufba.poo.Combinador\\s*<[^,]+>\\s*$"));
    } catch (ClassNotFoundException e) {
      throw new RuntimeException("Combinador não encontrado.");
    }
    try {
      Class<?> c = Class.forName("br.ufba.poo.Par");
      String assinatura = c.toGenericString();
      assertTrue("Par deve usar generics.", assinatura.matches("^.*class\\s+br.ufba.poo.Par\\s*<[^,]+>\\s*$"));
    } catch (ClassNotFoundException e) {
      throw new RuntimeException("Par não encontrado.");
    }
  }
}