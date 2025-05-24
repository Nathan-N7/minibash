/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:27:51 by natrodri          #+#    #+#             */
/*   Updated: 2025/05/20 16:23:58 by natrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/minishell.h"
#include "../my_lib/libft.h"
#include "../libs/structs.h"

void	execute_cmd(t_command *cmd, char **envp)
{
	char	*expand;
	char	**path;
	int		i;
	char	*join;
	char	*tmp;

	i = 0;
	expand = expand_var("$PATH", envp);
	path = ft_split(expand, ':');
	while (path[i])
	{
		join = ft_strjoin(path[i], "/");
		tmp = join;
		join = ft_strjoin(tmp, cmd->args[0]);
		free(tmp);
		if (access(join, F_OK && X_OK) == 0)
		{
			if (execve(join, cmd->args, envp) < 0)
				error_pipe(join, exec);
		}
		free(join);
		i++;
	}
	printf("%s: command not found\n", cmd->args[0]);
	exit (1);
}

void	son(int in_fd, int fd[2], t_command *cmd, char **envp)
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
		apply_redirects();*/
	if (is_builtin(cmd))
		execute_builtin(envp, cmd);
	else
		execute_cmd(cmd, envp);
	free_commands(cmd);
	exit (0);
}

void	father(int *in_fd, int fd[2], t_command *cmd)
{
	if (*in_fd != 0)
		close(*in_fd);
	if (cmd->next)
	{
		close(fd[1]);
		*in_fd = fd[0];
	}
	else
		if (fd[0] > 0)
			close(fd[0]);
}

void	my_pipe(t_command *cmd, char **envp)
{
	int		fd[2];
	int		in_fd;
	pid_t	pid;

	in_fd = 0;
	fd[0] = -1;
	fd[1] = -1;
	while (cmd)
	{
		if (builtin_father(cmd) && !cmd->next)
		{
			execute_builtin(envp, cmd);
			break ;
		}
		if (cmd->next && pipe(fd) == -1)
		{
			perror("pipe");
			exit(1);
		}
		pid = fork();
		if (pid == -1)
			error_pipe(NULL, pid);
		if (pid == 0)
			son(in_fd, fd, cmd, envp);
		else
			father(&in_fd, fd, cmd);
		cmd = cmd->next;
	}
	while (wait(NULL) > 0)
		;
}
/*[cmd1] ---stdout---> [pipe1] ---stdin---> [cmd2] ---stdout---> [pipe2] ---stdin---> [cmd3]
          	(fd[1])              (fd[0])         	 (fd[1])                fd[0])
*/
