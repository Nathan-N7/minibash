#include "../libs/minishell.h"
#include "../my_lib/libft.h"
#include "../libs/structs.h"

void file_exists_append(char *pathname)
{
    int fd;

	if (isdirectory(pathname))
	{
		dprintf(2, "minishell: %s: Is a directory\n", pathname);
		return ;
	}
	fd = open(pathname, O_WRONLY | O_APPEND);
	if (fd < 0)
	{
		dprintf(2, "minishell: %s: Permission denied\n", pathname);
		return ;
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void new_file_append(char *pathname)
{
    int fd;

	fd = open(pathname, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
	{
		dprintf(2, "minishell: %s: Permission denied\n", pathname);
		return ;
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void handle_append(t_redirect *redir, int *error_flag, char **envp)
{
    char    *fname;
    char    *pathname;
	
    fname = redir->filename;
	pathname = create_pathname(fname, envp);
	if (!pathname)
		return;
	if (access(pathname, F_OK) == 0)
		file_exists_append(pathname);
	else
		new_file_append(pathname);
	free(pathname);
}