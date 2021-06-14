all:	run

run:	compile-lib
		./run

compile-lib:	compile	../libft.a
		gcc -o run a.o -L. ../libft.a -lbsd

compile:
		gcc -c main.c -o a.o

clean:
		rm -f a.o
