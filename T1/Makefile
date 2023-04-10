EXEC = gcc
CFLAGS = -std=c99 -fstack-protector-all -g
PROJECT_NAME = ted

clear:
	rm *.o
	rm $(PROJECT_NAME)
	rm *.gch

$(PROJECT_NAME): lista.o main.c formas.o svg.o path.o system.o qry.o
	$(EXEC) $(CFLAGS) lista.o main.c formas.o svg.o path.o system.o qry.o -o $(PROJECT_NAME) -lm

lista.o: lista.c lista.h
	$(EXEC) $(CFLAGS) -c lista.c lista.h

formas.o: formas.c formas.h
	$(EXEC) $(CFLAGS) -c formas.c formas.h

svg.o: svg.c svg.h
	$(EXEC) $(CFLAGS) -c svg.c svg.h

path.o: path.c path.h
	$(EXEC) $(CFLAGS) -c path.c path.h

system.o: system.c system.h
	$(EXEC) $(CFLAGS) -c system.c system.h

qry.o: qry.c qry.h
	$(EXEC) $(CFLAGS) -c qry.c qry.h