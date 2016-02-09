/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_or.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/21 15:31:27 by brandazz          #+#    #+#             */
/*   Updated: 2014/03/26 15:15:11 by jpontat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "parser.h"

/*
** or ::= pipe [N_OR or]?
*/

static int	read_or_sub(t_ast **tree, t_list **tokens, t_ast *node)
{
	t_token		*t;

	if (*tokens)
	{
		t = (t_token *)(*tokens)->content;
		if (ft_strcmp(t->str, "||") == 0 && *tree)
		{
			node->str[0] = t->str;
			*tokens = (*tokens)->next;
			node->left = *tree;
			*tree = NULL;
			read_or(tree, tokens);
			if (*tree == node->left)
				return (syntax_error(t->str, *tree, node));
			node->right = *tree;
			if (node->left == NULL || node->right == NULL)
				return (syntax_error(t->str, *tree, node));
			*tree = node;
			return (TRUE);
		}
		else if (count_char(t->str, '|') > 1)
			syntax_error(t->str, *tree, node);
	}
	return (FALSE);
}

int			read_or(t_ast **tree, t_list **tokens)
{
	t_ast	*node;

	if (g_syntax_err)
		return (FALSE);
	if (!*tokens)
		return (FALSE);
	node = create_node();
	node->type = N_OR;
	read_pipe(tree, tokens);
	if (read_or_sub(tree, tokens, node) == TRUE)
		return (TRUE);
	free(node);
	return (FALSE);
}
