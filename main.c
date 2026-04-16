#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "pars.h"
#include "output.h"
#include "fruchterman.h"
#include "graph_utils.h"

int main(int argc, char* argv[]) {

    // 1. wczytaj plik
    Element* lista = czytaj_plik(argc, argv);
    if (!lista) {
        printf("Blad wczytywania pliku\n");
        return 1;
    }

    
    // 2. konwersja
    Graph* g = list_to_graph(lista);
    if(g==NULL) {
        return 1;
    }

    // 3. algorytm
    fruchterman_reingold(g, 500);

    // 4. zapis
    save_output_text("out.txt", g);
    save_output_binary("out.bin", g);

    return 0;
}