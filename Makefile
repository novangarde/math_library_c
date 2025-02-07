NAME      := mm_math
CC        := gcc
CFLAGS    := -std=c11 -pedantic -Wall -Werror -Wextra
GCOVFLAGS := -fprofile-arcs -ftest-coverage
LIBR      := $(NAME).a
SRC       := $(NAME).c
OBJ       := $(NAME).o
HEADER    := $(NAME).h
TEST      := test_$(NAME).c
OS        := $(shell uname -s)

ifeq ($(OS), Linux)
	CFLAGS+=           -D OS_LINUX
	CHECKFLAGS=        -lpthread -pthread -lrt -lm -lsubunit -lcheck
endif
ifeq ($(OS), Darwin)
	CFLAGS+=            -D OS_MAC
endif

.PHONY: all clean test gcov_report

all: clean $(LIBR)

$(LIBR): $(OBJ)
	ar rcs $(LIBR) $(OBJ)
	rm -rf ./*.o

$(OBJ): $(SRC) $(HEADER)
	$(CC) -c $(SRC) -o $(OBJ) $(CFLAGS)

test: rebuild_lib $(TEST)
	$(CC) $(CFLAGS) $(TEST) $(LIBR) $(CHECKFLAGS) $(shell pkg-config --cflags --libs check) -Wno-gnu-zero-variadic-macro-arguments -o test
	./test

gcov_report: rebuild_lib
	$(CC) $(GCOVFLAGS) $(TEST) $(SRC) $(CHECKFLAGS) $(shell pkg-config --cflags --libs check) -o GcovReport
	./GcovReport
	lcov -t "GcovReport" -o GcovReport.info -c -d .
	genhtml -o gcov_report GcovReport.info
	rm -rf ./*.gcno ./*gcda ./GcovReport

clean:
	rm -f $(LIBR) $(OBJ) $(NAME) *.gc*
	rm -rf gcov_report test GcovReport GcovReport.info

rebuild_lib: clean $(LIBR)

cn:
	clang-format -n -style=Google *.c *.h
