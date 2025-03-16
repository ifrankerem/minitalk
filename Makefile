NAME_SERVER = server
NAME_CLIENT = client

CC       = gcc
CFLAGS   = -g -Wall -Wextra -Werror

SRCS_SERVER = server.c
SRCS_CLIENT = client.c

FT_PRINTF_DIR = ./ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

all: ft_printf $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(SRCS_SERVER) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) $(SRCS_SERVER) -o $(NAME_SERVER) -L$(FT_PRINTF_DIR) -lftprintf

$(NAME_CLIENT): $(SRCS_CLIENT) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) $(SRCS_CLIENT) -o $(NAME_CLIENT) -L$(FT_PRINTF_DIR) -lftprintf

ft_printf:
	make -C $(FT_PRINTF_DIR)

clean:
	make clean -C $(FT_PRINTF_DIR)

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	make fclean -C $(FT_PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re ft_printf
