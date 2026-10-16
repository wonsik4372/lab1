#!/bin/bash

echo "===== for ====="
for i in {2..9}; do
	for j in {1..9}; do
		printf "%dx%d=%2d    " $i $j $((i*j))
	done
	echo
done

echo "===== while ====="
i=2
while [ $i -le 9 ]; do
	j=1
	while ((j <= 9)); do
		printf "%dx%d=%2d    " $i $j $((i*j))
		((j++))
	done
	echo
	i=$((i+1))
done

echo "===== until ====="
i=2
until [ $i -gt 9 ]; do
	j=1
	until [ $j -gt 9 ]; do
		printf "%dx%d=%2d    " $i $j $((i*j))
		let "j += 1"
	done
	echo
	let "i += 1"
done

