// main.c: 정적/공유 라이브러리

#include <stdio.h>
#include "calc.h"

int main(void){
	int a = 0;
	int b = 0;
	printf("정수 두 개 입력: ");
	if(scanf("%d %d", &a, &b) != 2){
		fprintf(stderr, "\n정수 두 개를 입력\n");
		return 1;
	}

	printf("더하기: %d + %d = %d\n", a, b, add(a, b));
	printf("빼기: %d - %d = %d\n", a, b, sub(a, b));
	printf("곱하기: %d * %d = %d\n", a, b, mul(a, b));
	printf("나누기: %d / %d = %.2lf\n", a, b, div(a, b));

	return 0;
}
