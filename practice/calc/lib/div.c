// lib/div.c

#include <stdio.h>
#include "calc.h"
double div(int a, int b){
	if(b == 0){
		fprintf(stderr, "0으로 나눌 수 없습니다. \n");
		return 0.0;
	}
	return (double) a / b;
}
