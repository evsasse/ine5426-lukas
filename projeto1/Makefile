OUTPUT=lukacompiler

$(OUTPUT): parser.h parser.cpp scanner.cpp main.cpp
	g++ -o $(OUTPUT) *.cpp -std=c++11

parser.h: parser.y
	bison -v --defines=parser.h -o parser.cpp parser.y

scanner.cpp: parser.h scanner.l
	flex -o scanner.cpp scanner.l

clear:
	rm lukacompiler parser.cpp parser.h scanner.cpp test errortest parser.output

test:
	echo "v0.1/1" > test
	-./lukacompiler < tests/v0.1/input/1.in | diff -B - tests/v0.1/expected/1.ex >> test
	echo "v0.1/2" >> test
	-./lukacompiler < tests/v0.1/input/2.in | diff -B - tests/v0.1/expected/2.ex >> test
	echo "v0.1/3" >> test
	-./lukacompiler < tests/v0.1/input/3.in | diff -B - tests/v0.1/expected/3.ex >> test
	echo "v0.2/1" >> test
	-./lukacompiler < tests/v0.2/input/1.in | diff -B - tests/v0.2/expected/1.ex >> test
	echo "v0.2/2" >> test
	-./lukacompiler < tests/v0.2/input/2.in | diff -B - tests/v0.2/expected/2.ex >> test
	echo "v0.2/3" >> test
	-./lukacompiler < tests/v0.2/input/3.in | diff -B - tests/v0.2/expected/3.ex >> test
	echo "v0.3/1" >> test
	-./lukacompiler < tests/v0.3/input/1.in | diff -B - tests/v0.3/expected/1.ex >> test
	echo "v0.3/2" >> test
	-./lukacompiler < tests/v0.3/input/2.in | diff -B - tests/v0.3/expected/2.ex >> test
	echo "v0.4/1" >> test
	-./lukacompiler < tests/v0.4/input/1.in | diff -B - tests/v0.4/expected/1.ex >> test
	echo "v0.4/2" >> test
	-./lukacompiler < tests/v0.4/input/2.in | diff -B - tests/v0.4/expected/2.ex >> test
	echo "v0.5/1" >> test
	-./lukacompiler < tests/v0.5/input/1.in | diff -B - tests/v0.5/expected/1.ex >> test
	echo "v0.5/2" >> test
	-./lukacompiler < tests/v0.5/input/2.in | diff -B - tests/v0.5/expected/2.ex >> test
	echo "v0.6/1" >> test
	-./lukacompiler < tests/v0.6/input/1.in | diff -B - tests/v0.6/expected/1.ex >> test
	echo "v0.6/2" >> test
	-./lukacompiler < tests/v0.6/input/2.in | diff -B - tests/v0.6/expected/2.ex >> test
	echo "v0.7/1" >> test
	-./lukacompiler < tests/v0.7/input/1.in | diff -B - tests/v0.7/expected/1.ex >> test
	echo "v0.7/2" >> test
	-./lukacompiler < tests/v0.7/input/2.in | diff -B - tests/v0.7/expected/2.ex >> test
	echo "v0.8/1" >> test
	-./lukacompiler < tests/v0.8/input/1.in | diff -B - tests/v0.8/expected/1.ex >> test
	echo "v0.8/2" >> test
	-./lukacompiler < tests/v0.8/input/2.in | diff -B - tests/v0.8/expected/2.ex >> test
	echo "v0.8/3" >> test
	-./lukacompiler < tests/v0.8/input/3.in | diff -B - tests/v0.8/expected/3.ex >> test
	echo "v1.0/1" >> test
	-./lukacompiler < tests/v1.0/input/1.in | diff -B - tests/v1.0/expected/1.ex >> test
	echo "v1.0/2" >> test
	-./lukacompiler < tests/v1.0/input/2.in | diff -B - tests/v1.0/expected/2.ex >> test

errortest:
	echo "v0.1/1" > errortest
	-./lukacompiler < error_tests/v0.1/input/1.in >error_tests/errortest 2>error_tests/errortest_err
	-diff -B error_tests/errortest error_tests/v0.1/expected/1.ex >> errortest
	echo "v0.1/1_err" >> errortest
	-diff -B error_tests/errortest_err error_tests/v0.1/expected/1.ex_err >> errortest
	rm error_tests/errortest error_tests/errortest_err
	echo "v0.1/2" >> errortest
	-./lukacompiler < error_tests/v0.1/input/2.in >error_tests/errortest 2>error_tests/errortest_err
	-diff -B error_tests/errortest error_tests/v0.1/expected/2.ex >> errortest
	echo "v0.1/2_err" >> errortest
	-diff -B error_tests/errortest_err error_tests/v0.1/expected/2.ex_err >> errortest
	rm error_tests/errortest error_tests/errortest_err
	echo "v0.1/3" >> errortest
	-./lukacompiler < error_tests/v0.1/input/3.in >error_tests/errortest 2>error_tests/errortest_err
	-diff -B error_tests/errortest error_tests/v0.1/expected/3.ex >> errortest
	echo "v0.1/3_err" >> errortest
	-diff -B error_tests/errortest_err error_tests/v0.1/expected/3.ex_err >> errortest
	rm error_tests/errortest error_tests/errortest_err
	echo "v0.1/4" >> errortest
	-./lukacompiler < error_tests/v0.1/input/4.in >error_tests/errortest 2>error_tests/errortest_err
	-diff -B error_tests/errortest error_tests/v0.1/expected/4.ex >> errortest
	echo "v0.1/4_err" >> errortest
	-diff -B error_tests/errortest_err error_tests/v0.1/expected/4.ex_err >> errortest
	rm error_tests/errortest error_tests/errortest_err
	echo "v0.2/1" >> errortest
	-./lukacompiler < error_tests/v0.2/input/1.in >error_tests/errortest 2>error_tests/errortest_err
	-diff -B error_tests/errortest error_tests/v0.2/expected/1.ex >> errortest
	echo "v0.2/1_err" >> errortest
	-diff -B error_tests/errortest_err error_tests/v0.2/expected/1.ex_err >> errortest
	rm error_tests/errortest error_tests/errortest_err
