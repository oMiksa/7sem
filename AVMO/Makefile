CC = gcc
CFLAGS = -c -g
PREFIX = ./bin

labs: lab_1.o lab_2.o lab_3.o curs.o
	$(CC) lab_1.o -o $(PREFIX)/lab_1
	$(CC) lab_2.o -o $(PREFIX)/lab_2
	$(CC) lab_3.o -o $(PREFIX)/lab_3
	$(CC) curs.o -o $(PREFIX)/curs
	rm -f *.o
lab_1.o: lab_1.c
	$(CC) $(CFLAGS) lab_1.c
lab_2.o: lab_2.c
	$(CC) $(CFLAGS) lab_2.c
lab_3.o: lab_3.c
	$(CC) $(CFLAGS) lab_3.c
curs.o: curs.c
	$(CC) $(CFLAGS) curs.c
clear:
	rm -f *.o $(PREFIX)/*