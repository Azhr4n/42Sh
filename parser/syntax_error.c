/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 11:08:39 by brandazz          #+#    #+#             */
/*   Updated: 2014/03/14 15:46:21 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "prompts.h"
#include "parser.h"
#include "sh.h"

static void		free_tree(t_ast *first, t_ast *node, t_ast *tree)
{
	if (node->left && node->left != tree)
		free_tree(first, node->left, tree);
	if (node->right && node->right != tree)
		free_tree(first, node->right, tree);
	if (node != first)
		free(node);
}

int				syntax_error(const char *token, t_ast *tree, t_ast *node)
{
	if (!g_syntax_err)
	{
		g_syntax_err = 1;
		ft_putstr_fd(PROG_NAME, 2);
		ft_putstr_fd(": syntax error near unexpected token `", 2);
		ft_putstr_fd(token, 2);
		ft_putendl_fd("'", 2);
		g_mood = M_CONFUSED;
	}
	free_tree(node, node, tree);
	return (FALSE);
}
