all: ma_lib.o my_process1.o my_process2.o allocate.o ma_lib.so

ma_lib.o: ma_lib.c
	gcc -c -fPIC ma_lib.c -o ma_lib.o

ma_lib.so: ma_lib.o
	gcc -o ma_lib.so -shared ma_lib.o

my_process1.o: my_process1.c
	gcc -l ma_lib -L. my_process1.c 

my_process2.o: my_process1.c
	gcc -l ma_lib -L. my_process1.c

allocate.o: allocate.c
	gcc -l ma_lib -L. allocate.c

clean:
	rm *.o
	rm *.so