#!/bin/bash
dir=$1
find $dir -size 0 -print
find $dir -size 0 -ok rm {} \;
