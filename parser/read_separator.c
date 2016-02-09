/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_separator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/21 14:43:34 by brandazz          #+#    #+#             */
/*   Updated: 2014/03/26 15:16:40 by jpontat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "parser.h"

/*
** separator_exp ::= [and | or] [N_SEPARATOR [exp]]?
*/

static int	read_separator_sub(t_ast **tree, t_list **tokens, t_ast *node)
{
	t_token		*t;

	if (*tokens)
	{
		t = (t_token *)(*tokens)->content;
		if (ft_strcmp(t->str, ";") == 0)
		{
			node->str[0] = t->str;
			*tokens = (*tokens)->next;
			if (!*tree)
				return (syntax_error(t->str, *tree, node));
			node->left = *tree;
			*tree = NULL;
			read_exp(tree, tokens);
			if (*tree != node->left)
				node->right = *tree;
			*tree = node;
			return (TRUE);
		}
		else if (ft_strchr(t->str, ';'))
			return (syntax_error(t->str, *tree, node));
	}
	return (FALSE);
}

int			read_separator(t_ast **tree, t_list **tokens)
{
	t_ast		*node;

	if (g_syntax_err)
		return (FALSE);
	if (!*tokens)
		return (FALSE);
	node = create_node();
	node->type = N_SEPARATOR;
	while (read_and(tree, tokens) || read_or(tree, tokens))
		;
	if (read_separator_sub(tree, tokens, node) == TRUE)
		return (TRUE);
	free(node);
	return (FALSE);
}
