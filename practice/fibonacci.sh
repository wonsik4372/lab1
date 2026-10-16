#!/bin/bash
# let / expr fibonacci
n=${1:-10}		# 입력 없을 시 기본값 10 
a=0
b=1
echo "피보나치 수열 (처음 $n개, let 사용): "
i=0
while [ $i -lt $n ]; do
	echo -n "$a "
	let "next = a + b"
	a=$b
	b=$next
	let "i++"
done
echo

echo "피보나치 수열 (처음 $n개, expr 사용): "
a=0; b=1; i=0
while [ $i -lt $n ]; do
	echo -n "$a "
	next=`expr $a + $b`
	a=$b
	b=$next
	i=`expr $i + 1`
done
echo

