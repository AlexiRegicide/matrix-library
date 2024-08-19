G = clang++ -std=c++17 -g
GCC =$(G) -Wall -Wextra -Werror 
LIBS = 
OS = $(shell uname)

ifeq ($(OS), Darwin) 
	# CFLAGS+=$(shell /Users/tianavin/googletest/googletest/include/gtest/gtest.h)
	LIBS+=$(shell pkg-config --libs --cflags gtest)
else
	LIBS+= -lgtest
endif

all:  s21_matrix_oop.a test

clean:
	rm -rf *.o *.a *.so *.gcda *.gcno *.gch rep.info *.html *.css tests report *.txt *.dSYM *.info

test: 
	$(GCC) S21_matrix_oop.a tests_matrix.cc -o tests $(LIBS)
	./tests --gtest_repeat=3 --gtest_break_on_failure --gtest_filter=* --gtest_color=yes 
	@make clang leak cppcheck

s21_matrix_oop.a:
	$(G) -c S21_*.cpp
	ar rc S21_matrix_oop.a S21_*.o
	ls S21_matrix_oop.a
	ranlib S21_matrix_oop.a
	# rm *.o

gcov_report: clean
	$(GCC) --coverage tests_matrix.cc S21_Matrix_oop*.cpp -o test $(LIBS)
	chmod +x *
	./test
	lcov --ignore-errors mismatch  -t "test" -o test.info --no-external -c -d .
	genhtml -o report/ test.info
	open ./report/index.html

leak:
	@echo -------------------LEAKS------------------------
		leaks -atExit -- test
clang:
	@echo -------------------CLANG_FORMAT------------------------
	clang-format -n S21_*.cpp S21_*.h tests_matrix.cc
cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem . *.cpp
