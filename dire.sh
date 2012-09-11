#!/bin/bash
nwdir=$1
if [ -d $nwdir ]
then
echo directory already exits
elif [ -f $nwdir ]
then
rm $nwdir
mkdir $nwdir
echo was a File now Directory
else
mkdir $nwdir
echo new Directory created
fi
