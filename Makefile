NAME = minishell

FLAGS = -Wall -Werror -Wextra -Ilibs

SOURCES = \
	main/minishell.c \
	parser/parsing.c \
	parser/tokenizar.c \
	utils/utils_toke.c \
	utils/utils_ps1.c \
	utils/utils_ps2.c \
	utils/expand.c


OBJECTS = \
	objects/minishell.o \
	objects/parsing.o \
	objects/tokenizar.o \
	objects/utils_toke.o \
	objects/utils_ps1.o	\
	objects/utils_ps2.o \
	objects/expand.o

LIBFT = my_lib/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	@cc $(FLAGS) -o $(NAME) $(OBJECTS) -L my_lib -lft -lreadline -lhistory

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

objects/utils_ps1.o:
	@mkdir -p objects
	@cc $(FLAGS) -c utils/utils_ps1.c -o objects/utils_ps1.o

objects/utils_ps2.o:
	@mkdir -p objects
	@cc $(FLAGS) -c utils/utils_ps2.c -o objects/utils_ps2.o

objects/expand.o:
	@mkdir -p objects
	@cc $(FLAGS) -c utils/expand.c -o objects/expand.o

$(LIBFT):
	@make -C my_lib

clean:
	@rm -f $(OBJECTS)
	@make -C my_lib clean

fclean: clean
	@rm -f $(NAME)
	@make -C my_lib fclean

re: fclean all

