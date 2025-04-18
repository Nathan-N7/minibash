#include "../libs/minishell.h"
#include "../my_lib/libft.h"
#include "../libs/structs.h"

t_token	*new_token(t_tk_type type,	char *value)
{
	t_token	*tok = ft_calloc(1, sizeof(t_token));
	if (!tok)
		return (NULL);
	tok->type = type;
	tok->value = value;
	tok->next = NULL;
	return (tok);
}

void	add_token(t_token	**head, t_token	*new)
{
	t_token	*tmp;

	if (!*head)
	{
		*head = new;
		return ;
	}
	tmp = *head; 
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_token	*tokenize(char *input)
{
    t_token	*head;
    int     i;

    i = 0;
	head = NULL;
    while (input[i])
    {
		if (ft_isspace(input[i]))
			i++;
		else if (input[i] == '>' && input[i + 1] == '|')
		{
			add_token(&head, new_token(REDIR_OUT, ft_strdup(">|")));
			i += 2;
		}
		else if (input[i] == '>' && input[i + 1] == '>' && input[i + 2] == '|')
		{
			add_token(&head, new_token(APPEND, ft_strdup(">>")));
			i += 3;
		}
		else if (input[i] == '>' && input[i + 1] ==  '>')
		{
			add_token(&head, new_token(APPEND, ft_strdup(">>")));
			i += 2;
		}
		else if (input[i] == '<' && input[i + 1] ==  '<')
		{
			add_token(&head, new_token(HEREDOC, ft_strdup("<<")));
			i += 2;
		}
		else if (input[i] == '>')
		{
			add_token(&head, new_token(REDIR_OUT, ft_strdup(">")));
			i++;
		}
		else if (input[i] == '<')
		{
			add_token(&head, new_token(REDIR_IN, ft_strdup("<")));
			i++;
		}
		else if (input[i] == '|')
		{
			add_token(&head, new_token(PIPE, ft_strdup("|")));
			i++;
		}
		else
		{
			char	buffer[4096];
			int		buf_i;
			char	aspas;

			buf_i = 0;
			while (input[i] && !ft_isspace(input[i]) && input[i] != '|' &&
		   		input[i] != '<' && input[i] != '>')
			{
				if (input[i] == '\'' || input[i] == '"')
				{
					aspas = input[i++];
					while (input[i] && input[i] != aspas)
						buffer[buf_i++] = input[i++];
					if (input[i] == aspas)
						i++; // pula aspas final
				}
				else
					buffer[buf_i++] = input[i++];
			}
			buffer[buf_i] = '\0';
			add_token(&head, new_token(WORD, ft_strdup(buffer)));
		}
	}
	return (head);
}