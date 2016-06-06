LIBS = R3Coord.o list.o
FUENTE = R3Coord.c list.c

sphere: $(LIBS) sphere.c
	gcc sphere.c $(LIBS) -o sphere -lm

$(LIBS): $(FUENTE)
	gcc -c $(FUENTE)

clean:
	rm $(LIBS) sphere