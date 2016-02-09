/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 16:59:26 by brandazz          #+#    #+#             */
/*   Updated: 2014/03/18 12:58:59 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>

#include "env.h"
#include "sh.h"
#include "util.h"

static char		*find_cmd_loop(char **exec, int i, char **cmd)
{
	char	*path;

	path = add_file_to_path(exec[i], *cmd);
	if (access(path, F_OK) != -1)
	{
		if (access(path, X_OK) != -1)
		{
			strfree_2d(exec);
			return (path);
		}
		else
		{
			wait_children();
			g_exit_status = PERM_DENIED_EXIT_STATUS;
			print_err(path, PERMISSION_DENIED);
		}
	}
	free(path);
	return (0);
}

static char		*check_slash(char **cmd)
{
	if (ft_strcmp(cmd[0], "/") == 0)
	{
		wait_children();
		g_exit_status = NOT_FOUND_EXIT_STATUS;
		print_err(cmd[0], NO_SUCH_FILE_OR_DIR);
		return (NULL);
	}
	if (access(cmd[0], F_OK) != -1 && ft_strchr(cmd[0], '/'))
	{
		if (access(cmd[0], X_OK) != -1)
			return (ft_strdup(cmd[0]));
		wait_children();
		g_exit_status = PERM_DENIED_EXIT_STATUS;
		print_err(cmd[0], PERMISSION_DENIED);
	}
	else if (ft_strchr(cmd[0], '/'))
	{
		wait_children();
		g_exit_status = NOT_FOUND_EXIT_STATUS;
		print_err(cmd[0], NO_SUCH_FILE_OR_DIR);
	}
	return (NULL);
}

static char		*check_in_path(char **cmd)
{
	char		*path;
	int			i;
	char		**exec;

	if ((path = ft_getenv("PATH")) != NULL)
	{
		exec = ft_strsplit(path, ':');
		i = 0;
		while (exec[i])
		{
			if ((path = find_cmd_loop(exec, i++, cmd)))
				return (path);
		}
		strfree_2d(exec);
	}
	if (g_exit_status > 0)
		return (NULL);
	wait_children();
	g_exit_status = NOT_FOUND_EXIT_STATUS;
	print_err(cmd[0], CMD_NOT_FOUND);
	return (NULL);
}

char			*find_cmd(char **cmd)
{
	char	*path;
	int		old_status;

	old_status = g_exit_status;
	g_exit_status = 0;
	path = check_slash(cmd);
	if (path)
	{
		g_exit_status = old_status;
		return (path);
	}
	if (g_exit_status > 0)
		return (NULL);
	path = check_in_path(cmd);
	if (path)
	{
		g_exit_status = old_status;
		return (path);
	}
	return (NULL);
}
