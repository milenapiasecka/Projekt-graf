//wstępne struktury potrzebne do napisania kody wyjścia//

#ifndef GRAPH_H
#define GRAPH_H

// Wierzchołek
typedef struct {
    int id;        // identyfikator wierzchołka
    double x;      // współrzędna X
    double y;      // współrzędna Y
} Vertex;


// Krawędź
typedef struct {
    char name[32]; // nazwa krawędzi
    int u;         // początek
    int v;         // koniec
    double weight; // waga
} Edge;


// Graf
typedef struct {
    Vertex* vertices; // tablica wierzchołków
    Edge* edges;      // tablica krawędzi
    int n_vertices;   // liczba wierzchołków
    int n_edges;      // liczba krawędzi
} Graph;

#endif