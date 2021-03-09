package br.ufba.poo;

import static org.mockito.Mockito.mock;
import static org.mockito.Mockito.never;
import static org.mockito.Mockito.verify;
import static org.mockito.Mockito.when;

import java.io.File;

import org.junit.Test;

public class TornaExecutavelTest {

	@Test
	public void arquivoNaoExiste() {
		File file = mock(File.class);
		when(file.exists()).thenReturn(false);
		Lista1.tornaExecutavel(file);
		verify(file, never()).setExecutable(true);
	}
}
