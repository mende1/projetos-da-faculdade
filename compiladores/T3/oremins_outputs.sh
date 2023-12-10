#!/bin/bash

user=$(whoami)
testenv=$(pwd)
outputs=/feedback/outputs/
outputsf=/feedback/outputsf/
outputsc=/feedback/outputsc/

# The function total_files reports a total number of files for a given directory. 
function total_files {
        find $1 -type f | wc -l
}

cd "$testenv$outputs"
echo
echo "- `total_files "$testenv$outputs"` filtrados"
echo

cd $testenv
if [ ! -d "$testenv$outputsf" ]; then
   mkdir "$testenv$outputsf"
fi
if [ ! -d "$testenv$outputsc" ]; then
   mkdir "$testenv$outputsc"
fi

#echo
#echo "run rmnl in each file"
cd "$testenv$outputs"
mytests=$(ls)
cd $testenv
for t in $mytests; do
    ./orem < "$testenv$outputs$t" > "$testenv$outputsf$t"
    ./oins < "$testenv$outputsf$t" > "$testenv$outputsc$t"
done


