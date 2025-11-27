
#ifndef CONVERT_H
#define CONVERT_H

int validar_parentesis(const char *expr);
void convertir_infija_postfija(const char *infija, char *postfija);
void convertir_infija_prefija(const char *infija, char *prefija);
int evaluar_postfija(const char *postfija);

#endif
