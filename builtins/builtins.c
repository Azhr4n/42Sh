/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpontat <jpontat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 11:22:33 by jpontat           #+#    #+#             */
/*   Updated: 2014/03/27 11:49:37 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>

#include "sh.h"
#include "builtins.h"

static t_built		g_builtins[] = {
	{"cd", b_cd},
	{"exit", b_exit},
	{"env", b_env},
	{"setenv", b_setenv},
	{"unsetenv", b_unsetenv},
	{"echo", b_echo},
	{NULL, 0}
};

static void		set_builtin_io(int fd[2], int io[2], int index)
{
	if (io[index] != index)
	{
		fd[index] = xdup(index);
		xdup2(io[index], index);
		xclose(io[index]);
		io[index] = index;
	}
}

static void		exec_builtin(char **buff, int io[2], void (*f)(char **),
								int fd[2])
{
	fd[0] = 0;
	fd[1] = 1;
	set_builtin_io(fd, io, 0);
	set_builtin_io(fd, io, 1);
	f(buff);
	if (fd[0] != 0)
	{
		xdup2(fd[0], 0);
		xclose(fd[0]);
	}
	if (fd[1] != 1)
	{
		xdup2(fd[1], 1);
		xclose(fd[1]);
	}
}

int				find_exec_builtin(char **buff, int io[2])
{
	int			i;
	int			fd[2];

	i = 0;
	while (g_builtins[i].cmd)
	{
		if (ft_strcmp(g_builtins[i].cmd, buff[0]) == 0)
		{
			exec_builtin(buff, io, g_builtins[i].fct, fd);
			return (1);
		}
		i++;
	}
	return (0);
}
