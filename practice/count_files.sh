#!/bin/bash
# 현재 디렉토리 파일 개수 출력 
count=$(ls -l | grep '^-' | wc -l)
echo "현재 디렉토리($(pwd))의 개수: $count"
