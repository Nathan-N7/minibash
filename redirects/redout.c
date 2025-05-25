#include "../libs/minishell.h"
#include "../my_lib/libft.h"
#include "../libs/structs.h"

void file_exists_redout(char *pathname)
{
    int fd;

	if (isdirectory(pathname))
	{
		write(2, "minishell: Is a directory\n", 25);
		return ;
	}
	fd = open(pathname, O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
	{
		write(2, "minishell: Permission denied\n", 30);
		return ;
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void new_file_redout(char *pathname)
{
	int fd;
    
    fd= open(pathname, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
	{
		write(2, "minishell: Permission denied\n", 30);
		return ;
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void handle_redout(t_redirect *redir, char **envp)
{
	char *fname;
	char *pathname;

    fname = redir->filename;
    pathname = create_pathname(fname, envp);
	if (!pathname)
		return ;
	if (access(pathname, F_OK) == 0)
		file_exists_redout(pathname);
	else
		new_file_redout(pathname);
	free(pathname);
}