#!/bin/bash

user=$(whoami)
testenv=$(pwd)
inputs=/tests
outputs=/tests/outputs

# The function total_files reports a total number of files for a given directory. 
function total_files {
        find $1 -type f | wc -l
}

cd "$testenv$inputs"
echo
echo "- `total_files "$testenv$inputs"` analisados"
echo

#cd $testenv
#mkdir "$testenv$outputs"

#cd "$testenv$inputs"
mytests=$(ls)

cd $testenv
for t in $mytests; do
    name=$(basename $t .in)
    echo "- $t: "
    ./blite < "$testenv$inputs/$t"
    echo
done