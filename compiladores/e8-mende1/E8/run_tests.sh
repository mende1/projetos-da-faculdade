#!/bin/bash
# no parameter
# Use make compile to generate "avalia" before running this script.

T1=$(pwd)
tests="$T1/tests"

# The function total_files reports a total number of files for a given directory. 
function total_files {
        find $1 -type f | wc -l
}

# Copy the executable file "avalia" to the tests folder.
cp "$T1/avalia" $tests

# Get the tests in folder inputs
cd "$tests"
mytests=$(ls *.in)

echo "running tests for E8  .."

for t in $mytests; do
    name="$(basename $t .in).out"
    ora="$(basename $t .in).ora"
    echo "running $t ..."
    ./avalia < "$tests/$t" > "$tests/$name"
    n1=`diff -bB -iw "$tests/$name" "$tests/$ora" | grep "^>" | wc -l`
    n2=`diff -bB -iw "$tests/$name" "$tests/$ora" | grep "^<" | wc -l`
    if [[ $n1 -eq 0 ]] && [[ $n2 -eq 0 ]] ; then
        echo "PASS"
    else
        echo "FAIL"
    fi
done

rm "$tests/avalia"
cd "$T1"

