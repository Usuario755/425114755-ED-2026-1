#include "coutingSort.h"
#include <stdio.h>
#include <stdlib.h>




void countingSortWithSteps(int arr[], int n) {
    // Encontrar mínimo y máximo
    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    int range = max - min + 1;
    int *count = (int *)calloc(range, sizeof(int));

    printf("\n--- Paso 1: Rango calculado ---\n");
    printf("Mínimo = %d, Máximo = %d, Rango = %d\n", min, max, range);

    // Contar ocurrencias con desplazamiento
    printf("\n--- Paso 2: Conteo de ocurrencias ---\n");
    for (int i = 0; i < n; i++) {
        count[arr[i] - min]++;
        printf("Elemento %d -> count[%d] = %d\n", arr[i], arr[i] - min, count[arr[i] - min]);
    }

       printf("\nArreglo de conteo inicial:\n");
    for (int i = 0; i < range; i++) {
        printf("count[%d] = %d\n", i, count[i]);
    }

    // Reconstruir arreglo ordenado
    printf("\n--- Paso 3: Reconstrucción del arreglo ordenado ---\n");
    int index = 0;
    for (int i = 0; i < range; i++) {
        while (count[i] > 0) {
            arr[index++] = i + min;
            printf("Insertando %d en posición %d\n", i + min, index - 1);
            count[i]--;
        }
    }

    free(count);
}
