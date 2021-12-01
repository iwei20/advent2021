run: main.out
	./main.out

main.out: main.cpp
	g++ -std=c++20 -Wall -Wextra -Wconversion -o main.out main.cpp ../../advent_utils.o

fast: main.cpp
	g++ -std=c++20 -Wall -Wextra -Wconversion -Ofast -march=native -fopenmp -D_GLIBCXX_PARALLEL -o main.out main.cpp ../../advent_utils.o

debug: main.cpp
	g++ -std=c++20 -Wall -Wextra -Wconversion -Og -D_GLIBCXX_DEBUG -o main.out main.cpp ../../advent_utils.o