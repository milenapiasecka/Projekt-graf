#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pars.h"
#include "graph.h"


Element* dodaj_element(Element *glowa, const char *name, int u, int v, double weight) {
    Element *nowy = malloc(sizeof(Element));

    if(nowy == NULL)
        return glowa;

    strncpy(nowy->dane.name, name, 31);
    nowy->dane.name[31] = '\0'; 
    nowy->dane.u = u;
    nowy->dane.v = v;
    nowy->dane.weight = weight;

    nowy->next=glowa;

    return nowy;
    
}


Element * czytaj_plik(int argc, char *argv[]){

    if(argc < 2) {
        printf("Nie podano nazwy pliku");
        return NULL;
    }

    FILE *f = fopen(argv[1], "r");

    if(f == NULL)
        return NULL;

    Element *glowa = NULL;

    int u,v;
    char name[32];
    double weight;

    while(fscanf(f,"%31s %d %d %lf", name, &u, &v, &weight ) == 4) {
        if (u < 0 || v < 0 || weight <= 0) {
            printf("Wprowadzone wartosci sa bledne\n");
            break;
        }

        glowa = dodaj_element(glowa, name, u,v,weight);
    }
    
    fclose(f);
    return glowa;
}
