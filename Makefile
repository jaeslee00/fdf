NAME = fdf

SRC =	main.c \
		draw_line.c \
		parser.c \
		parser_utils.c \
		move.c \
		instruction.c \
		draw.c \
		init.c \
		key_inputs1.c \
		key_inputs2.c \
		color.c \
		free_resources.c \
		special_atoi.c \
		pixel_in_img.c

OBJ = $(patsubst %.c, obj/%.o, $(SRC))

HEADER = ./includes/fdf.h \
		 ./libft/includes/libft.h

INCLUDE_PATH = -I ./includes -I ./libft/includes

LIBFT =	libft/libft.a

HEADER_MLX = -I /usr/local/include/

LIB_MLX = -L /usr/local/lib/

MLX = -lmlx -framework OpenGL -framework AppKit

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(INCLUDE_PATH) $(OBJ) -o $(NAME) $(LIBFT) $(LIB_MLX) $(MLX)

obj:
	mkdir -p obj

obj/%.o: src/%.c $(LIBFT) | obj
	$(CC) $(FLAGS) -c $< -o $@ $(INCLUDE_PATH) $(HEADER_MLX)


$(LIBFT):
	make -C ./libft/

clean:
	rm -rf obj
	make clean -C ./libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft/

re: fclean all

.PHONY : all, re, clean, flcean
