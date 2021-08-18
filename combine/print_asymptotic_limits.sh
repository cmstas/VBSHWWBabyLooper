usage()
{
    echo "Usage:"
    echo ""
    echo "   >  $0 TAG"
    echo ""
    echo ""
    exit
}

tag=$1

if [ -z $tag ]; then
    usage
fi

COUPLING=c2v

print_limits()
{
    var=exp
    idx=$1
    tail -n7 limits/${tag}/${COUPLING}_*/bdt_${var}.out | grep "r\|${var}" | paste -d" " - - - - - - - | awk '{print $2, $'${idx}'}' | sed 's|limits/'${tag}'/c2v_||' | sed 's|/bdt_exp.out||' | tr 'm' '-' | tr 'p' '.' | sort -g
}

function col {
if [ $# -lt 1 ]; then
    echo "usage: col <col #>"
    return 1
fi
num=$1

if [[ $num -lt 0 ]]; then 
    awk "{print \$(NF+$((num+1)))}"
else
    awk -v x=$num '{print $x}'
fi
}

OUTPUT=limits/${tag}_asymptotic_results.py

rm -rf ${OUTPUT}
echo "import numpy as np" >> ${OUTPUT}
echo "mv   = np.array([$(print_limits 18  | col 1 | tr '\n' ' ' | tr ' ' ',')])" >> ${OUTPUT}
echo "lov  = np.array([$(print_limits 18  | col 2 | tr '\n' ' ' | tr ' ' ',')])" >> ${OUTPUT} # TODO: UPDATE
echo "lm2v = np.array([$(print_limits  8  | col 2 | tr '\n' ' ' | tr ' ' ',')])" >> ${OUTPUT}
echo "lm1v = np.array([$(print_limits 13  | col 2 | tr '\n' ' ' | tr ' ' ',')])" >> ${OUTPUT}
echo "lev  = np.array([$(print_limits 18  | col 2 | tr '\n' ' ' | tr ' ' ',')])" >> ${OUTPUT}
echo "lp1v = np.array([$(print_limits 23  | col 2 | tr '\n' ' ' | tr ' ' ',')])" >> ${OUTPUT}
echo "lp2v = np.array([$(print_limits 28  | col 2 | tr '\n' ' ' | tr ' ' ',')])" >> ${OUTPUT}
