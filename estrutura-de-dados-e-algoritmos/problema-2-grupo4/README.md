# Problema 2 - Ray Tracing de Curvas Implícitas

## O sistema de janelas

O código base fornecido nesse repositório utiliza duas bibliotecas gráficas para a visualização da estrutura de dados que será criada.

Para compilar o código base é necessário possuir na sua instalação os arquivos binários das bibliotecas e também os arquivos de *headers* na instalação do seu compilador. Nos links abaixo são descritos os procedimentos de instalação nos ambientes:

* Windows - https://www.ft.unicamp.br/~magic/opengl/instala-windows.html
* Linux - https://askubuntu.com/questions/96087/how-to-install-opengl-glut-libraries

O desenvolvimento de aplicações em ambientes de janelas é um pouco diferente dos programas com entrada e saída via terminal. O modelo utilizado em janelas é **baseado em eventos**. O programa cria e configura uma janela, define as *callbacks*, rotinas que respondem aos eventos da janela, como desenho, redimensionamento, teclas pressionadas, movimento e cliques do mouse, entre outros. Esse controle é feito pela biblioteca GLUT e esta encapsulado na classe **cOpenGLWindow**. 

```
cOpenGLWindow win(500, 500);          // Cria uma janela de tamanho 500x500 pixels

	win.setDomain(cQuad(cPoint(-3.0f, -3.0f), cPoint(3.0f, 3.0f), BLUE)); // Define o domínio que será desenhado na janela 

	win.init(argc, argv);               // Inicialização dos parametros da janela

	win.setKeyboardFunc(myKeyboard);    // função de resposta e eventos de teclado
	win.setDisplayFunc(draw);           // função de resposta ao evento de desenho

	win.mainLoop();                     // Dispara o Loop de eventos
``` 
Caso não sejam definidas funções para nenhum evento, funções *default* são instanciadas na classe **cOpenGLWindow**. 
Importante mencionar que uma vez acionado, o *loop* de eventos não retorna mais ao programa principal, somente se a aplicação for finalizada. Ou seja, comandos colocados após o loop de eventos não serão executados senão ao final da aplicação. 

As funções de tratamento de eventos tem protótipos fixos que devem ser respeitados. Voce pode ver que parametros são esses nos exemplos das duas funções customizadas nesse código: 

``
void draw(void);
void myKeyboard(unsigned char key, int x, int y);
``
A mais importante é a *draw* que é acionada toda a vez que a janela precisa ser redesenhada (fechar e abrir, voltar ao primeiro plano, mudar de tamanho, entre outras) ou por um comando que force o evento, a função *glutPostRedisplay()*. 

```
	win.clear();				// Limpa a janela
	  		        	
	win.drawLine(cPoint(-3,-3, RED), cPoint(3,3, BLUE));	// desenha uma linha passando pelos 2 pontos fornecidos

	win.drawQuad(cQuad(cPoint(-1.0,-1.0), cPoint(1.0,1.0), MAGENTA));	// desenha um quadrado com pontos min e max de cor MAGENTA

	win.draw();				// efetiva o desenho na janela
```
Todos os comandos que gerarem desenhos na janela devem ser codificados nessa função. 

A função de tratamento de teclado típica recebe o código da tecla pressionada e o associa a uma ação, que pode resultar em mudança no desenho da janela. É o caso das teclas 'D' e 'M' nesse codigo, que modificam a função de tratamento do evento *display* da função default da classe *cOpenGLWindow* e a função customizada *draw*, respectivamente.  

```
	switch (key) {				// código da tecla pressionada
		case 27		: 	exit(0);	// tecla ESC abandona a aplicação	
					break;
						
		case 'm'	: 			
		case 'M'	: 	win.setDisplayFunc(draw);	// define a função draw como resposta ao evento display
					break;
						
		case 'd'	: 	
		case 'D'	:	win.setDisplayFuncDefault();	// define a função default da classe cOpenGlWindow
					break;
		}
	glutPostRedisplay();						// força que o evento de display ocorra, forçando o redesenho

```
Caso voce clique o *mouse* perceberá uma saida no console. Ela é produzida pela função *default* da classe *cOpenGLWindow*. Caso queira tratar eventos de clique do *mouse* voce pode customiza-la também. 

Outros eventos e funcionalidades da biblioteca glut podem ser conhecidas no manual da API da biblioteca: 

http://freeglut.sourceforge.net/docs/api.php

Lembrando porém que o foco do trabalho é a definição, construção e operação sobre a estrutura de dados que dará suporte a subdivisão adaptativa do espaço. 

## As classes de suporte

O código base também já fornece uma série de classes que darão apoio a construção da estrutura de dados de subdivisão adaptativa do espaço. São elas:

* cColor - definição de uma cor no padrão RGB;
* cPoint - um ponto no espaço 2D, com uma cor associado;
* cQuad - representa um quadrante definido por dois pontos, min e max, e que também possui uma cor associada;
* cSector - um setor representa um quadrante com uma classificação associada.

Espera-se que com esse conjunto de classe a tarefa de criar a estrutura de dados de subdivisão adaptativa do espaço torne-se mais simples. 

Estude com cuidado o código fonte e seu funcionamento. 

Qualquer dúvida entre em contato com o professor. 
