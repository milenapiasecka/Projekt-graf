#include <stdio.h>
#include <stdlib.h>
#include "output.h"

// zapis tekstowy
int save_output_text(const char* filename, Graph* g) {
    if (g == NULL)
        return 0;

    FILE* f = fopen(filename, "w");
    if (f == NULL) {
        printf("Nie mozna otworzyc pliku %s\n", filename);
        return 0;
    }

    for (int i = 0; i < g->n_vertices; i++) {
        fprintf(f, "%d %.3f %.3f\n",
                g->vertices[i].id,
                g->vertices[i].x,
                g->vertices[i].y);
    }

    fclose(f);
    return 1;
}

// zapis binarny
int save_output_binary(const char* filename, Graph* g) {
    if (g == NULL)
        return 0;

    FILE* f = fopen(filename, "wb");
    if (f == NULL) {
        printf("Error: cannot open file %s\n", filename);
        return 0;
    }

    // zapis liczby wierzchołków
    fwrite(&g->n_vertices, sizeof(int), 1, f);

    // zapis tablicy Vertex
    fwrite(g->vertices, sizeof(Vertex), g->n_vertices, f);

    fclose(f);
    return 1;
}
