/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 17:06:24 by brandazz          #+#    #+#             */
/*   Updated: 2014/03/27 13:56:49 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <libft.h>

#include "sh.h"
#include "builtins.h"
#include "sig.h"
#include "parser.h"

int		find_exec_cmd(char **arg, int io[2], char **env)
{
	char	*path;

	if (find_exec_builtin(arg, io) == 1)
		return (0);
	path = find_cmd(arg);
	if (path)
	{
		exec_cmd(path, arg, io, env);
		free(path);
		return (0);
	}
	reset_io(io);
	return (-1);
}

void	exec_cmd(char *path, char **arg, int io[2], char **env)
{
	pid_t	father;

	father = fork();
	if (father)
	{
		reset_io(io);
		return ;
	}
	if (io[0] != 0)
	{
		xdup2(io[0], 0);
		xclose(io[0]);
	}
	if (io[1] != 1)
	{
		xdup2(io[1], 1);
		xclose(io[1]);
	}
	if (execve(path, arg, env) < 0)
		exit(0);
}

void	wait_children(void)
{
	while (waitpid(-1, &g_exit_status, 0) > 0)
	{
		if (g_exit_status != SIGINT)
			print_signal(g_exit_status);
		g_exit_status = (g_exit_status & 0xFF00) >> 8;
	}
	if (g_interrupted)
	{
		g_interrupted = 0;
		ft_putchar('\n');
	}
}
