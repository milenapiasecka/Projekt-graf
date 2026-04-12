CC = cc
CFLAGS = -Wall -Wextra 
 
graf: fruchterman.o graph_utils.o main.o output.o pars.o
	$(CC) fruchterman.o graph_utils.o main.o output.o pars.o -o graf -lm


main.o: main.c fruchterman.h graph_utils.h pars.h output.h graph.h
	$(CC) $(CFLAGS) -c main.c 

fruchterman.o: fruchterman.c fruchterman.h
	$(CC) $(CFLAGS) -c fruchterman.c 

graph_utils.o: graph_utils.c graph_utils.h
	$(CC) $(CFLAGS) -c graph_utils.c

output.o: output.c output.h
	$(CC) $(CFLAGS) -c output.c 

pars.o: pars.c pars.h
	$(CC) $(CFLAGS) -c pars.c

run: graf
	./graf graf.txt

clean:
	rm -f *.o graf out.txt out.bin
