#include "../libs/minishell.h"
#include "../my_lib/libft.h"
#include "../libs/structs.h"

void handle_heredoc(t_redirect *redir, int *error_flag, char **envp)
{
    char    *rline;
    int     pipefd[2];
	
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
		if (!strcmp(rline, redir->filename))
		{
			free(rline);
			break ;
		}
		my_printf_fd("%s\n", pipefd[1], rline);
		free(rline);
	}
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
}
