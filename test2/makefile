test2:fun.c main.c
	gcc fun.c main.c -o test2
fun.o:fun.c head.h
	gcc -c fun.c
main.o:main.c head.h
	gcc -c main.c
clean:
	rm -f *.o
