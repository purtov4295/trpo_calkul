all: bin/calculator bin/calculator_test


bin/calculator: build/src/main.o build/src/functions.o
	gcc -Wall -Werror build/src/main.o build/src/functions.o -o bin/calculator
build/src/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/src/main.o
build/src/functions.o: src/functions.c
	gcc -Wall -Werror -c src/functions.c -o build/src/functions.o


bin/calculator_test: bin/calculator_test

bin/calculator_test: build/test/main.o build/test/functions.o
	gcc -Wall -Werror build/test/main.o build/test/functions.o -o bin/calculator_test -lm

build/test/main.o: test/main.c
	gcc -Wall -Werror -c -I thirdparty -I src test/main.c -o build/test/main.o

build/test/functions.o: src/functions.c src/functions.h
	gcc -Wall -Werror -c -I thirdparty -I src src/functions.c -o build/test/functions.o


clean:
	rm -rf build/src/*.o bin/calculator
	rm -rf build/test/*.o bin/calculator_test