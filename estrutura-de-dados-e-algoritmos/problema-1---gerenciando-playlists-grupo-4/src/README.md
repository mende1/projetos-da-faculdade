# Problema 1 - Gerenciando Playlists

## Análise do Grupo
> *Por Alan Divino, Diego Carapiá, Ícaro Santana, Gabriel Andrade e Gustavo Mendel*
---

### O problema proposto

A equipe foi contrata por uma startup para apresentar uma solução viável para o gerenciamento de playlists como uma fase inicial de testes para um *app* maior que está por vir.

A partir do login de um usuário com seu banco de dados (as músicas deste usuário) o programa deve gerar outras novas playlists cada uma com sua característica de ordenação:

1. ***Top n faixas*** - as n músicas mais bem cotadas e mais ouvidas da base de dados. O valor de n será parametrizado como uma preferencia do usuário, definida na aplicação.

2. ***Acabei de baixar*** - as faixas mais recentemente incluidas na base de dados.

3. ***Acabei de escutar*** - as faixas que foram reproduzidas mais recentemente.

4. ***Não escuto a muito tempo*** - as faixas que são bem classificadas mas que não são reproduzidas a muito tempo.

A resultado esperado requer uma solução performática, eficiente, que consuma poucos recursos.

---
### A solução

A solução encontrada pela equipe foi usar a Estrutura de Dados **Lista** para Gerenciar as playlists.

O programa para a solução foi feito em C++.

A música será uma Classe, que terá como atributos seus metadados (nome, artista, albúm, data de inclusão, etc.)

A Playlist (o conjunto de músicas) será uma Classe, em que possui métodos e atributos.

Em que é armazenada nessa Classe os endereços de outras duas Classes Música, ou seja, o Objeto Playlist apontará para duas músicas, as músicas *início* e *fim*.

E cada Objeto música apontará para mais duas Músicas, *anterior* e *próxima*.

Sendo assim, usamos a ***Lista Duplamente Encadeada***, pois assim temos mais controle e facilidade de acesso a qualquer músicas que quisermos, tendo apontadores para músicas *anteriores* e *próximas* temos controle total de ida e volta.

---
### Lendo o banco de dados

Os banco de dados oferecidos para cada usuário é no formato .csv (comma-separated-values), ou seja, os valores são separados por *vírgulas*.

O programa utiliza do método fstream, disponível na linguagem C++, que nos permite leitura e escrita de arquivos.

Ao abrir o arquivos, cada linha significa uma música, e cada valor separado por vírgulas, significa um atributo de cada música na ordem certa, ou seja, temos o Nome, Artista, Albúm, Data da Última Reprodução entre outros.

O programa vai ler cada linha, e com os atributos que ele pegou, cria-se então uma nova Classe música, cada uma delas apontando para a próxima e a anterior assim como é inserida na playlist geral, que de antemão estará desordenada, do jeito que veio do arquivo csv original.

***Login do usuário***

Ao executar o programa, poderá passar por linha de comando duas variáveis, o nome do usuário e o tamanho das playlist desejado pelo usuário.

Exemplo:
```bash
./main GustavoMendel 20
```

E deve ser colocado o arquivo csv com o mesmo nome do usuário na pasta específica.

O tipo de arquivo deverá ser obrigatório do tipo **csv**, e deverá ser colocado na pasta database/ com o nome do usuário desejado seguido da extensão .csv, por exemplo: `database/GustavoMendel.csv`


Caso não seja atribuido os valores na execução, será considerado os valores padrão. O nome do database será o arquivo de teste disponibilizado pela startup , `MusicaDataBase-G4` e o tamanho padrão será `10`.

---
### Montando as playlists

Depois da leitura do arquivo, "login do usuário", e de criado os objetos músicas e inseridas no objeto Playlist geral, é hora de montar as playlists.

Cada uma das playlists terá um atributo em específico para ser analisado, e ordenar a playlist de acordo com ele.

Será analisado:

1. Na playlist **Top n faixas**, será analisado o atributo *Classificacao*, ou seja, as mais bem cotadas, com maior Classificacao, serão as primeiras. Como critério de desempate, será analisado o atributo *Reproducoes*, sendo aquelas mais ouvidas. A ordenação será Decrescente, as melhores em primeiro.

2. Na playlist **Acabei de Baixar**, será analisado o atributo *DataAdicao*, ficarão em primeiro as músicas com a Data de Adição "maior", por assim se dizer, em outras palavras, as mais recentes adicionadas. Ou seja, será uma classificação Decrescente também.

3. Na playlist **Acabei de Escutar**, será analisado o atributo *UltimaReproducao*, ficarão em primeiro as músicas com a Data da Ultima Reprodução "maior", ou seja, as mais recentes. Também será uma ordenação descrescente.

4. Na playlist **Não escuto a muito tempo**, serão analisadas as músicas que foram reproduzidas. Após isso, é levado em conta o atributo *Classificacao*, aquelas que ficarão em primeiro são aquelas com maiores Classificações. E como critério de desempate, analisa-se o atributo *UltimaReproducao*, aquelas que tiverem a Data de Última reprodução "menores", ou seja, aquelas mais antigas, ficarão em primeiro, obviamente, como critério de desempate apenas. Então, a ordenação será decrescente inicialmente analisando as Classificações, e será crescente analisando a Ultima Reprodução.

Tendo em vista todas as prioridades de ordenção para cada Playlist em específico, vamos montar então o objeto Playlist ordenada.

Após criar a playlist geral logo na leitura do arquivo, será criada uma cópia da primeira música dessa playlist, e será inserida na Playlist ordenada.

Depois é percorrido todo o restante da playlist geral, que será analisada música por música.

Cada música recolhida da playlist geral será comparada com os elementos da playlist ordenada seguindo os parâmetros de ordenação de cada playlist, citada acima.

Ela será inserida no lugar exato a que pertence sendo comparada com as músicas das playlists analisadas. Por exemplo, supondo que seja uma Playlist de músicas com maior duração, ou seja, as mais longas ficam em primeiro lugar. Ela será inserida quando achar uma música que ela tem uma duração menor, e que logo após terá uma música com a duração maior, sendo encaixada exatamente entre as músicas maiores e menores a música a ser inserida.

E então, de acordo com o tamanho que o usuário especificar logo na execução do programa, a playlist ordenada terá esse tamanho. Para poupar recursos e ser eficiente, o algoritmo já compara a música a ser inserida com a última música da playlist ordenada. Caso ela seja menor (neste caso em que a ordenação é decrescente), a música não será inserida, e não será comparada com outras, para não gastar recursos.

Caso a playlist ordenada já estiver cheia, e alguma música for inserida nela em posições acima, a música que seria a última será removida da playlist para manter o tamanho desejado.

E assim criamos uma playlist ordenada de acordo com os parâmetros desejados de cada playlist.

Após isso, será escrita essa playlist em um arquivo `<nome-do-usuario> - <tipo-da-playlist>.csv`. Do mesmo jeito, será escrito no arquivo usando o método fstream do C++, onde cada linha será uma música, e os atributos da música serão separados por vírgulas.

---
### Análise de Complexidade 

Pior caso: A playlist geral está em ordem crescente em relação ao parâmetro analisado. A cada inserção é necessário percorrer toda a playlist que ficará ordenada. Logo terá complexidade O(kn), sendo K o tamanho máximo da playlist que ficará ordenada, por exemplo, uma “Top 10 faixas” terá complexidade 10n.

Melhor caso : A playlist já estaria ordenada, fazendo apenas a inserção das músicas que atendem o requisito solicitado. Ou seja, será O(k), com K sendo o tamanho da lista gerada.

Com isso percebemos que o algoritmo tem complexidade LINEAR.

---
### Rodando o programa

Após ter colocado o arquivo .csv com as músicas lá na pasta `database/`, então está na hora de ver o programa em ação.

O usuário pode compilar todos os arquivos .cpp juntos e executar manualmente. Mas para fins de otimização, nossa equipe deixou o `Makefile` prontinho para compilar, executar e remover os arquivos objetos.

Para compilar, basta está na pasta raiz do projeto (onde se encontra o `Makefile`), e digitar:

```bash
make
```

Ele vai compilar os objetos necessários, criar o executável `main` a irá apagar os objetos, já que ele só é necessário para criar o executável.

E então, para executar, o usuário deve ir no Makefile e mudar a função `exe`, adicionando o nome do usuário (o mesmo do banco de dados) e também o tamanho, exemplo:

```Make
exe:
  ./main GustavoMendel 20
  rm main
```

Após isso, salve, e então na pasta raiz, dê o comando:

```bash
make exe
```

E pronto, o programa será executado e logo após será apagado o executável `main`, para fins de organização.

Ou para compilar e executar manualmente:

```bash
g++ -o main main.cpp musica.cpp playlist.cpp playlistOrdenacao.cpp openCsv.cpp
```

E para executar:

```bash
./main <usuario> <tamanho>
```

---