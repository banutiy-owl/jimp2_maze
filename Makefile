graph: main.c bfs.c Dijsktra.c utility.c pomocnicze.c
	$(CC) -o graph main.c bfs.c Dijsktra.c utility.c pomocnicze.c
test: test.c bfs.c
	$(CC) -o test test.c bfs.c Dijsktra.c
clear:
	rm graph *.o *~