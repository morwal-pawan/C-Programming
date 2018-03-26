#!/bin/bash
echo "enter four numbers:"
read a b c d
if [ $a -gt $b ]
then
	if [ $a -gt $c ]
	then
		if [ $a -gt $d ]
		then
			echo "largest value is:$a"
		else
			echo "largest value is:$d"
		fi
	else
		if [ $c -gt $d ]
		then
			echo "largest value is:$c"
		else 
			echo "largest value is:$d"
		fi
	fi
else
	if [ $b -gt $c ]
	then
		if [ $b -gt $d ]
		then 
			echo "largest value is:$b"
		else
			echo "largest value is:$d"
		fi
	else
		if [ $c -gt $d ]
		then 
			echo "largest value is :$c"
		else
			echo "largest value is:$d"
		fi
	fi
fi
