/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 16:10:54 by brandazz          #+#    #+#             */
/*   Updated: 2014/03/27 14:02:24 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#include "sh.h"
#include "parser.h"

static t_redir	g_tab[] = {
	{"<", 0, redir_input},
	{">", 1, redir_output},
	{">>", 1, redir_output_append},
	{NULL, 0, 0}
};

int				redir_output(const char *file)
{
	int		fd;

	fd = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
	{
		print_err(file, PERMISSION_DENIED);
		return (-1);
	}
	return (fd);
}

int				redir_output_append(const char *file)
{
	int		fd;

	fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
	{
		print_err(file, PERMISSION_DENIED);
		return (-1);
	}
	return (fd);
}

int				redir_input(const char *file)
{
	int		fd;

	if (access(file, F_OK) == -1)
	{
		print_err(file, NO_SUCH_FILE_OR_DIR);
		return (-1);
	}
	if (access(file, R_OK) == -1)
	{
		print_err(file, PERMISSION_DENIED);
		return (-1);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
		fatal("open");
	return (fd);
}

static int		find_redir(t_parser *p, int i)
{
	int				k;

	k = 0;
	while (g_tab[k].str)
	{
		if (ft_strcmp(g_tab[k].str, p->node->redir[i]) == 0)
		{
			if (p->io[g_tab[k].io_index] != g_tab[k].io_index)
				xclose(p->io[g_tab[k].io_index]);
			p->io[g_tab[k].io_index] = g_tab[k].fct(p->node->redir[++i]);
		}
		k++;
	}
	return (i + 1);
}

void			make_redir(t_parser *p)
{
	int		i;

	i = 0;
	while (p->node->redir[i])
	{
		i = find_redir(p, i);
		if (p->io[0] < 0 || p->io[1] < 0)
		{
			if (p->io[0] != 0)
			{
				if (p->io[0] > 0)
					xclose(p->io[0]);
				p->io[0] = 0;
			}
			if (p->io[1] != 1)
			{
				if (p->io[1] > 0)
					xclose(p->io[1]);
				p->io[1] = 1;
			}
			g_exit_status = 1;
			p->node = 0;
			return ;
		}
	}
}
