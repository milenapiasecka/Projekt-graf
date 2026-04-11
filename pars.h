#ifndef PARS_H
#define PARS_H

#include "graph.h"

typedef struct Element {
    Edge dane;
    struct Element *next;
} Element;


Element* dodaj_element(Element *glowa, const char *name, int u, int v, double weight);
Element* czytaj_plik(int argc, char *argv[]);

#endif


