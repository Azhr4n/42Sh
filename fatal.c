/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 17:16:02 by brandazz          #+#    #+#             */
/*   Updated: 2014/03/26 14:51:04 by jpontat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

#include "prompts.h"
#include "sh.h"

static char		*g_errlist[] = {
	"Argument list too long",
	"command not found",
	"No such file or directory",
	"Permission denied",
	"OLDPWD is not set",
	"Illegal option",
	"Numeric argument required",
	"Too many arguments",
	"Syntax error",
	"Too few arguments",
	NULL
};

void	failed(const char *err)
{
	ft_putstr_fd(PROG_NAME, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(err, 2);
	g_mood = M_DEAD;
}

void	print_err(const char *cause, const int err)
{
	ft_putstr_fd(PROG_NAME, 2);
	ft_putstr_fd(": ", 2);
	if (cause)
	{
		ft_putstr_fd(cause, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putendl_fd(g_errlist[err], 2);
	g_mood = M_BORED;
}

void	fatal(const char *err)
{
	failed(err);
	exit(1);
}
