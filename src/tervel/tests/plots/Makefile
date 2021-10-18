CC=g++
CFLAGS=-I.
DEPS = 
OBJ = script.o

%.o: %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

script: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	
clean:
	rm -f script $(OBJ)
