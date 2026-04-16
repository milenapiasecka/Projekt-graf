#include <math.h>
#include <stdlib.h>
#include "fruchterman.h"

#define AREA 10000.0
#define EPSILON 0.0001

// losowa liczba z zakresu 0–1
static double rand01() {
    return rand() / (double)RAND_MAX;
}

void fruchterman_reingold(Graph *g, int iterations) {
    if (g == NULL || g->n_vertices == 0)
        return;

    int n = g->n_vertices;

    // optymalna odległość między wierzchołkami
    double k = sqrt(AREA / n);

    // losowa inicjalizacja
    for (int i = 0; i < n; i++) {
        g->vertices[i].x = rand01() * 100.0;
        g->vertices[i].y = rand01() * 100.0;
    }

    
    // iteracje
    for (int iter = 0; iter < iterations; iter++) {

        double *dx = malloc(n * sizeof(double));
        double *dy = malloc(n * sizeof(double));

        if (!dx || !dy) {
            free(dx);
            free(dy);
            return;
        }

        // zerowanie sił
        for (int i = 0; i < n; i++) {
            dx[i] = 0.0;
            dy[i] = 0.0;
        }

        //siły odpychajace 
        for (int v = 0; v < n; v++) {
            for (int u = v + 1; u < n; u++) {

                double dxv = g->vertices[v].x - g->vertices[u].x;
                double dyv = g->vertices[v].y - g->vertices[u].y;

                double dist = sqrt(dxv * dxv + dyv * dyv) + EPSILON;

                double force = (k * k) / dist;

                dx[v] += (dxv / dist) * force;
                dy[v] += (dyv / dist) * force;

                dx[u] -= (dxv / dist) * force;
                dy[u] -= (dyv / dist) * force;
            }
        }

        // sily przyciagajace - krawedzie
        for (int e = 0; e < g->n_edges; e++) {

            int u_id = g->edges[e].u;
            int v_id = g->edges[e].v;

            int u = -1;
            int v = -1;

            // znajdź indeksy wierzchołków
            for (int i = 0; i < n; i++) {
                if (g->vertices[i].id == u_id)
                    u = i;
                if (g->vertices[i].id == v_id)
                    v = i;
            }

            if (u == -1 || v == -1)
                continue;

            double dxv = g->vertices[v].x - g->vertices[u].x;
            double dyv = g->vertices[v].y - g->vertices[u].y;

            double dist = sqrt(dxv * dxv + dyv * dyv) + EPSILON;

            double force = (dist * dist) / k;

            dx[v] -= (dxv / dist) * force;
            dy[v] -= (dyv / dist) * force;

            dx[u] += (dxv / dist) * force;
            dy[u] += (dyv / dist) * force;
        }

        // aktualizacja pozycji
        for (int i = 0; i < n; i++) {
            g->vertices[i].x += dx[i] * 0.01;
            g->vertices[i].y += dy[i] * 0.01;
        }

        // zwolnienie pamięci
        free(dx);
        free(dy);
    }
}