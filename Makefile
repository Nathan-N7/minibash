NAME = minishell

FLAGS = -Wall -Werror -Wextra -Ilibs

SOURCES = main/minishell.c parser/parsing.c parser/tokenizar.c utils/utils_toke.c

OBJECTS = $(SOURCES:.c=.o)

LIBFT = mylib/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	@cc $(FLAGS) -o $(NAME) $(OBJECTS) -L mylib -lft -lreadline -lhistory

$(LIBFT):
	@make -C mylib

.c.o:
	@cc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS)
	@make -C mylib clean

fclean: clean
	@rm -f $(NAME)
	@make -C mylib fclean

re: fclean all
