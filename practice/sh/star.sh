#!/bin/bash
# 별 출력하기
i=${1:-5} 
while [ $i -gt 0 ]; do
	j=$i
	while [ $j -gt 0 ]; do
		echo -n "*"
		let "j = j - 1"
	done
	echo	
	let "i = i - 1"
done
echo

