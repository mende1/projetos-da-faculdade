# Problema 2 - Ray Tracing de Curvas Implícitas

## Análise do Grupo
> *Por Alan Divino, Diego Carapiá, Ícaro Santana, Gabriel Andrade e Gustavo Mendel*
---

### O problema proposto

O problema consiste em uma busca por um objeto em uma divisão de 2 dimensões, através de uma raio que passa por subdivisões que será feita nessa região a fim de otimizar o processo pela busca desse objeto.

É proposto uma subdivisão adaptativa que visa a tática "dividir para conquistar", fazendo um algoritmo inteligente para descartar grandes pedaços de área em que certamente o objeto não estará, para assim economizar recursos de máquina para realizar a procura bem otimizada.

---

### A solução

A solução então encontrada pelo grupo, foi a implementação de uma estrutura de dados, a árvore, do tipo QuadTree, para realizar os procedimentos dessa busca.

A árvore então consiste em referenciar um nó, que seria o nó raiz da árvore. Cada nó, então, referenciando a outros 4 nós.

O nó raiz, o pai de todos, seria então o domínio da imagem. E cada nó filho, vai representar uma subdivisão dessa área, sendo 1/4 da região do seu nó pai.

É então analisado os quatro vértices dos quadrados (representados por um nó), realizando um cálculo entre os vértices com a função implícita do objeto, se os 4 pontos resultar em número maior do que zero (0), então o objeto está fora da área de busca. Se os 4 pontos resultar em número menor do que zero (0), então a área de busca estará dentro do objeto, nesses dois casos a busca abortará. Se então nenhuma das condições forem atendidas, a busca vai continuar acontecendo.

---

### Ray Tracing

Será emitido um raio, de uma certa origem até um certo destino, visando achar o objeto, onde o raio irá parar quando encontrar. O objetivo será encontrar todos os quadrados em que a reta (raio) passa, até encontrar o objeto.

O algoritmo então irá analisar, se vai existir interseção entre o raio e a aresta dos quadrados. Havendo interseção ele vai continuar a busca no ramo da árvore, até encontrar uma folha (últimos nós de cada galho da árvore). Se a folha analisada pertence a curva do objeto, o programa vai encerrar a busca. Caso contrário, a busca será continuada e os quadrados por onde passou será pintado de outra cor. A lógica será repetida até que ou encontre o objeto, ou chegue no seu destino final.

---

### O porquê da subdivisão adaptativa ser melhor do que a regular

A subdivisão regular se basea em percorrer toda a estrutura da árvore para encontrar o objeto. A divisão das áreas (quadrados) seria dada de meneira igual, ou seja, todos os quadrados que foram feitos para realizar a busca teriam mesmo tamanho, e varreria de maneira igual a árvore.

Já na subdivisão adaptativa, é realizado um algoritmo inteligente para analisar e identificar grandes áreas em que já descartaria a possibilidade do objeto está ali, sendo assim, o algoritmo já iria partir para outra área e continuar a busca. Reduzindo bastante recursos da máquina, realizando a busca de maneira bem otimizada.

---

### Executando o programa

O programa utiliza da biblioteca `GL/Glut`, freeglut da OpenGL. Para instalar as bibliotecas:

* No Linux Base Debian:
```bash
sudo apt install freeglut3 freeglut3-dev -y
```
Mais informações: https://askubuntu.com/questions/96087/how-to-install-opengl-glut-libraries

* No windows, acesso o site: https://www.ft.unicamp.br/~magic/opengl/instala-windows.html

##### Organização do Código

A estrutura do código foi feita pensando no `Makefile`, que utiliza da estrutura para facilitar e otimizar o processo do usuário compilar e executar o programa.

Temos a pasta `include`, onde teremos todos nossos arquivos de include, sendo esse `.h` no nosso caso.

Temos a pasta `src`, que é onde fica o código em si, todos os arquivos `.cpp`. Separamos em duas outras pastas visando organização do código.
* `grafic` é onde ficam os códigos relacionados a biblioteca Glut e OpenGL, destinado a parte gráfica em si do programa.
* `struct` será o programa principal, onde teremos as estruturas principais, nesse caso, da árvore e dos nós da árvore.

Temos também a pasta `build`, que é onde o Makefile vai utilizar para criar os arquivos objetos, e também o executável em si.

##### O Makefile

Foi feito para utilizar a estrutura acima a seu favor, criando os arquivos objetos, compilados e executáveis em uma pasta `build`, sendo assim, toda vez que for modificado algum arquivo do programa, ele vai compilar apenas aquele modificado, mantendo os objetos compilados anteriormente.

Temos os comandos:

```bash
make

# Vai montar os arquivos objetos .o
# Gerando um executável baseCode com base nos objetos.
```

```bash
make run

# Vai executar o executável criado anteriormente `baseCode`
```

```bash
make clean

# Será excluído todos os arquivos objetos .o .d
# e executáveis da pasta build
```

```bash
make info

# Algumas informações
```

##### Visualizando o programa

Depois de compilar, e executar, será criado uma janela representando a integração do nosso algoritmo e estrutura de dados com a parte gráfica disponibilizada pela biblioteca OpenGL e Glut.

A primeira imagem será a primeira estrutura que foi definida, que foi o círculo.
Foram definidas 7 figuras ao todos. Em que podemos trocar de acordo com atalhos do teclado.

`Apertando os números, de 0 até 6, podemos trocar os objetos definidos.`

Também definimos funções com os dois botões do mouse.

`Botão esquerdo do mouse`
Será emitido o raio (Ray Tracing) para realizar a busca.
São 4 raios, que podem ser alternados clicando no botão do mouse esquerdo.
O RayTracing terá duas cores, a sua origem terá cor azul, e o destino cor vermelha.
Apenas para identificar o sentido do raio.
Também será pintado as subdivisões passadas pelo raio de AZUL CIANO.

`Botão esquerdo do mouse`
Será mostrado todas as subdivisões feitas para identificar o objeto, serão representados por quadrados cor de ROSA.