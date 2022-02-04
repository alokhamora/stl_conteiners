

all: map_test stack_test vector_test
	./map_test
	./stack_test
	./vector_test

CFLAGS=-Wall -Wextra -Werror


map_test: map_test.cpp
	clang++ -std=c++98 $(CFLAGS) map_test.cpp -o map_test
stack_test: stack_test.cpp
	clang++ -std=c++98 $(CFLAGS) stack_test.cpp -o stack_test
vector_test: vector_test.cpp
	clang++ -std=c++98 $(CFLAGS) vector_test.cpp -o vector_test


