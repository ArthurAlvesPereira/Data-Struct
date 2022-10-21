EXEC = gcc
CFLAGS = -std=c99 -fstack-protector-all -g
PROJECT_NAME = ted

clear:
	rm *.o
	rm $(PROJECT_NAME)

$(PROJECT_NAME): lista.o main.c geo.o formas.o svg.o
	$(EXEC) $(CFLAGS) lista.o main.c geo.o formas.o svg.o -o $(PROJECT_NAME)

lista.o: lista.c lista.h
	$(EXEC) $(CFLAGS) -c lista.c lista.h

geo.o: geo.c geo.h
	$(EXEC) $(CFLAGS) -c geo.c geo.h

formas.o: formas.c formas.h
	$(EXEC) $(CFLAGS) -c formas.c formas.h

svg.o: svg.c svg.h
	$(EXEC) $(CFLAGS) -c svg.c svg.h

#circulo.o: circulo.c circulo.h
#	$(EXEC) $(CFLAGS) -c circulo.c circulo.h

#retangulo.o: retangulo.c retangulo.h
#	$(EXEC) $(CFLAGS) -c retangulo.c retangulo.h

#linha.o: linha.c linha.h
#	$(EXEC) $(CFLAGS) -c linha.c linha.h

#texto.o: texto.c texto.h
#	$(EXEC) $(CFLAGS) -c texto.c texto.h

