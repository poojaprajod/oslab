#!/bin/bash
inp=0
while [ $inp -lt 1 -o $inp -gt 12 ] ; do
clear
echo -n "Enter a number between 1 and 12(included) : "
read inp
done

case $inp in
1)
mon="JANUARY"
;;
2)
mon="FEBRUARY"
;;
3)
mon="MARCH"
;;
4)
mon="APRIL"
;;
5)
mon="MAY"
;;

6)
mon="JUNE"
;;
7)
mon="JULY"
;;
8)
mon="AUGUST"
;;
9)
mon="SEPTEMBER"
;;
10)
mon="OCTOBER"
;;
11)
mon="NOVEMBER"
;;
12)
mon="DECEMBER"
;;
esac

echo " $inp coresponds to $mon"  
