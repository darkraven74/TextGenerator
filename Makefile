all: main.cpp text_generator.cpp text_generator.h
	g++ -std=c++11 -O3 main.cpp text_generator.cpp -o text_generator
clean:
	rm -f text_generator *.o

