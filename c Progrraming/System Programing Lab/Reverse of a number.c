#!/bin/bash
echo "enter a number:"
read a
n=`expr 0`
b=`expr $a`
c=`expr 0`
while [ $a -gt 0 ]
do
	a=`expr $a / 10`
	c=`expr $c + 1`
done
while [ $b -gt 0 ]
do
	n=`expr 10 \* $n + $b % 10` 
	b=`expr $b / 10`
done
echo "reverse is:$n"
	
