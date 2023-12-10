#!/bin/bash

user=$(whoami)
testenv=$(pwd)
testfolder=/tests/
srcparser=/src/parser/
srclexer=/src/lexer/
feedback=/feedback
inputs=/feedback/inputs/
outputs=/feedback/outputs/
outputsc=/feedback/outputsc/
oracle=/feedback/oracle/
oraclec=/feedback/oraclec/
oracleok=/feedback/oracleok/
oraclenok=/feedback/oraclenok/
passou=/feedback/passou/
naopassou=/feedback/naopassou/
mydiff=/feedback/diffc/
mydiffTP=/feedback/TP/
mydiffTN=/feedback/TN/
mydiffFP=/feedback/FP/
mydiffFN=/feedback/FN/

function total_files {
    find $1 -type f | wc -l
}

function is_green {
    find "$testenv$passou" -name "$1" | wc -l
}

function is_OK {
    find "$testenv$oracleok" -name "$1" | wc -l
}

function is_red {
    find "$testenv$naopassou" -name "$1" | wc -l
}

function is_NOK {
    find "$testenv$oraclenok" -name "$1" | wc -l
}

echo
echo "# Correção do Trabalho T2-T3-AST  - MATA61 2023.2"
echo
 
# find, set context and run compile.sh
# echo "compiling .............................."
# "$testenv/compile_parser.sh" > compile_errors.log
# echo

if [ -f "blite" ]; then

# create feedback folder with tests
# if [ ! -d "$testenv$feedback" ]; then
#   mkdir "$testenv$feedback"
#   cp -r "$testenv$testfolder/" "$testenv$feedback"
#fi

# find, set context and run parser
echo "running ................................"
./run_parser.sh
echo

if [ "$(ls -A $testenv$outputs)" ]; then

echo
# remove newline and then 1 bracket element per line
echo "filtering .............................."
./oremins_outputs.sh
echo
# compare outputsc with oraclec
echo "comparing .............................."
./diff_parser.sh
echo

# reporta 
echo
echo "## Resultados"
echo
if [ ! -d "$testenv$mydiffTP" ]; then
   mkdir "$testenv$mydiffTP"
fi
if [ ! -d "$testenv$mydiffTN" ]; then
   mkdir "$testenv$mydiffTN"
fi
if [ ! -d "$testenv$mydiffFP" ]; then
   mkdir "$testenv$mydiffFP"
fi
if [ ! -d "$testenv$mydiffFN" ]; then
   mkdir "$testenv$mydiffFN"
fi

cd "$testenv$oraclec"
mytests=$(ls)
cd $testenv

for t in $mytests; do
    g=`is_green $t`
    r=`is_red $t`
    o=`is_OK $t`
    n=`is_NOK $t`

    if [[ $g -gt 0  &&  $o -gt 0 ]]; then
        cp "$testenv$outputsc$t" "$testenv$mydiffTP$t"
    fi

    if [[ $g -gt 0 ]] && [[ $n -gt 0 ]]; then
        cp "$testenv$outputsc$t" "$testenv$mydiffTN$t"
    fi

    if [[ $r -gt 0 ]] && [[ $o -gt 0 ]]; then
        cp "$testenv$outputsc$t" "$testenv$mydiffFN$t"
    fi

    if [[ $r -gt 0 ]] && [[ $n -gt 0 ]]; then
        cp "$testenv$outputsc$t" "$testenv$mydiffFP$t"
    fi
done

TP=`ls "$testenv$mydiffTP" | wc -l`
echo "TP: $TP"
TN=`ls "$testenv$mydiffTN" | wc -l`
echo "TN: $TN"
FP=`ls "$testenv$mydiffFP" | wc -l`
echo "FP: $FP"
FN=`ls "$testenv$mydiffFN" | wc -l`
echo "FN: $FN"
echo

A=$(( TP + FP ))
B=$(( TP + FN ))
C=$(( TP + TN ))
D=$(( TP + TN + FP + FN ))
E=$(( TN + FP ))

TPRd=$(( 100 * TP ))
TNRd=$(( 100 * TN ))

if [[ $B -gt  0 ]]; then
    Recall=$(( 100 * TP / B ))
    TPR=$(( TPRd / B ))
else
    Recall=0
    TPR=0
fi

if [[ $E -gt  0 ]]; then
    TNR=$(( TNRd / E ))
else
    TNR=0
fi

F=$(( TPR + TNR ))
BA=$(( F / 2 ))

if [[ $A -gt  0 ]]; then
    Precision=$(( 100 * TP / A ))
else
    Precision=0
fi

echo
echo \`\`\`
echo "                   -------------------------------------"
echo "                              Your parser               "
echo "                   -------------------------------------"
echo "                  | output_OK      | output_NOK         "
echo "--------------------------------------------------------"
echo " O   | oracle_OK  |  $TP (TP) |   $FP (FP)              "
echo " RA  |------------|----------------|--------------------"
echo " CLE | oracle_NOK |  $FN (FN) |   $TN (TN)              "
echo "--------------------------------------------------------"
echo \`\`\`
echo
echo
echo \`\`\`
if [[ $A -gt 0 ]]; then 
echo "Precision = TP / (TP + FP) = $(( 100 * TP / A ))"
fi
if [[ $B -gt 0 ]]; then 
echo "Recall = TP / (TP + FN) = $(( 100 * TP / B ))"
fi
if [[ $E -gt 0 ]]; then 
echo "Specificity = TN / (TN + FP) = $(( 100 * TN / E ))"
fi
if [[ $D -gt 0 ]]; then 
echo "Accuracy = (TP + TN) / (TP + TN + FP + FN) = $(( 100 * C / D ))"
fi
echo
#echo "Balanced Accuracy = $BA"
   echo \`\`\`
   echo
else
    echo "tp2_test.sh: The outputs folder is empty."
fi
else
    echo "compiling error(s): bison, flex or other."
fi
echo
echo "Done: `date`"
echo "--------------------------------------------------------"
echo

