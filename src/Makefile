CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11
UBUNTU_FLAGS=-lsubunit -lrt -lpthread -lm
LDFLAGS=
SOURCES=matrix.c
DEBUG_SOURCES=$(SOURCES)
OBJECTS=$(SOURCES:.c=.o)
LIBS=-lcheck
TEST_SOURCES=tests/*.c
OS=$(shell uname -s)

all: test

test: matrix.a $(TEST_SOURCES)
	$(CC) $(CFLAGS) -c $(TEST_SOURCES)
ifeq ($(OS), Darwin)
	$(CC) *.o -o unit_test $(LIBS) matrix.a
else
	$(CC) *.o -o unit_test $(LIBS) $(UBUNTU_FLAGS) matrix.a
endif
	rm -rf *.o
	./unit_test

debug: $(DEBUG_SOURCES)
	$(CC) $(DEBUG_SOURCES) -g

matrix.a: $(SOURCES)
	$(CC) $(CFLAGS) -c $(SOURCES)
	ar cr matrix.a *.o

gcov_report:
ifeq ($(OS), Darwin)
	$(CC) --coverage $(CFLAGS) $(TEST_SOURCES) $(SOURCES) -o gcov_test $(LIBS)
else
	$(CC) --coverage $(CFLAGS) $(TEST_SOURCES) $(SOURCES) -o gcov_test $(LIBS) $(UBUNTU_FLAGS)
endif
	./gcov_test
	lcov -t "gcov_test" -o gcov_test.info -c -d .
	genhtml -o report gcov_test.info
	open ./report/index.html
	rm -rf *.gc*

clean:
	rm -rf *.o unit_test matrix.a gcov_test gcov_test.info *.gc* report

rebuild: clean test
