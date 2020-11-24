[![Work in Repl.it](https://classroom.github.com/assets/work-in-replit-14baed9a392b3a25080506f3b7b6d57f295ec2978f6f33ec97e36a161684cbe9.svg)](https://classroom.github.com/online_ide?assignment_repo_id=328391&assignment_repo_type=GroupAssignmentRepo)
# Problema 1

## Gerenciando listas de reprodução geradas automáticamente

### Motivação:

O uso de listas de reprodução (*playlists*) hoje é bastante comum em aplicações que gerenciam mídias como audio e vídeo. Com elas um usuário é capaz de fazer seleções de musicas baseadas, por exemplo, em critérios como estilo musical, artista, duração, classificação, etc.

É comum que aplicações de gerenciamento de mídias forneçam também algumas opções de listas de reprodução pré-definidas, como "top tracks", lançamentos, estilo, etc. 

### O Problema:

Você foi contactado por uma startup, que já desenvolve aplicações para plataformas de realidade aumentada (RA), e deseja entrar no mercado de gerenciamento de streaming de audio e vídeo. Eles querem projetar *apps* que rodem em dispositivos como o MS HoloLens [1] e, futuramente, no iGlass da Apple [2]. Aplicações de RA tem uma  alta demanda de processamento para registro e alinhamento de informações no ambiente real. Portanto, aplicações não críticas devem ser leves e consumirem poucos recursos computacionais. 

Como primeiro passo no desenvolvimento do *app*, a empresa quer testar alguns módulos básicos, entre eles o gerenciador de *playlists*, em termos de consumo de memória e tempo de processamento. A partir da base de dados de músicas do usuário (obtida durante o seu *login* no *app*) algumas *playlists* devem ser geradas para apresentação ao usuário. A base de dados contem as seguintes informações: nome do artista/banda e seu estilo musical; para cada album seu nome, ano de lançamento e quando foi incluido na base de dados do usuário; e para cada faixa do album, seu numero, nome, duração, número de reproduções, avaliação (de 0 a 5 estrelas) e a data da ultima execução.

A partir dessa base de dados, o módulo de geração de *playlists* deve produzir as seguintes organizações: 

1. **Top n faixas** - as **n** músicas mais bem cotadas e mais ouvidas da base de dados. O valor de **n** será parametrizado como uma preferencia do usuário, definida na aplicação.

2. **Acabei de baixar** - as faixas mais recentemente incluidas na base de dados.

3. **Acabei de escutar** - as faixas que foram reproduzidas mais recentemente.

4. **Não escuto a muito tempo** - as faixas que são bem classificadas mas que não são reproduzidas a muito tempo. 

Essas *playlists* são sempre geradas no *login* do usuário, mas poderão ser atualizadas por solicitação do usuário, através da *interface* do *app* (botão de *refresh*).

### O Resultado Esperado:

Sua equipe de desenvolvimento deverá, no prazo de 2 semanas, apresentar um protótipo aos diretores da startup, demonstrando sua eficiencia em termos de armazenamento dos dados e tempo de processamento/gasto energético. Para tanto, os diretores solicitaram uma apresentação, de no máximo 10 minutos, onde a(s) estrutura(s) de dados e os algoritmos propostos devem ser analisados. Por se tratarem de diretores que são exímios programadores, as partes mais importantes do código fonte devem analisadas na apresentação.    

### Requisitos Técnicos: 

A implementação deve ser feita utilizando a linguagem C++. 
Os códigos fonte produzidos devem ser armazenados em repositório GitHub. 
A base de dados de músicas para a geração das *playlists* será lida a partir de um arquivo no formato CSV [6]. A startup irá fornecer uma base de exemplo para a identificação do formato de entrada (ordem dos campos). Considera-se que o formato do arquivo de entrada será sempre válido.
Para os testes, o protótipo deve ser capaz de ler qualquer bases de dados fornecidos pelo usuário. 
O protótipo deve gerar como saída, arquivos no mesmo formato CSV, contendo as *playlist* montadas, em arquivos separados, nomeados com base no nome da base da dados fornecida.

### Avaliação: 

A equipe será avaliada ao longo de todo o processo de desenvolvimento: 

- De forma global pelo resultado alcançado (protótipo e apresentação) e
- De forma individual, com base na participação nas reuniões de trabalho (sessões tutoriais PBL), no cumprimento das metas estabelecidas e nas contribuições individuais durante o problema (relatório de cada sessão). 


### Referencias:

[1] https://www.youtube.com/watch?v=EIJM9xNg9xs

[2] https://www.youtube.com/watch?v=Xp0H84sWRqU

[3] T.H.Cormen, C.E.Leiserson, R.L.Rivest, C.Stein. Algoritmos – Teoria e Prática. Editora Campus. 3a Edição, 2012.

[4] R.Sedgewick. Algorithms, Addison-Wesley Professional, 4th Edition, 2011.

[5] Drozdek, Adam. Data structures and algorithms in C++, Cengage Learning, 4th Edition, 2013.

[6] https://pt.wikipedia.org/wiki/Comma-separated_values
