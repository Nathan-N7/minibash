#include "../libs/minishell.h"
#include "../my_lib/libft.h"
#include "../libs/structs.h"

int handle_redirects(t_command *cmd, t_envp *env)
{
    int i;
    t_redirect *r;
	int	error_flag;

    i = -1;
	error_flag = FALSE;
    while (++i < cmd->redirect_count && error_flag != TRUE)
	{
		r = &cmd->redirects[i];
		if (r->type == REDIR_OUT)
			handle_redout(r, &error_flag, env->envp);
		else if (r->type == APPEND)
			handle_append(r, &error_flag, env->envp);
		else if (r->type == REDIR_IN)
			handle_redin(r, &error_flag, env->envp);
		else if (r->type == HEREDOC)
			handle_heredoc(r, env);
	}
	if (error_flag == TRUE)
		return (-1);
	return (0);
}

