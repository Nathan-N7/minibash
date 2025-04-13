NAME = minishell

FLAGS = -Wall -Werror -Wextra -Ilibs

SOURCES = \
	main/minishell.c \
	parser/parsing.c \
	parser/tokenizar.c \
	utils/utils_toke.c

OBJECTS = \
	objects/minishell.o \
	objects/parsing.o \
	objects/tokenizar.o \
	objects/utils_toke.o

LIBFT = mylib/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	@cc $(FLAGS) -o $(NAME) $(OBJECTS) -L mylib -lft -lreadline -lhistory

# Compilação dos objetos manual, sem % e com mkdir
objects/minishell.o:
	@mkdir -p objects
	@cc $(FLAGS) -c main/minishell.c -o objects/minishell.o

objects/parsing.o:
	@mkdir -p objects
	@cc $(FLAGS) -c parser/parsing.c -o objects/parsing.o

objects/tokenizar.o:
	@mkdir -p objects
	@cc $(FLAGS) -c parser/tokenizar.c -o objects/tokenizar.o

objects/utils_toke.o:
	@mkdir -p objects
	@cc $(FLAGS) -c utils/utils_toke.c -o objects/utils_toke.o

$(LIBFT):
	@make -C mylib

clean:
	@rm -f $(OBJECTS)
	@make -C mylib clean

fclean: clean
	@rm -f $(NAME)
	@make -C mylib fclean

re: fclean all

