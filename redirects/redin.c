#include "../libs/minishell.h"
#include "../my_lib/libft.h"
#include "../libs/structs.h"

void execute_redin(char *pathname)
{
    int fd;
	if (isdirectory(pathname))
	{
		write(2, "minishell: Is a directory\n", 27);
		return;
	}
	fd = open(pathname, O_RDONLY);
	if (fd < 0)
	{
		write(2, "minishell: No such file or directory\n", 38);
		return ;
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
}

void handle_redin(t_redirect *redir, char **envp)
{
	char *fname;
	char *pathname;

    fname = redir->filename;
    pathname = create_pathname(fname, envp);
	if (!pathname)
		return ;
	execute_redin(pathname);
	free(pathname);
}