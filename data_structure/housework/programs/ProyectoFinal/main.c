

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "convert.h" // Incluimos funciones de conversión y evaluación

void mostrar_ayuda(const char *prog) {
    printf("Uso: %s \"expresion\"\n", prog);
    printf("Ejemplo: %s \"(1000+27)*-3\"\n", prog);
    printf("Opciones:\n");
    printf("  -h    Muestra esta ayuda\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        mostrar_ayuda(argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "-h") == 0) {
        mostrar_ayuda(argv[0]);
        return 0;
    }

    char *expresion = argv[1];

    // Validar paréntesis
    if (!validar_parentesis(expresion)) {
        printf("Error: expresión con paréntesis desbalanceados.\n");
        return 1;
    }

    char postfija[400], prefija[400];
    convertir_infija_postfija(expresion, postfija);
    convertir_infija_prefija(expresion, prefija);

    int resultado = evaluar_postfija(postfija);

    // Guardar en archivo
    FILE *f = fopen("resultados.txt", "a");
    if (f) {
        fprintf(f, "Expresión: %s\n", expresion);
        fprintf(f, "Postfija: %s\n", postfija);
        fprintf(f, "Prefija: %s\n", prefija);
        fprintf(f, "Resultado: %d\n", resultado);
        fprintf(f, "---------------------------\n");
        fclose(f);
    } else {
        printf("No se pudo abrir el archivo para guardar resultados.\n");
    }

    return 0;
}
