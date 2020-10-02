CC=g++
CFLAGS=-I. -ltbb -std=c++0x -pthread
DEPS = 
OBJ = main.o

%.o: %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	
clean:
	rm -f main $(OBJ)
