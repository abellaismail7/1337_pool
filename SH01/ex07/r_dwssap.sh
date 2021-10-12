#!/bin/sh

cat /etc/passwd  | \
grep -E '^[^#]' | \
awk "NR%2==0{print}" | \
cut -d ":" -f 1 | \
rev | \
sort -r | \
sed -n "$FT_LINE1,$(echo $FT_LINE2)p" | \
tr '\n' ',' | sed -e 's/,$//g' | sed -e 's/,/, /g' | tr -d '\n'
echo '.' | tr -d "\n"
