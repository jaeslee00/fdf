NAME = fdf

SRC = ./fdf.c \
		./check.c \
		./draw_line.c \
		./move.c \
		./graph.c

OBJ = $(SRC:.c=.o)

HEADER = ./fdf.h

INCLUDE_PATH = -I ./

LIBFT =	libft/libft.a

HEADER_MLX = -I /usr/local/include/

LIB_MLX = -L /usr/local/lib/

MLX = -lmlx -framework OpenGL -framework AppKit

CC = gcc

FLAGS = -Wall -Wextra -Werror #-fsanitize=address -g

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(SRC) $(HEADER)
	$(CC) $(FLAGS) $(INCLUDE_PATH) $(OBJ) -o $(NAME) $(LIBFT) $(LIB_MLX) $(MLX)

$(OBJ): %.o: %.c $(LIBFT)
	$(CC) $(FLAGS) -c $(SRC) $(INCLUDE_PATH) $(HEADER_MLX)

$(LIBFT):
	make -C ./libft/

clean:
	rm -f $(OBJ)
	make clean -C ./libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft/

re: fclean all

.PHONY : all, re, clean, flcean
