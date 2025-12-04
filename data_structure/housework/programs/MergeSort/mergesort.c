

#include "mergesort.h"
#include <stdio.h>
#include <stdlib.h>

// Merges dos sub-arreglos de arr[].
// Primer arreglo es arr[izq..med]
// Segundo arreglo es arr[med+1..der]

void merge(int arr[], int izq, int med, int der) {
    int i, j, k;
    int n1 = med - izq + 1;
    int n2 = der - med;

    // Crea arreglos temporales
    int izqArr[n1], derArr[n2];

    // Copia data a arreglos temporales 
    for (i = 0; i < n1; i++)
        izqArr[i] = arr[izq + i];
    for (j = 0; j < n2; j++)
        derArr[j] = arr[med + 1 + j];

    // Merge los arreglos temporales vuelven a estar en arr[izq..der]
    i = 0;
    j = 0;
    k = izq;
    while (i < n1 && j < n2) {
        if (izqArr[i] <= derArr[j]) {
            arr[k] = izqArr[i];
            i++;
        }
        else {
            arr[k] = derArr[j];
            j++;
        }
        k++;
    }

    // Copia los elementos restantes de izqArr[], si hay
    while (i < n1) {
        arr[k] = izqArr[i];
        i++;
        k++;
    }

    // Copia los elementos restantes de derArr[], si hay
    while (j < n2) {
        arr[k] = derArr[j];
        j++;
        k++;
    }
}

// El subarreglo que se va a ordenar está en el rango de índice [izq-der]
void mergeSort(int arr[], int izq, int der) {
    if (izq < der) {
      
        // Calcular el punto medio
        int med = izq + (der - izq) / 2;

        // Ordenar la primera y la segunda mitad
        mergeSort(arr, izq, med);
        mergeSort(arr, med + 1, der);

        // Merge las mitades ordenadas
        merge(arr, izq, med, der);
    }
}