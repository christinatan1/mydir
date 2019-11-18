all: mydir.o
	gcc -o a.out mydir.o

statFunctions.o: mydir.c
	gcc -c mydir.c

run:
	./a.out

clean:
	rm *.o
	rm *~
