#!/bin/bash

user=$(whoami)
testenv=$(pwd)
outputs=/feedback/outputscopy/
outputsc=/feedback/outputsc/
oraclec=/feedback/oraclec/
mydiff=/feedback/diffc/
passou=/feedback/passou/
naopassou=/feedback/naopassou/

# The function total_files reports a total number of files for a given directory. 
function total_files {
        find $1 -type f | wc -l
}

if [ ! -d "$testenv$mydiff" ]; then
   mkdir "$testenv$mydiff"
fi
if [ ! -d "$testenv$passou" ]; then
   mkdir "$testenv$passou"
fi
if [ ! -d "$testenv$naopassou" ]; then
   mkdir "$testenv$naopassou"
fi

echo
echo "## Testes"
echo
echo "- `total_files "$testenv$oraclec"` testes"
echo

#echo "run diff in each file"
cd "$testenv$oraclec"
mytests=$(ls)
cd $testenv

echo
echo "### Resultados"
echo

for t in $mytests; do

    diff -bB -iw "$testenv$outputsc$t" "$testenv$oraclec$t" > "$testenv$mydiff$t"
    n1=`diff -bB -iw "$testenv$outputsc$t" "$testenv$oraclec$t" | grep "^>" | wc -l`
    n2=`diff -bB -iw "$testenv$outputsc$t" "$testenv$oraclec$t" | grep "^<" | wc -l`

    if [[ $n1 -eq 0 ]] && [[ $n2 -eq 0 ]] ; then
        cp "$testenv$mydiff$t" "$testenv$passou$t"
    else
        echo "- $t não passou nos testes"
        cp "$testenv$mydiff$t" "$testenv$naopassou$t"
    fi

done

echo
echo "### Resumo"
echo
echo "- `ls "$testenv$passou" | wc -l` saída(s) correta(s)"
echo "- `ls "$testenv$naopassou" | wc -l` saída(s) incorreta(s)"
echo

