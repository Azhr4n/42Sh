/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 16:44:09 by brandazz          #+#    #+#             */
/*   Updated: 2014/03/27 11:16:21 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "sh.h"
#include "env.h"
#include "parser.h"

void			reset_io(int io[2])
{
	if (io[0] != 0 && io[0] > 0)
		xclose(io[0]);
	if (io[1] != 1 && io[1] > 0)
		xclose(io[1]);
	io[0] = 0;
	io[1] = 1;
}

static int		is_separator(int type)
{
	return ((type == N_SEPARATOR) || (type == N_AND) || (type == N_OR));
}

static void		abort_and_or(t_parser *p)
{
	p->prev_prev_node = p->prev_node;
	p->prev_node = p->node;
	reset_io(p->io);
}

static void		interpreter_loop(t_parser *p, t_list *lst)
{
	p->node = (t_ast *)lst->content;
	if (p->node->type == N_PIPE)
		make_pipe(p);
	else if (is_separator(p->node->type) && p->prev_node)
	{
		if (p->prev_prev_node)
		{
			if (p->prev_prev_node->type == N_AND && g_exit_status != 0)
				return (abort_and_or(p));
			if (p->prev_prev_node->type == N_OR && g_exit_status == 0)
				return (abort_and_or(p));
		}
		find_exec_cmd(p->prev_node->str, p->io, g_env);
		wait_children();
		reset_io(p->io);
	}
	else if (p->node->type == N_CMD)
		make_redir(p);
	p->prev_prev_node = p->prev_node;
	p->prev_node = p->node;
}

void			interpreter(t_parser *p)
{
	t_list	*lst;

	p->io[0] = 0;
	p->io[1] = 1;
	lst = p->traverse;
	while (lst)
	{
		interpreter_loop(p, lst);
		lst = lst->next;
	}
	if (p->node && p->node->type == N_CMD && p->io[0] >= 0 && p->io[1] >= 0)
	{
		if (p->prev_prev_node)
		{
			if (p->prev_prev_node->type == N_AND && g_exit_status != 0)
				return (reset_io(p->io));
			if (p->prev_prev_node->type == N_OR && g_exit_status == 0)
				return (reset_io(p->io));
		}
		find_exec_cmd(p->node->str, p->io, g_env);
		wait_children();
	}
}
