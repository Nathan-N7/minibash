/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarreto <lbarreto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:48:05 by natrodri          #+#    #+#             */
/*   Updated: 2025/05/27 19:29:46 by lbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/minishell.h"
#include "../libs/structs.h"
#include "../my_lib/libft.h"

void	handle_variable(t_expand *exp, t_envp *env)
{
	char	*val;

	exp->idx->i++;
	exp->idx->k = 0;
	if (exp->src[exp->idx->i] == '?')
	{
		val = ft_itoa(env->last_stats);
		while (val[exp->idx->k])
			exp->buffer[exp->idx->j++] = val[exp->idx->k++];
		free(val);
		exp->idx->i++;
		return ;
	}
	while (exp->src[exp->idx->i] && (ft_isalnum(exp->src[exp->idx->i])
			|| exp->src[exp->idx->i] == '_'))
		exp->varname[exp->idx->k++] = exp->src[exp->idx->i++];
	exp->varname[exp->idx->k] = '\0';
	val = get_value(exp->varname, env->envp);
	if (!val)
		val = ft_strdup("");
	exp->idx->m = 0;
	while (val[exp->idx->m])
		exp->buffer[exp->idx->j++] = val[exp->idx->m++];
	free(val);
}

void	handle_single_quote(t_expand *exp)
{
	exp->idx->i++;
	while (exp->src[exp->idx->i] && exp->src[exp->idx->i] != '\'')
		exp->buffer[exp->idx->j++] = exp->src[exp->idx->i++];
	if (exp->src[exp->idx->i] == '\'')
		exp->idx->i++;
}

void	handle_double_quote(t_expand *exp, t_envp *env)
{
	exp->idx->i++;
	while (exp->src[exp->idx->i] && exp->src[exp->idx->i] != '\"')
	{
		if (exp->src[exp->idx->i] == '$'
			&& ft_isalnum(exp->src[exp->idx->i + 1]))
			handle_variable(exp, env);
		else
			exp->buffer[exp->idx->j++] = exp->src[exp->idx->i++];
	}
	if (exp->src[exp->idx->i] == '\"')
		exp->idx->i++;
}

void	process_char(t_expand *exp, t_envp *env)
{
	if (exp->src[exp->idx->i] == '\'')
		handle_single_quote(exp);
	else if (exp->src[exp->idx->i] == '\"')
		handle_double_quote(exp);
	else if (exp->src[exp->idx->i] == '$'
		&& (ft_isalnum(exp->src[exp->idx->i + 1]) 
		|| exp->src[exp->idx->i + 1] == '_'))
		handle_variable(exp);
	else
		exp->buffer[exp->idx->j++] = exp->src[exp->idx->i++];
}

char	*expand_var(char *src, t_envp *env)
{
	t_indexvar	idx;
	char		buffer[4096];
	char		varname[256];
	t_expand	exp;

	exp.src = src;
	exp.idx = &idx;
	exp.buffer = buffer;
	exp.varname = varname;
	idx.i = 0;
	idx.j = 0;
	while (src[idx.i])
		process_char(&exp, env);
	buffer[idx.j] = '\0';
	return (ft_strdup(buffer));
}
