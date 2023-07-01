LIBDIR := ./libft

CC := cc
CFLAGS := -Wall -Wextra -Werror

CLIENT_SRC := client.c
SERVER_SRC := server.c
HEADER := minitalk.h

CLIENT_OBJ := $(CLIENT_SRC:.c=.o)
SERVER_OBJ := $(SERVER_SRC:.c=.o)

all: libft client server

client: $(CLIENT_OBJ)
	$(CC) $(CFLAGS) -L$(LIBDIR) $^ -o $@ -L$(LIBDIR) -lft

server: $(SERVER_OBJ)
	$(CC) $(CFLAGS) -L$(LIBDIR) $^ -o $@ -L$(LIBDIR) -lft

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	$(MAKE) -C $(LIBDIR)

clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ)
	$(MAKE) -C $(LIBDIR) clean

fclean: clean
	rm -f client server
	$(MAKE) -C $(LIBDIR) fclean

re: fclean all

.PHONY: all clean fclean re libft