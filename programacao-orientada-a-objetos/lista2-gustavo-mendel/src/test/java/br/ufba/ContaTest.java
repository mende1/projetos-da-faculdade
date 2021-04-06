package br.ufba.poo;

import static org.junit.Assert.*;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class ContaTest {

	@Before
	public void setUp() throws Exception {
	}

	@After
	public void tearDown() throws Exception {
	}

	@Test
	public void testExisteConstrutorComCodigo() throws NoSuchMethodException, SecurityException {
		Class<Conta> classe = Conta.class;
		classe.getConstructor(String.class); 
	}
	
	@Test
	public void testAoConstruirSemSaldoOSaldoEhZero() {
		Conta conta = new Conta("123");
		assertEquals("123", conta.getCodigo());
		assertEquals(0.0, conta.getSaldo(), 0.001);
	}
	
	@Test
	public void testExisteConstrutorComCodigoESaldo() throws NoSuchMethodException, SecurityException {
		Class<Conta> classe = Conta.class;
		classe.getConstructor(String.class, double.class);
	}

	@Test
	public void testChecaAtributosDoConstrutorComDoisParametros() {
		Conta conta = new Conta("123", 3.14);
		assertEquals("123", conta.getCodigo());
		assertEquals(3.14, conta.getSaldo(), 0.001);
	}
	
	@Test
	public void testRetiraQuandoTemSaldo() {
		Conta conta = new Conta("123", 100.0);
		assertTrue(conta.retira(60.0));
		assertEquals(40.0, conta.getSaldo(), 0.001);
	}
	
	@Test
	public void testRetiraQuandoNaoTemSaldo() {
		Conta conta = new Conta("123", 50.0);
		assertFalse(conta.retira(60.0));
		assertEquals(50.0, conta.getSaldo(), 0.001);
	}
	
	@Test
	public void testDeposita() {
		Conta conta = new Conta("123", 50.0);
		conta.deposita(60.0);
		conta.deposita(10.0);
		assertEquals(120.0, conta.getSaldo(), 0.001);
	}
	
	@Test
	public void testTransfereSaldoSuficiente() {
		Conta conta = new Conta("123", 50.0);
		Conta beneficiario = new Conta("999", 10.0);
		
		assertTrue(conta.transfere(30.0, beneficiario));
		assertEquals(40.0, beneficiario.getSaldo(), 0.001);
		assertEquals(20.0, conta.getSaldo(), 0.001);
	}
	
	@Test
	public void testTransfereSaldoInsuficiente() {
		Conta conta = new Conta("123", 5.0);
		Conta beneficiario = new Conta("999", 10.0);
		
		assertFalse(conta.transfere(30.0, beneficiario));
		assertEquals(10.0, beneficiario.getSaldo(), 0.001);
		assertEquals(5.0, conta.getSaldo(), 0.001);
	}
	
	@Test
	public void testTransfereBeneficiarioNull() {
		Conta conta = new Conta("123", 5.0);
		Conta beneficiario = null;
		
		assertFalse(conta.transfere(2.0, beneficiario));
		assertEquals(5.0, conta.getSaldo(), 0.001);
	}
}
