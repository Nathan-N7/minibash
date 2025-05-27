#include "../libs/minishell.h"
#include "../my_lib/libft.h"
#include "../libs/structs.h"

void handle_heredoc(t_redirect *redir, char **envp)
{
    char    *rline;
    int     pipefd[2];
	char	*e_rline;

	pipe(pipefd);
	while (1)
	{
		rline = readline(">");
		if (!rline)
			break ;
		if (!strcmp(rline, redir->filename))
		{
			free(rline);
			break ;
		}
		e_rline = expand_var(rline, envp);
		my_printf_fd("%s\n", pipefd[1], e_rline);
		free(rline);
		free(e_rline);
	}
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
}
