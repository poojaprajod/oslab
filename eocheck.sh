#!bin/bash
clear
echo "ENTER A NUMBER  :  "
read  n
if [ `expr $n % 2` -eq 0 ]; then
echo "EVEN"
else 
echo "ODD"
fi 
