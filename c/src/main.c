#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph.h"
#include "pars.h"
#include "output.h"
#include "fruchterman.h"
#include "graph_utils.h"


int is_planar_euler(Graph *g) {
    int V = g->n_vertices;
    int E = g->n_edges;

    if (V < 3) return 1; 

    if (E > 3 * V - 6)
        return 0; 

    return 1; 
}



int main(int argc, char* argv[]) {

    // wczytaj plik
    Element* lista = czytaj_plik(argc, argv);
    if (!lista) {
        printf("Blad wczytywania pliku\n");
        return 1;
    }

    
    // konwersja
    Graph* g = list_to_graph(lista);
    if(g==NULL) {
        return 1;
    }


    if (is_planar_euler(g)) {
        fruchterman_reingold(g, 500);
    }
    
    else {
    printf("Graf nie jest planarny\n");
    return 1;
    }

   

    // zapis
   if(argc < 3) {
        printf("Prosze podac w jakim formacie maja byc zapisane pliki\n");
        return 2;
    }

    if(strcmp(argv[2], "-b") == 0) 
    {
        save_output_binary("out.bin", g);
    }
    else if(strcmp(argv[2], "-t") == 0)
    {
        save_output_text("out.txt", g);
    }
    else {
        printf("Bledny parametr\n");
        return 3;
    }

    return 0;
}