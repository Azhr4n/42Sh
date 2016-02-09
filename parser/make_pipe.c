/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 16:25:16 by brandazz          #+#    #+#             */
/*   Updated: 2014/03/27 11:14:37 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "env.h"
#include "sh.h"
#include "parser.h"

void	make_pipe(t_parser *p)
{
	if (pipe(p->fd) < 0)
		fatal("pipe");
	if (p->io[1] == 1)
		p->io[1] = p->fd[1];
	else
		xclose(p->fd[1]);
	if (p->prev_node)
		find_exec_cmd(p->prev_node->str, p->io, g_env);
	reset_io(p->io);
	p->io[0] = p->fd[0];
}
