CC = gcc
CFLAGS = -Wall -g -fPIC

all: my_graph my_Knapsack

my_graph: my_graph.o graphlib.so
	$(CC) $(CFLAGS) -o $@ $< ./graphlib.so

graphlib.so: my_mat.o my_mat.h
	$(CC) $(CFLAGS) -shared -o $@ $^

my_graph.o: my_graph.c my_mat.h
	$(CC) $(CFLAGS) -c $<

my_mat.o: my_mat.c my_mat.h
	$(CC) $(CFLAGS) -c $<

my_Knapsack: my_Knapsack.o
	$(CC) $(CFLAGS) -o $@ $^

my_Knapsack.o: my_Knapsack.c
	$(CC) $(CFLAGS) -c $^

.PHONY: clean all

clean:
	rm -f *.o *.so my_graph my_Knapsack