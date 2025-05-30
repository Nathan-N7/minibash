/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:55:43 by natrodri          #+#    #+#             */
/*   Updated: 2025/05/29 10:33:30 by natrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum s_tk_type
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	APPEND,
	HEREDOC
}	t_tk_type;

typedef enum s_op
{
	exec,
	pid
}	t_op;

typedef struct s_redirect
{
	t_tk_type	type;
	char		*filename;
}	t_redirect;

typedef struct s_command
{
	char				**args;
	t_redirect			*redirects;
	int					redirect_count;
	int					in_fd;
	struct s_command	*next;
}	t_command;

typedef struct s_indexvar
{
	int	i;
	int	k;
	int	j;
	int	m;
}	t_indexvar;

typedef struct s_expand
{
	char		*src;
	t_indexvar	*idx;
	char		*buffer;
	char		*varname;
}	t_expand;

typedef struct s_token
{
	t_tk_type		type;
	char			*value;
	struct s_token	*next;
}	t_token;

typedef struct s_envp
{
	char	**envp;
	int		last_stats;
}	t_envp;

#endif
