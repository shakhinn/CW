all: main

main: main.o read_text.o task_3_4.o task_1.o task_2.o free.o
	gcc main.o read_text.o task_3_4.o task_1.o task_2.o free.o -o main
main.o: main.c
	gcc -c main.c
read_text.o: read_text.c
	gcc -c read_text.c
task_3_4.o: task_3_4.c
	gcc -c task_3_4.c
task_1.o: task_1.c
	gcc -c task_1.c
task_2.o: task_2.c
	gcc -c task_2.c
free.o: free.c
	gcc -c free.c
clean:
	rm -rf *.o
