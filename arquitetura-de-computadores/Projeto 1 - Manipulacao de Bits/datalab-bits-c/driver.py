#!/usr/bin/python3

import os
import sys
import re

funcs       = ['bitXor', 'allEvenBits', 'logicalShift',   'logicalNeg', 'tmax', 'twosBits' ]
scores      = [1,        2,             2,                3,            1,              3           ]
max_opers   = [14,       12,            20,              12,            4,             15          ]

os.system("chmod +x ./dlc")

ret = os.system('make 1>/dev/null 2> ./.make.err')

# error compiling
if ret != 0:
    print('ERROR: cannot compile your code:\n')
    print(open('./.make.err').read())
    os.remove('./.make.err')
    sys.exit(1)

try:
  os.remove('./.make.err')
except:
  pass

# check for ANSI compatibility
#gcc_out = os.popen('gcc -fsyntax-only -ansi -pedantic bits.c')
#print(gcc_out)

# make sure btest program was generated
if not (os.path.isfile("./btest") and os.access("./btest", os.X_OK)):
    print("ERROR: No executable btest binary.\n")
    sys.exit(1)

# make sure that an executable dlc (data lab compiler) exists
if not (os.path.isfile("./dlc") and os.access("./dlc", os.X_OK)):
    print("ERROR: No executable dlc binary.\n")
    sys.exit(1)

status_tab = {}
for f in funcs:
    btest_out = os.popen('./btest -f '+f).read()
    if 'failed' in btest_out:
        status_tab[f] = 'Error'
    else:
        status_tab[f] = 'OK'

# check for code violations
dlc_out = os.popen('./dlc -W1 bits.c 2>&1').read()

if 'parse error' in dlc_out:
    print('ERROR: Failed to parse code. Make sure all your variable declarations appear before any statement that is not a declaration.\n')
    sys.exit(1)

if 'Assertion failed' in dlc_out and 'longness==2' in dlc_out:
    print('ERROR: No constants larger than 8 bits (i.e., 0-255 inclusive) are allowed.\n')
    print('Output: ', dlc_out)
    sys.exit(1)

matches = re.findall('[0-9]+:(\w+):(.*)', dlc_out)
for m in matches:
    if 'Illegal' in m[1]:
      status_tab[m[0]] = m[1].strip()

#print(status_tab)

# count operators
dlc_out = os.popen('./dlc -W1 -e bits.c').read()
matches = re.findall('[0-9]+:(\w+):.*?([0-9]+)', dlc_out)
oper_tab = {}
for m in matches:
    num_op = int(m[1])
    oper_tab[m[0]] = num_op

max_score = sum(scores)+len(scores)
corr_total = 0
perf_total = 0
score_total = 0
total_opers = 0 

output = [['Corr. Points', 'Perf. Points', 'Max. Points','Ops', 'Function', 'Status']]

k = 0
for f in funcs:
    line = []
    if 'OK' in status_tab[f]:
        score_total += scores[k]
        corr_total += scores[k]
        #print(scores[k], end = '\t')
        line += [scores[k]]

        total_opers += oper_tab[f]
        if oper_tab[f] <= max_opers[k]:
            #print('1', end = '\t')
            line += ['1']
            score_total += 1
            perf_total += 1
        else:
            line += ['0']
            status_tab[f] += ' - Warning: %d operators exceeds max of %d' % (oper_tab[f], max_opers[k])

    else:
      line += [0]
      line += [0]

    line += [scores[k]+1, oper_tab[f], f, status_tab[f]]

    output += [line]

    k += 1

#print (output)

for row in output:
    print("{: >15} {: >15} {: >15} {: >10} {: >15} {: <40}".format(*row))

print('Score = %d/%d [%d/%d Corr + %d/%d Perf] (%d total operators)' % (score_total, max_score, corr_total, sum(scores), perf_total, len(scores), total_opers))

