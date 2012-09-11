d=0
while output=`find $1 -mindepth $d -maxdepth $d` && [[ -n $output ]]
do
    find $1 -mindepth $d -maxdepth $d   
    ((d++))
done
