#!/bin/bash
echo "enter number to write table:"
read n
echo "$n's table is:"
for(( i=1;i<=10;i++))
do
	echo "`expr $n \* $i`"
done
