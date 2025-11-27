
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "dlist.h"
#include "convert.h"

// Mostrar pila para trazado
void mostrar_pila(DList *pila) {
    printf("[Pila]: ");
    DListNode *node = dlist_tail(pila);
    while (node) {
        printf("%c ", *(char *)node->data);
        node = dlist_prev(node);
    }
    printf("\n");
}

// Prioridad de operadores
int prioridad(char op) {
    switch (op) {
        case '^': case '%': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        case '(': return 0;
        default: return -1;
    }
}

// Validar paréntesis balanceados
int validar_parentesis(const char *expr) {
    int balance = 0;
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(') balance++;
        else if (expr[i] == ')') balance--;
        if (balance < 0) return 0;
    }
    return balance == 0;
}

// Conversión a postfija con trazado
void convertir_infija_postfija(const char *infija, char *postfija) {
    DList pila;
    dlist_init(&pila, free);
    int j = 0;
    int len = strlen(infija);

    printf("\n--- Conversión a Postfija ---\n");
    for (int i = 0; i < len; i++) {
        if (isspace(infija[i])) continue;

        // Detectar número (incluye negativos)
        if (isdigit(infija[i]) || 
            (infija[i] == '-' && (i == 0 || infija[i-1] == '(' || strchr("+-*/%^", infija[i-1])))) {
            printf("Token: número ");
            if (infija[i] == '-') {
                postfija[j++] = infija[i];
                printf("-");
                i++;
            }
            while (i < len && isdigit(infija[i])) {
                postfija[j++] = infija[i];
                printf("%c", infija[i]);
                i++;
            }
            postfija[j++] = ' ';
            printf(" -> agregado\n");
            i--;
        } else if (infija[i] == '(') {
            char *dato = malloc(sizeof(char));
            *dato = infija[i];
            dlist_ins_next(&pila, dlist_tail(&pila), dato);
            printf("Token: '(' -> push\n");
            mostrar_pila(&pila);
        } else if (infija[i] == ')') {
            printf("Token: ')' -> desapilar hasta '('\n");
            while (dlist_size(&pila) > 0) {
                char *dato;
                dlist_remove(&pila, dlist_tail(&pila), (void **)&dato);
                if (*dato == '(') {
                    free(dato);
                    break;
                }
                postfija[j++] = *dato;
                postfija[j++] = ' ';
                printf("Pop: %c -> agregado\n", *dato);
                free(dato);
            }
            mostrar_pila(&pila);
        } else {
            printf("Token: operador %c\n", infija[i]);
            int p = prioridad(infija[i]);
            while (dlist_size(&pila) > 0) {
                char *dato = dlist_tail(&pila)->data;
                if (prioridad(*dato) >= p && *dato != '(') {
                    char *rem;
                    dlist_remove(&pila, dlist_tail(&pila), (void **)&rem);
                    postfija[j++] = *rem;
                    postfija[j++] = ' ';
                    printf("Pop: %c -> agregado\n", *rem);
                    free(rem);
                } else break;
            }
            char *nuevo = malloc(sizeof(char));
            *nuevo = infija[i];
            dlist_ins_next(&pila, dlist_tail(&pila), nuevo);
            printf("Push: %c\n", infija[i]);
            mostrar_pila(&pila);
        }
    }

    printf("Vaciar pila...\n");
    while (dlist_size(&pila) > 0) {
        char *dato;
        dlist_remove(&pila, dlist_tail(&pila), (void **)&dato);
        if (*dato != '(') {
            postfija[j++] = *dato;
            postfija[j++] = ' ';
            printf("Pop final: %c -> agregado\n", *dato);
        }
        free(dato);
    }

    postfija[j] = '\0';
    dlist_destroy(&pila);
    printf("Postfija final: %s\n", postfija);
}

// Conversión a prefija (invierte lógica)
void convertir_infija_prefija(const char *infija, char *prefija) {
    char invertida[200], postfija[400];
    strcpy(invertida, infija);

    // Invertir expresión y cambiar paréntesis
    int len = strlen(invertida);
    for (int i = 0; i < len / 2; i++) {
        char temp = invertida[i];
        invertida[i] = invertida[len - i - 1];
        invertida[len - i - 1] = temp;
    }
    for (int i = 0; i < len; i++) {
        if (invertida[i] == '(') invertida[i] = ')';
        else if (invertida[i] == ')') invertida[i] = '(';
    }

    printf("\n--- Conversión a Prefija ---\n");
    printf("Expresión invertida: %s\n", invertida);

    convertir_infija_postfija(invertida, postfija);

    // Invertir resultado para prefija
    int lenPost = strlen(postfija);
    int k = 0;
    for (int i = lenPost - 1; i >= 0; i--) {
        prefija[k++] = postfija[i];
    }
    prefija[k] = '\0';
    printf("Prefija final: %s\n", prefija);
}

// Evaluación de postfija
int evaluar_postfija(const char *postfija) {
    DList pila;
    dlist_init(&pila, free);
    char token[100];
    int i = 0;

    printf("\n--- Evaluación de Postfija ---\n");
    while (sscanf(postfija + i, "%s", token) == 1) {
        i += strlen(token) + 1;
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            int *num = malloc(sizeof(int));
            *num = atoi(token);
            dlist_ins_next(&pila, dlist_tail(&pila), num);
            printf("Push número: %d\n", *num);
        } else {
            int *b, *a;
            dlist_remove(&pila, dlist_tail(&pila), (void **)&b);
            dlist_remove(&pila, dlist_tail(&pila), (void **)&a);
            int res = 0;
            switch (token[0]) {
                case '+': res = *a + *b; break;
                case '-': res = *a - *b; break;
                case '*': res = *a * *b; break;
                case '/': res = *a / *b; break;
                case '%': res = *a % *b; break;
                case '^': res = (int)pow(*a, *b); break;
            }
            printf("Operación: %d %c %d = %d\n", *a, token[0], *b, res);
            free(a); free(b);
            int *resultado = malloc(sizeof(int));
            *resultado = res;
            dlist_ins_next(&pila, dlist_tail(&pila), resultado);
        }
    }

    int *final;
    dlist_remove(&pila, dlist_tail(&pila), (void **)&final);
    int resultado = *final;
    free(final);
    dlist_destroy(&pila);
    printf("Resultado final: %d\n", resultado);
    return resultado;
}
