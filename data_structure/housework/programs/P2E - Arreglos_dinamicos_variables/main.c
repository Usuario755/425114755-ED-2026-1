#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>



char* read_string();

int getAlphabetPosition(char c) {
    return c - 'A' + 1;
}

void printMatrix(char **matrix, int rows) {
    printf("\n MATRIZ DE LETRAS \n\n");
    for (int i = 0; i < rows; i++) {
        if (matrix[i] != NULL) {
            printf("| ");
            for (int j = 0; matrix[i][j] != '\0'; j++) {
                printf("%c ", matrix[i][j]);
            }
            printf("|\n");
        } else {
            printf("| NULL |\n");
        }
    }
}

int main() {
    printf("Ingrese una cadena en MAYUSCULAS: ");
    char *input = read_string();
    if (input == NULL) {
        printf("Error al leer la cadena.\n");
        return -1;
    }

    int length = strlen(input);
    char **matrix = (char **) malloc((length + 1) * sizeof(char *));
    if (matrix == NULL) {
        printf("Error al asignar memoria para matrix.\n");
        free(input);
        return -1;
    }

    for (int i = 0; i < length; i++) {
        char c = input[i];
        if (isupper(c)) {
            int count = getAlphabetPosition(c);
            matrix[i] = (char *) malloc((count + 1) * sizeof(char));
            if (matrix[i] == NULL) {
                printf("Error al asignar memoria para fila %d.\n", i);
                free(input);
                return -1;
            }
            for (int j = 0; j < count; j++) {
                matrix[i][j] = c;
            }
            matrix[i][count] = '\0';
        } else {
            matrix[i] = NULL;
        }
    }

    matrix[length] = NULL;

    printMatrix(matrix, length);

    
    for (int i = 0; i < length; i++) {
        if (matrix[i] != NULL) free(matrix[i]);
    }
    free(matrix);
    free(input);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

char* read_string() {
    char *str = NULL;
    int ch, len = 0;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        char *temp = realloc(str, len + 2);
        if (temp == NULL) {
            free(str);
            return NULL;
        }
        str = temp;
        str[len++] = ch;
        str[len] = '\0';
    }

    return str;
}
