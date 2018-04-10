CC = g++
CFLAGS = -pg -g -O2 -Wall
CXXFLAGS=-g -std=c++11 -Wall -pedantic
LDFLAGS = -pg -g
LIBS = -lm

raytracer:  main.o raytracer.o util.o light_source.o scene_object.o bmp_io.o experiments.o scenes.o
	$(CC) $(CFLAGS) -o raytracer \
	main.o raytracer.o util.o light_source.o scene_object.o bmp_io.o experiments.o scenes.o $(LIBS)

clean:
	-rm -f core *.o
	-rm raytracer