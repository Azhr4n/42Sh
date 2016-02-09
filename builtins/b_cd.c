/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:39:28 by pivanovi          #+#    #+#             */
/*   Updated: 2014/03/14 10:30:18 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>

#include "builtins.h"
#include "env.h"
#include "sh.h"

static void		b_cd_sub(char *name)
{
	char	*pwd;
	char	*oldpwd;

	pwd = NULL;
	if (!access(name, F_OK))
	{
		if (access(name, R_OK) == -1)
			print_err("cd", PERMISSION_DENIED);
		else if (!chdir(name))
		{
			if (!ft_strcmp(name, ft_getenv("OLDPWD")))
				ft_putendl(ft_getenv("OLDPWD"));
			oldpwd = ft_getenv("PWD");
			pwd = getcwd(pwd, 1);
			ft_setenv("OLDPWD", oldpwd, 1);
			ft_setenv("PWD", pwd, 1);
			free(pwd);
		}
		else
			fatal("chdir");
	}
	else
		print_err("cd", NO_SUCH_FILE_OR_DIR);
}

static void		opt_p(char **buffer, char *b_link)
{
	if (buffer[2] && access(buffer[2], F_OK) != -1)
	{
		if (access(buffer[2], R_OK) == -1)
			print_err("cd", PERMISSION_DENIED);
		ft_bzero(b_link, 1024);
		if (buffer[2] && readlink(buffer[2], b_link, 1024) != -1)
			b_cd_sub(b_link);
		else if (buffer[2] && readlink(buffer[2], b_link, 1024) == -1)
			b_cd_sub(buffer[2]);
	}
	else
		print_err("cd", NO_SUCH_FILE_OR_DIR);
}

static void		opt_l(char **buffer)
{
	if (buffer[2] && access(buffer[2], F_OK) != -1)
	{
		if (access(buffer[2], R_OK) == -1)
			print_err("cd", PERMISSION_DENIED);
		b_cd_sub(buffer[2]);
	}
	else
		print_err("cd", NO_SUCH_FILE_OR_DIR);
}

static void		test_getenv(char *name)
{
	char	*pwd;

	if ((pwd = ft_getenv(name)))
		b_cd_sub(pwd);
	else
		print_err("cd", NO_OLDPWD);
}

void			b_cd(char **buffer)
{
	char	b_link[1024];

	if (buffer[1] && buffer[1][0] == '-')
	{
		if (buffer[1][1] == 'P' && buffer[2])
			opt_p(buffer, b_link);
		else if (buffer[1][1] == 'L' && buffer[2])
			opt_l(buffer);
		else if (!buffer[1][1])
			test_getenv("OLDPWD");
	}
	else if (!buffer[1])
		test_getenv("HOME");
	else
		b_cd_sub(buffer[1]);
}
