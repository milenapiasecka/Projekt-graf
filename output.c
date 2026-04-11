#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "output.h"

// ----------------------------------
// FAKE layout – rozmieszczenie na okręgu
// ----------------------------------
void generate_fake_layout(Graph* g) {
    if (g == NULL || g->n_vertices == 0)
        return;

    double radius = 10.0;

    for (int i = 0; i < g->n_vertices; i++) {
        double angle = 2.0 * M_PI * i / g->n_vertices;

        g->vertices[i].x = radius * cos(angle);
        g->vertices[i].y = radius * sin(angle);
    }
}

// ----------------------------------
// Zapis tekstowy
// ----------------------------------
int save_output_text(const char* filename, Graph* g) {
    if (g == NULL)
        return 0;

    FILE* f = fopen(filename, "w");
    if (f == NULL) {
        printf("Error: cannot open file %s\n", filename);
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

// ----------------------------------
// Zapis binarny
// ----------------------------------
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