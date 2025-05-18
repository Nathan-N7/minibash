#include "../libs/minishell.h"
#include "../my_lib/libft.h"
#include "../libs/structs.h"

int	is_builtin(t_command *cmd)
{
	if (!cmd || !cmd->args || !cmd->args[0])
		return (0);
	if (ft_strcmp(cmd->args[0], "cd") == 0
		|| ft_strcmp(cmd->args[0], "exit") == 0
		|| ft_strcmp(cmd->args[0], "pwd") == 0
		|| ft_strcmp(cmd->args[0], "env") == 0
		|| ft_strcmp(cmd->args[0], "unset") == 0
		|| ft_strcmp(cmd->args[0], "export") == 0
		|| ft_strcmp(cmd->args[0], "echo") == 0)
		return (1);
	return (0);
}

void	execute_cmd(t_command *cmd, char **envp)
{
	char	*expand;
	char	**path;
	int	i;
	char	*join;
	char	*tmp;

	i = 0;
	expand = expand_var("$PATH", envp);
	path = ft_split(expand, ':');
	while (path[i])
	{
		join = ft_strjoin(path[i], "/");
		tmp = join;
		join = ft_strjoin(join, cmd->args[0]);
		free(tmp);
		if (access(join, F_OK) == 0)
		{
			if (execve(join, cmd->args, envp) == -1)
			{
				perror("execve");
				free(join);
				exit(1);
			}
		}
		free(join);
		i++;
	}
	printf("%s: command not found\n", cmd->args[0]);
	exit (0);
}

void	my_pipe(t_command *cmd, char **envp)
{
	int		fd[2];
	int		in_fd;
	pid_t		pid;

	in_fd = 0;
	while (cmd)
	{
		if (cmd->next && pipe(fd) == -1)
		{
			perror("pipe");
			exit(1);
		}
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(1);
		}
		if (pid == 0)
		{
			if (in_fd != 0)
			{
				dup2(in_fd, STDIN_FILENO);
				close(in_fd);
			}
			if (cmd->next)
			{
				close(fd[0]);
				dup2(fd[1], STDOUT_FILENO);
				close(fd[1]);
			}
			/*if (cmd->redirect_count > 0)
				apply_redirects();
			if (is_builtin(cmd))
				execute_builtin(cmd);*/
			execute_cmd(cmd, envp);
		}
		else
		{
			if (in_fd != 0)
				close(in_fd);
			if (cmd->next)
			{
				close(fd[1]);
				in_fd = fd[0]; 
			}
			else
				if (fd[0] > 0)
					close(fd[0]);
		}
		cmd = cmd->next;
	}
	while (wait(NULL) > 0);
}
