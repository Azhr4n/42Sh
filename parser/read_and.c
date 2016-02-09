/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/21 16:01:30 by brandazz          #+#    #+#             */
/*   Updated: 2014/03/26 15:11:39 by jpontat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "parser.h"

/*
** and ::= pipe [N_AND and]?
*/

static int	read_and_sub(t_ast **tree, t_list **tokens, t_ast *node)
{
	t_token		*t;

	if (*tokens)
	{
		t = (t_token*)(*tokens)->content;
		if (!ft_strcmp(t->str, "&&") && *tree)
		{
			node->str[0] = t->str;
			*tokens = (*tokens)->next;
			node->left = *tree;
			*tree = NULL;
			read_and(tree, tokens);
			if (*tree == node->left)
				return (syntax_error(t->str, *tree, node));
			node->right = *tree;
			if (node->left == NULL || node->right == NULL)
				return (syntax_error(t->str, *tree, node));
			*tree = node;
			return (TRUE);
		}
		else if (ft_strchr(t->str, '&'))
			return (syntax_error(t->str, *tree, node));
	}
	return (FALSE);
}

int			read_and(t_ast **tree, t_list **tokens)
{
	t_ast	*node;

	if (g_syntax_err)
		return (FALSE);
	if (!*tokens)
		return (FALSE);
	node = create_node();
	node->type = N_AND;
	read_pipe(tree, tokens);
	if (read_and_sub(tree, tokens, node) == TRUE)
		return (TRUE);
	free(node);
	return (FALSE);
}
