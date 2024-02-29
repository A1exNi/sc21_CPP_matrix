CC=							gcc
CFLAGS=					-Wall -Werror -Wextra -std=c++17 -pedantic -lstdc++
GCOVFLAG=				-fprofile-arcs -ftest-coverage -std=c++17 -lstdc++
SOURSES_MATRIX=	s21_matrix*.cc
OBJECT_MATRIX=	$(patsubst %*.cc, %*.o, $(SOURSES_MATRIX))
SOURSES_TEST=		test_*.cc
OS=							$(shell uname -s)

ifeq ($(OS), Linux)
	CFLAGS+=		-D OS_LINUX -lm
	GTESTFLAGS=	-lgtest -pthread -lpthread -lm
endif
ifeq ($(OS), Darwin)
	CFLAGS+= 		-D OS_MAC
	GTESTFLAGS=	-lgtest
endif

all: rebuild_lib

s21_matrix_oop.a: $(SOURSES_MATRIX)
	$(CC) $(CFLAGS) -c $(SOURSES_MATRIX)
	@ar rcs s21_matrix_oop.a $(OBJECT_MATRIX)
	@rm -rf ./*.o

test: rebuild_lib $(SOURSES_TEST)
	$(CC) $(SOURSES_TEST) s21_matrix_oop.a -o test $(CFLAGS) $(GTESTFLAGS) 
	./test

gcov_report: rebuild_lib
	@$(CC) $(SOURSES_TEST) $(SOURSES_MATRIX) $(GCOVFLAG) $(GTESTFLAGS) -o GcovReport
	@./GcovReport
	@lcov -no-external -t "GcovReport" -o GcovReport.info -c -d .
	@genhtml -o report GcovReport.info
	@open ./report/index-sort-f.html
	@rm -rf ./*.gcno ./*gcda ./GcovReport.*

clang:
	@cp ../materials/linters/.clang-format .clang-format
	clang-format -n *.cc *.h
	@rm -rf .clang-format

valgrind_test: test
	valgrind --tool=memcheck --leak-check=yes ./test

leaks_test: test
	leaks -atExit -- ./test

clean:
	@rm -rf ./*.o ./*.a ./a.out ./GcovReport ./*.gcno ./*.gcda ./report ./*.info ./*.dSYM ./unit-test ./CPPLINT* ./test

rebuild_lib: clean s21_matrix_oop.a

valgrind_single_test: single_test
	valgrind --tool=memcheck --leak-check=yes ./test

single_test: rebuild_lib
	$(CC) single_test.cc s21_matrix_oop.a $(CFLAGS) -o test
	@./test