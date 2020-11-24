all: main

CPP_FLAGS = -Wall -g

FONTES = src/main.cpp src/sortAlg.cpp
OBJETOS = $(FONTES:.cpp=.o)

main: $(OBJETOS)								# função principal de ordenação
	g++ $(CPP_FLAGS) $(OBJETOS) -o main
	./main
	rm -f $(OBJETOS) main

gerarPlacas: src/gerarPlacas.cpp				# geração de placas aleatórias
	g++ -o dados.out src/gerarPlacas.cpp
	./dados.out
	rm dados.out

teste: teste.cpp
	g++ -o teste.out teste.cpp
	./teste.out
	rm teste.out