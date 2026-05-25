#include <stdlib.h>
#include "graph.h"
#include "pars.h"

Graph* list_to_graph(Element* list) {
    if (list == NULL)
        return NULL;

    Graph* g = malloc(sizeof(Graph));
    if (g == NULL) 
        return NULL;

    g->n_edges = 0;
    g->n_vertices = 0;

    // policz krawędzie
    Element* temp = list;
    while (temp != NULL) {
        g->n_edges++;
        temp = temp->next;
    }

    g->edges = malloc(g->n_edges * sizeof(Edge));
    if (g->edges == NULL) {
        free(g);
        return NULL;
    }

    // kopiuj krawędzie
    temp = list;
    int i = 0;
    while (temp != NULL) {
        g->edges[i++] = temp->dane;
        temp = temp->next;
    }

    // znajdź wierzchołki
    int max = g->n_edges * 2;
    g->vertices = malloc(max * sizeof(Vertex));
    if (g->vertices == NULL) {
        free(g->edges);
        free(g);
        return NULL;
    }

    for (int i = 0; i < g->n_edges; i++) {
        int u = g->edges[i].u;
        int v = g->edges[i].v;

        int found_u = 0, found_v = 0;

        for (int j = 0; j < g->n_vertices; j++) {
            if (g->vertices[j].id == u) 
                found_u = 1;
            if (g->vertices[j].id == v) 
                found_v = 1;
        }

        if (found_u == 0) {
            g->vertices[g->n_vertices].id = u;
            g->vertices[g->n_vertices].x = 0.0;
            g->vertices[g->n_vertices].y = 0.0;
            g->n_vertices++;
        }

        if (found_v == 0) {
            g->vertices[g->n_vertices].id = v;
            g->vertices[g->n_vertices].x = 0.0;
            g->vertices[g->n_vertices].y = 0.0;
            g->n_vertices++;
        }
     }

    return g;
}
