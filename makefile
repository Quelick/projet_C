# Déclaration des variables
CC = gcc
CFLAGS = -Wall -g
OBJFILES = main.o client.o vol.o reservation.o
EXEC = gestion_vols

# Règle par défaut pour compiler l'exécutable
all: $(EXEC)

# Compilation de l'exécutable
$(EXEC): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJFILES)

# Compilation des fichiers objets
main.o: main.c client.h vol.h reservation.h
	$(CC) $(CFLAGS) -c main.c

client.o: client.c client.h
	$(CC) $(CFLAGS) -c client.c

vol.o: vol.c vol.h
	$(CC) $(CFLAGS) -c vol.c

reservation.o: reservation.c reservation.h client.h vol.h
	$(CC) $(CFLAGS) -c reservation.c

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f $(OBJFILES) $(EXEC)

# Recompilation complète (nettoyage et compilation)
rebuild: clean all

