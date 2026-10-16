/* dlmain.c */
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main()
{
    void *handle;
    int (*add)(int, int), (*sub)(int, int), (*mul)(int, int);
    double (*divp)(int, int);   /* div 는 stdlib.h 의 div()와 이름이 겹치므로 다른 이름 사용 */
    char *error;

    handle = dlopen("./lib/libcalc.so", RTLD_LAZY);
    if (!handle) { fputs(dlerror(), stderr); exit(1); }

    add  = dlsym(handle, "add");
    sub  = dlsym(handle, "sub");
    mul  = dlsym(handle, "mul");
    divp = dlsym(handle, "div");    /* 라이브러리 안의 심볼 이름은 "div" */
    if ((error = dlerror()) != NULL) { fprintf(stderr, "%s", error); exit(1); }

    printf("add(20,4)=%d\n", (*add)(20, 4));
    printf("sub(20,4)=%d\n", (*sub)(20, 4));
    printf("mul(20,4)=%d\n", (*mul)(20, 4));
    printf("div(20,4)=%.2f\n", (*divp)(20, 4));
    dlclose(handle);
}