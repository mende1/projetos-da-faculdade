# Algumas Dicas para T2-T3

## Parte 1

- Revisar o blite.l para retornar tokens mais específicos, por exemplo,
%token PLUS, %token COMMA, etc., e se adequar à linguagem reduzida (B-Lite-Minus);
- Fazer o blite.y rodar sem conflitos (escrever a gramática sem ações semânticas);

## Parte 2
- Definir tipos de não-terminais e terminais no blite.y 
(usar %union, %type, e revisar declaração de alguns tokens), sem uso de ações semânticas nas regras ainda. Olhar o livro do Flex & Bison;
- Revisar o blite.l (usar tipos para ALGUNS tokens), por exemplo, yylval.d para 
token NUMBER, sendo _d_ do tipo _int_;
- Desenvolver __incrementalmente__, em especial, as ações semânticas 
para criação da AST. Por exemplo, desenvolver e testar _expression_ primeiro, etc. 
Explicações no video compartilhado - aula 30/10.

## Geral 
Pensar sobre como dividir trabalho entre os membros da equipe e usar efetivamente o GitHub,
controle de versões, commits, comentários sobre commits. Por exemplo, 
pensar em uma estratégia para trabalhar em declaration e expression em paralelo. 


