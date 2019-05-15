all: bin/geometry bin/test


bin/geometry: build/src/main.o build/src/circle.o
	gcc -Wall -Werror build/src/main.o build/src/circle.o -o bin/geometry
build/src/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/src/main.o
build/src/circle.o: src/circle.c
	gcc -Wall -Werror -c src/circle.c -o build/src/circle.o


bin/test: bin/geometry_test

bin/geometry_test: build/test/main.o build/test/circle.o
	gcc -Wall -Werror build/test/main.o build/test/circle.o -o bin/geometry_test -lm

build/test/main.o: test/main.c
	gcc -Wall -Werror -c -I thirdparty -I src test/main.c -o build/test/main.o

build/test/circle.o: src/circle.c src/circle.h
	gcc -Wall -Werror -c -I thirdparty -I src src/circle.c -o build/test/circle.o


clean:
	rm -rf build/src/*.o bin/geometry
	rm -rf build/test/*.o bin/test