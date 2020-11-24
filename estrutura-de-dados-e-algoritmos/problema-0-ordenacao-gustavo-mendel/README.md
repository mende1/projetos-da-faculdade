[![Work in Repl.it](https://classroom.github.com/assets/work-in-replit-14baed9a392b3a25080506f3b7b6d57f295ec2978f6f33ec97e36a161684cbe9.svg)](https://classroom.github.com/online_ide?assignment_repo_id=3297617&assignment_repo_type=AssignmentRepo)
# Problema 0
## Algoritmos de Ordenação

***Objetivo***: 
- Aprofundar o estudo dos algoritmos de ordenação e sua análise de complexidade;
- Construir um programa do zero na linguagem C++;
- Consolidar o entendimento do ambiente computacional utilizado na disciplina;
- Pesquisar alternativas mais complexas para um problema básico já conhecido.

***O Problema***:

Desde 27 de novembro de 2014 o CONATRAN estabeleceu como novo padrão oficial de *Placa de Identificação Veicular*  ou *PIV* o sistema alfanumérico composto por quatro letras e três números, no formato ABC1D23, também conhecido como *Padrão Mercosul*, por seguir a diretiva e ostentar o emblema do bloco econômico, conforme as regras da Resolução 780 de 2019. O novo padrão substitui o anterior, não mais emitido, mas ainda válido, com três letras e quatro números, no formato ABC·1234, que iniciou-se em 1990 e que seguia a Resolução 231 de 2007 do Denatran.

O novo formato da *PIV* garante uma identificação única a todos os veículos que circulam pelos países do Mercosul. Dessa forma é possível criar uma base de dados única para consulta e rastreamento de veículos. Mas para que qualquer consulta possa ser realizada com maior eficiência e rapidez é interessante que a base de dados esteja ordenada. Por se tratar de um código que envolve letras e dígitos uma ordenação lexicográfica da *PIV* deve ser feita. 

Por se tratar de uma base de dados que poderá ter da ordem de 456.976.000 de combinações/placas possíveis, é interessante utilizar algoritmos de ordenação cuja complexidade seja menor que `O(n²)`. Algoritmos `O(n.log(n))` são interessantes, no entanto para uma base tão grande o melhor seria se algoritmos lineares (ou quase) pudessem ser aplicados. 

***A Atividade***: 

1. Pesquise algoritmos de ordenação que sejam capazes de ordenar lexicograficamente sequencias alfanuméricas. 
2. Analise os algoritmos que voce encontrar e escolha um que voce considerar mais eficiente para o problema proposto. 
3. Construa um programa de teste que permita ler uma base de dados de placas no formato da *PIV Padrão Mercosul* (sem repetições) e que gere como saída uma outra base de dados com essas placas ordenadas lexicograficamente.  

***A Implementação***:

A implementação deve ser desenvolvida em linguagem C++ ANSI.

Utilize se possível o conceito de modularização utilizado nas aulas de laboratório.

O código fonte gerado deve ser comentado e legível. 

Procure fazer `commits` sempre que finalizar uma etapa da implementação. 

Ao final do processo, submeta sua versão final dando um `pull request` no seu repositório, `branch` do repositório do problema. 


***Referencias Bibliográficas***: 

* Cormen, Thomas, Charles Leiserson, and Ronald Rivest. Algoritmos - Teoria e Prática. Elsevier Brasil, 3ª Edição, 2012.
* R.Sedgewick. Algorithms, Addison-Wesley Professional, 4th Edition, 2011.

