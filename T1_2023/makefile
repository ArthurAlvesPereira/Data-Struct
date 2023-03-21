EXEC = gcc
CFLAGS = -std=c99 -fstack-protector-all -g
PROJECT_NAME = ted

clear:
	rm *.o
	rm $(PROJECT_NAME)

$(PROJECT_NAME): lista.o main.c path.o system.o
	$(EXEC) $(CFLAGS) lista.o main.c path.o system.o -o $(PROJECT_NAME) -lm

lista.o: lista.c lista.h
	$(EXEC) $(CFLAGS) -c lista.c lista.h

path.o: path.c path.h
	$(EXEC) $(CFLAGS) -c path.c path.h

system.o: system.c system.h
	$(EXEC) $(CFLAGS) -c system.c system.h


