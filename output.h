#ifndef OUTPUT_H
#define OUTPUT_H

#include "graph.h"

// Generuje przykładowe (fake) współrzędne wierzchołków
void generate_fake_layout(Graph* g);

// Zapis do pliku tekstowego
int save_output_text(const char* filename, Graph* g);

// Zapis do pliku binarnego
int save_output_binary(const char* filename, Graph* g);

#endif