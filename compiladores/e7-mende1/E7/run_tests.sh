#!/bin/bash
# no parameter
# Use make compile to generate "interpreta" before running this script.

T1=$(pwd)
tests="$T1/tests"

# The function total_files reports a total number of files for a given directory. 
function total_files {
        find $1 -type f | wc -l
}

# Copy the executable file "interpreta" to the tests folder.
cp "$T1/interpreta" $tests

# Get the tests in folder inputs
cd "$tests"
mytests=$(ls *.in)

echo "running tests for E7  .."

for t in $mytests; do
    name="$(basename $t .in).out"
    ora="$(basename $t .in).ora"
    echo "running $t ..."
    ./interpreta < "$tests/$t" > "$tests/$name"
    n1=`diff -bB -iw "$tests/$name" "$tests/$ora" | grep "^>" | wc -l`
    n2=`diff -bB -iw "$tests/$name" "$tests/$ora" | grep "^<" | wc -l`
    if [[ $n1 -eq 0 ]] && [[ $n2 -eq 0 ]] ; then
        echo "PASS"
    else
        echo "FAIL"
    fi
done

rm "$tests/interpreta"
rm "$T1/interpreta"
rm "$T1/lex.yy.c"
rm "$T1/e7.tab.c"
rm "$T1/e7.tab.h"
cd "$T1"

