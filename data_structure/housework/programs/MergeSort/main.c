/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/


#include "mergesort.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    int i;
    char *num = argv[0];
    
    fprintf(stdout, "arg[10] = %s \n", argv[0]);
    
    
    
    for (i = 0; i < strlen(argv[0]); i++)
        fprintf(stdout, "num[%d] = %c \n", i, num[i]);


  	// Ordenamiente de un arreglo mediante mergesort
    mergeSort(arr, 0, n - 1);
    
    printf("Arreglo ordenado: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}