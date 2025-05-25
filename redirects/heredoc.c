#include "../libs/minishell.h"
#include "../my_lib/libft.h"
#include "../libs/structs.h"

void handle_heredoc(t_redirect *redir)
{
    char    *rline;
    int     pipefd[2];
    char    *limiter;

	limiter = redir->filename;
	if (pipe(pipefd) < 0)
	{
		perror("pipe");
		return ;
	}
	while (1)
	{
		rline = readline(">");
		if (!rline)
			break ;
		if (!strcmp(rline, limiter))
		{
			free(rline);
			break ;
		}
		write(pipefd[1], rline, strlen(rline));
		write(pipefd[1], "\n", 1);
		free(rline);
	}
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
}