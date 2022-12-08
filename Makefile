NAME := push_swap
CC := gcc
CFLAGS := -Wall -Wextra -Werror -Iheaders/

SOURCE := srcs/*.c

all:
			$(CC) $(CFLAGS) $(SOURCE) -o $(NAME)

clean:

fclean: clean
				rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re