CC=gcc-11
CFLAGS=-lxml2 -fopenmp -I/opt/homebrew/include -L/opt/homebrew/lib -lomp -O3

target: 
	$(CC) -o dband_omp.o src/main.c src/file.c src/parse_xy.c src/calc_band.c $(CFLAGS) 
