NAME = fdf

TEST = test

SRC = fdf.c \
		check.c \
		draw_line.c \
		move.c

TEST_SRC =	test.c \
			draw_line.c \
			check.c \
			check_utils.c \
			move.c \
			instruction.c \
			draw.c \
			init.c

OBJ = $(patsubst %.c, obj/%.o, $(SRC))

TEST_OBJ = $(patsubst %.c, test_obj/%.o, $(TEST_SRC))

HEADER = ./includes/fdf.h \
		 ./libft/includes/libft.h

INCLUDE_PATH = -I ./includes -I ./libft/includes

LIBFT =	libft/libft.a

HEADER_MLX = -I /usr/local/include/

LIB_MLX = -L /usr/local/lib/

MLX = -lmlx -framework OpenGL -framework AppKit

CC = gcc

FLAGS = -Wall -Wextra -Werror -g #-fsanitize=address -g

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(INCLUDE_PATH) $(OBJ) -o $(NAME) $(LIBFT) $(LIB_MLX) $(MLX)

$(TEST): $(LIBFT) $(TEST_OBJ) $(HEADER)
	$(CC) $(FLAGS) $(INCLUDE_PATH) $(TEST_OBJ) -o $(TEST) $(LIBFT) $(LIB_MLX) $(MLX)

obj:
	mkdir -p obj

test_obj:
	mkdir -p test_obj

test_obj/%.o: src/%.c $(LIBFT) | test_obj
	$(CC) $(FLAGS) -c $< -o $@ $(INCLUDE_PATH)

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
