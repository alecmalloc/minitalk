CC := gcc
CFLAGS := -Wall -Wextra

CLIENT_SRC := client.c
SERVER_SRC := server.c
HEADER := minitalk.h

CLIENT_OBJ := $(CLIENT_SRC:.c=.o)
SERVER_OBJ := $(SERVER_SRC:.c=.o)

all: client server

client: $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

server: $(SERVER_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ)

fclean: clean
	rm -f client server $(HEADER).a

re: fclean all