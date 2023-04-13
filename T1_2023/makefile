EXEC = gcc
CFLAGS = -std=c99 -fstack-protector-all -g
PROJECT_NAME = ted

clear:
	rm *.o
	rm $(PROJECT_NAME)
	rm *.gch

$(PROJECT_NAME): lista.o main.c path.o system.o formas.o qry.o
	$(EXEC) $(CFLAGS) lista.o main.c path.o system.o formas.o qry.o -o $(PROJECT_NAME) -lm

lista.o: lista.c lista.h
	$(EXEC) $(CFLAGS) -c lista.c

path.o: path.c path.h
	$(EXEC) $(CFLAGS) -c path.c

system.o: system.c system.h
	$(EXEC) $(CFLAGS) -c system.c

formas.o: formas.c formas.h
	$(EXEC) $(CFLAGS) -c formas.c

qry.o: qry.c qry.h
	$(EXEC) $(CFLAGS) -c qry.c


