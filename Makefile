all: ma_lib.o libma.so my_process1.o my_process2.o allocate.o 

ma_lib.o: ma_lib.c
	gcc -c -fPIC ma_lib.c -o ma_lib.o

libma.so: ma_lib.o
	gcc -o libma.so -shared ma_lib.o

my_process1.o: my_process1.c
	gcc  my_process1.c  -o my_process1.o -lma -L.

my_process2.o: my_process2.c
	gcc  my_process2.c  -o my_process2.o -lma -L.

allocate.o: allocate.c
	gcc  allocate.c -o allocate.o -lma -L.

clean:
	rm *.o
	rm *.so
