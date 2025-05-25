#include "../libs/minishell.h"
#include "../my_lib/libft.h"
#include "../libs/structs.h"

int handle_redirects(t_command *cmd, char **envp)
{
    int i;
    t_redirect *r;

    i = -1;
    while (++i < cmd->redirect_count)
	{
		r = &cmd->redirects[i];
		if (r->type == REDIR_OUT)
			handle_redout(r, envp);
		else if (r->type == APPEND)
			handle_append(r, envp);
		else if (r->type == REDIR_IN)
			handle_redin(r, envp);
		else if (r->type == HEREDOC)
			handle_heredoc(r);
	}
	return 0;
}

