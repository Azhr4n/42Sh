/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 17:34:54 by pivanovi          #+#    #+#             */
/*   Updated: 2014/03/14 15:13:29 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>

#include "builtins.h"
#include "util.h"
#include "env.h"
#include "sh.h"

static int	get_i_opt(char **buffer)
{
	if (buffer[1] && buffer[1][0] == '-')
	{
		if (buffer[1][1] && buffer[1][1] != 'i')
		{
			print_err(buffer[1], ILLEGAL_OPTION);
			return (-1);
		}
		return (1);
	}
	return (0);
}

static void	tiny_setenv(const char *var)
{
	char	*ptr;
	char	*name;

	ptr = ft_strchr(var, '=');
	name = ft_strsub(var, 0, ptr - var);
	if (!name)
		fatal("ft_strsub");
	ptr++;
	ft_setenv(name, ptr, 1);
	free(name);
}

static void	b_env_find_exec(char **arg, char **env)
{
	char	*path;
	pid_t	father;

	path = find_cmd(arg);
	if (path)
	{
		father = fork();
		if (father == 0)
		{
			if (execve(path, arg, env) < 0)
				exit(0);
		}
		wait_children();
		free(path);
		return ;
	}
	g_exit_status = NOT_FOUND_EXIT_STATUS;
	print_err(arg[0], NO_SUCH_FILE_OR_DIR);
}

static int	fill_env(char **buffer, char ***tmp_env, int i)
{
	char	**orig_env;

	orig_env = g_env;
	g_env = *tmp_env;
	while (buffer[i] && ft_strchr(buffer[i], '='))
	{
		tiny_setenv(buffer[i]);
		i++;
	}
	*tmp_env = g_env;
	g_env = orig_env;
	return (i);
}

void		b_env(char **buffer)
{
	int		i_opt;
	char	**tmp_env;
	int		i;

	i_opt = get_i_opt(buffer);
	if (i_opt < 0)
		return ;
	if (!i_opt)
		tmp_env = strdup_2d(g_env);
	else
	{
		tmp_env = (char **)malloc(sizeof(char *) * 2);
		ft_bzero(tmp_env, sizeof(char *) * 2);
	}
	i = i_opt + 1;
	i = fill_env(buffer, &tmp_env, i);
	if (!buffer[i])
		ft_print_env(tmp_env);
	else
		b_env_find_exec(&(buffer[i]), tmp_env);
	strfree_2d(tmp_env);
}
