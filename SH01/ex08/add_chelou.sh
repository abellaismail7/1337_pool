#!/bin/sh

base1="'\\\"?!"
base2="mrdoc"


n1=$(echo "$FT_NBR1" | sed -e "y/$base1/01234/" )
n2=$(echo "$FT_NBR2" | tr "$base2" '01234' )

bases="ibase=5;obase=D"

echo "$bases;$n1 + $n2" | bc | sed -e 'y/0123456789ABC/gtaio luSnemf/'

