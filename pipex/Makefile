NAME = pipex
LIBFT = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft

SRCS = main.c process.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

make_libft:
	$(MAKE) -C $(LIBFT_DIR)

$(NAME) : make_libft $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/$(LIBFT) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re