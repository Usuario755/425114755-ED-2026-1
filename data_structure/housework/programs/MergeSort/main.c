
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mergesort.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s num1 num2 num3 ...\n", argv[0]);
        return 1;
    }

    // Mostrar el nombre del programa carácter por carácter
    char *num = argv[0];
    fprintf(stdout, "arg[0] = %s \n", argv[0]);
    for (int i = 0; i < strlen(argv[0]); i++)
        fprintf(stdout, "num[%d] = %c \n", i, num[i]);

    // Convertir argumentos en enteros
    int n = argc - 1;
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = atoi(argv[i + 1]);
    }

    mergeSort(arr, 0, n - 1);

    printf("Arreglo ordenado: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

