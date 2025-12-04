#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUMNOS 100
#define MAX_CARACTERES 25

int main() {
    char alumnos[MAX_ALUMNOS][3][MAX_CARACTERES];
    int n = 0;
    char opcion[3];

    do {
        printf("Ingrese el nombre del alumno #%d: ", n + 1);
        fgets(alumnos[n][0], MAX_CARACTERES, stdin);
        alumnos[n][0][strcspn(alumnos[n][0], "\n")] = '\0'; // Eliminar salto de línea

        printf("Ingrese la edad del alumno #%d: ", n + 1);
        fgets(alumnos[n][1], MAX_CARACTERES, stdin);

        printf("Ingrese la calificación del alumno #%d: ", n + 1);
        fgets(alumnos[n][2], MAX_CARACTERES, stdin);

        n++;

        printf("¿Desea agregar otro alumno? (si/no): ");
        fgets(opcion, 3, stdin);
        getchar(); // Limpiar el buffer

    } while (strcmp(opcion, "si") == 0 && n < MAX_ALUMNOS);

    // Cálculo de promedios
    int sumaEdad = 0, sumaCalif = 0;
    for (int i = 0; i < n; i++) {
        sumaEdad += atoi(alumnos[i][1]);
        sumaCalif += atoi(alumnos[i][2]);
    }

    float promedioEdad = (float)sumaEdad / n;
    float promedioCalif = (float)sumaCalif / n;

    printf("\nPromedio de edad: %.2f\n", promedioEdad);
    printf("Promedio de calificación: %.2f\n", promedioCalif);

    // Imprimir nombres en orden inverso
    printf("\nNombres en orden inverso:\n");
    for (int i = n - 1; i >= 0; i--) {
        printf("%s|%d|%.2f\n", alumnos[i][0], atoi(alumnos[i][1]), atof(alumnos[i][2]));
    }

    return 0;
}
