/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 17:12:51 by brandazz          #+#    #+#             */
/*   Updated: 2014/03/27 19:18:17 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <libft.h>

#include "sh.h"
#include "parser.h"
#include "env.h"
#include "prompts.h"
#include "sig.h"
#include "util.h"

int				g_exit_status = 0;
int				g_interrupted = 0;
int				g_mood = M_HAPPY;

static void		init_shell(void)
{
	catch_environ();
	init_sig();
}

static int		read_input(char **line)
{
	int		ret;

	*line = NULL;
	if ((ret = get_next_line(0, line)) < 0)
	{
		if (g_interrupted)
		{
			g_interrupted = 0;
			free(*line);
			ft_putchar('\n');
			return (ret);
		}
		fatal("get_next_line");
	}
	if (ret != 0 && (ret = quotes_cmd(line)) < 0)
	{
		free(*line);
		ft_putchar('\n');
		return (ret);
	}
	return (ret);
}

static void		prompt(void)
{
	putprompt(g_mood, C_BOLD_GREEN, 1);
	if (g_mood != M_HAPPY)
		g_mood = M_HAPPY;
}

static void		end_shell(char *line)
{
	if (line)
		free(line);
	ft_putendl("exit");
}

int				main(void)
{
	char	*line;
	t_list	*lst;
	int		ret;

	init_shell();
	ret = 1;
	while (ret != 0)
	{
		prompt();
		if ((ret = read_input(&line)) <= 0)
			continue ;
		if (ft_strlen(line) < ARG_MAX)
		{
			if ((lst = lexer(line)))
			{
				parser(lst);
				ft_lstdel(&lst, del_lst);
			}
		}
		else
			print_err(NULL, ARG_LIST_TOO_LONG);
		free(line);
	}
	end_shell(line);
	return (0);
}
