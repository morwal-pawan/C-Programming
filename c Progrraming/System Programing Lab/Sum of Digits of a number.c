#!/bin/bash
echo "enter a number:"
read a
sum=`expr 0`
while [ $a -gt 0 ]
do
	n=`expr $a % 10`
	sum=`expr $sum + $n`
	a=`expr $a / 10`
done
echo "sum of digits of number: $sum"
