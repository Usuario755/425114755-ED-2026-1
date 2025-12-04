
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coutingSort.h"


int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s num1 num2 num3 ...\n", argv[0]);
        return 1;
    }

    // Convertir argumentos en enteros
    int n = argc - 1;
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = atoi(argv[i + 1]);
    }

    printf("\nArreglo original:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Ordenar con Counting Sort mostrando pasos
    countingSortWithSteps(arr, n);

    printf("\nArreglo ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
