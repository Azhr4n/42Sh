/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 20:21:46 by gmarais           #+#    #+#             */
/*   Updated: 2014/03/26 15:27:37 by jpontat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

#include "env.h"
#include "prompts.h"

/*
** examples of config:
** config GAWUDA :
** PT_CONFIG "5/16;0/11/0"
** PT_FIX_COLOR "0/0;1/0;2/0;3/0;4/0;5/0;6/0;7/0;8/0;9/0;10/0"
** config HELL :
** PT_CONFIG "6/1/10;2/1/10"
** PT_FIX_COLOR "0/10;1/10;2/10;3/10;4/1;5/10;6/14;7/1;8/14;9/14;10/14"
*/
static char	*g_prompt[] = {
	"(>'_')>\033[0m ",
	"(>^_^)>\033[0m ",
	"(>T_T)>\033[0m ",
	"( x_x)>\033[0m ",
	"('-_-)>\033[0m ",
	"( >C<)>\033[0m ",
	"(>*^*)>\033[0m ",
	"( ~_~)>\033[0m ",
	"(?o_O)>\033[0m ",
	"(>@_@)>\033[0m ",
	"(>'x')>\033[0m ",
};

static char	*get_prompt_arg(int type)
{
	char	*res;

	res = NULL;
	if (type == A_USER)
		res = ft_getenv("USER");
	else if (type == A_GROUP)
		res = ft_getenv("GROUP");
	else if (type == A_LOGIN)
		res = ft_getenv("LOGNAME");
	else if (type == A_TIME || type == A_LTIME)
		res = pt_get_time(type);
	else if (type == A_PWD)
		res = pt_get_pwd();
	return (res);
}

static void	putprompt_arg(char *arg, int color, int color_sep)
{
	if (color_sep)
	{
		puttermcolor(color_sep);
		ft_putchar('[');
	}
	if (color)
	{
		puttermcolor(color);
		ft_putstr(arg);
	}
	if (color_sep)
	{
		puttermcolor(color_sep);
		ft_putchar(']');
	}
}

static void	pt_arg(void)
{
	char	**arg_tab;
	char	*line;
	int		type;
	int		color[2];
	int		i;

	if (!(line = ft_getenv("PT_CONFIG"))
		|| !(arg_tab = ft_strsplit(line, ';')))
		return ;
	i = -1;
	while (arg_tab[++i])
	{
		if ((line = ft_strchr(arg_tab[i], '/')) && line[1])
		{
			type = ft_atoi(arg_tab[i]);
			color[0] = ft_atoi(line + 1);
			line = ft_strchr(line + 1, '/');
			color[1] = (line && line[1]) ? ft_atoi(line + 1) : color[0];
			if (type >= 0 && type <= A_TIME && (line = get_prompt_arg(type)))
				putprompt_arg(line, color[0], color[1]);
		}
		free(arg_tab[i]);
	}
	free(arg_tab);
}

int			pt_fix_color(int mood, int prevcolor)
{
	char	**arg_tab;
	char	*line;
	int		type;
	int		color;
	int		i;

	if (!(line = ft_getenv("PT_FIX_COLOR"))
		|| !(arg_tab = ft_strsplit(line, ';')))
		return (prevcolor);
	i = -1;
	while (arg_tab[++i])
	{
		if ((line = ft_strchr(arg_tab[i], '/')) && line[1])
		{
			type = ft_atoi(arg_tab[i]);
			color = ft_atoi(line + 1);
			if (type == mood)
				prevcolor = color;
		}
		free(arg_tab[i]);
	}
	free(arg_tab);
	return (prevcolor);
}

void		putprompt(int mood, int color, int with_arg)
{
	if (with_arg)
		pt_arg();
	color = pt_fix_color(mood, color);
	if (color)
	{
		puttermcolor(color);
		ft_putstr(g_prompt[mood]);
	}
	else
		ft_putstr(">\033[0m ");
}
