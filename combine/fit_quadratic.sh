#!/bin/bash

# Parse the yield values from the data cards to create a data.dat file with two
# columns where first column is c2v value and the second column is the signal
# yields. In this case, the "bin2" is used (i.e. mu+l+ channel)
grep "rate" datacards/bdt_c2v*/*bin2.txt | \
    sed 's|.*bdt_c2v|\ |' | \
    tr 'p' '.' | tr 'm' '-' | \
    sed 's/\/datacard[^:]*/ /' | \
    awk '{print $1", "$3}' > data.dat;

# then use the data.dat file with two columns (c2v and signal yields) to fit a
# quadratic and parse the output result to obtain f(x) = ax^2 + bx + c
printf '%s\n' 'fit a*x**2 + b*x + c "data.dat" via a, b, c' | \
    gnuplot 2>&1 | \
    grep '+/-' | \
    awk '{print $3}' | \
    tr '\n' ' ' | \
    awk '{print $1"*c2v^2 "$2"*c2v +"$3}'
