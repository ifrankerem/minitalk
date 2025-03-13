NAME_SERVER = server
NAME_CLIENT = client

CC       = gcc
CFLAGS   = -g -Wall -Wextra -Werror

SRCS_SERVER = server.c
SRCS_CLIENT = client.c

FT_PRINTF_DIR = ./ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all: ft_printf $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJS_SERVER) -o $(NAME_SERVER) -L$(FT_PRINTF_DIR) -lftprintf

$(NAME_CLIENT): $(OBJS_CLIENT) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(NAME_CLIENT) -L$(FT_PRINTF_DIR) -lftprintf

ft_printf:
	make -C $(FT_PRINTF_DIR)

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	make clean -C $(FT_PRINTF_DIR)

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	make fclean -C $(FT_PRINTF_DIR)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re ft_printf
