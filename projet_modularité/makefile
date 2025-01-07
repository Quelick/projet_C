CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude
SRC = src/main.c src/vols.c src/clients.c src/reservation.c src/menu.c
OBJ = $(SRC:.c=.o)
EXEC = programme

all: data $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

data:
	mkdir -p data

clean:
	rm -f $(OBJ) $(EXEC)

re: clean all

