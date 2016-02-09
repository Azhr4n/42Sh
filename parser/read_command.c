/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/21 14:43:30 by brandazz          #+#    #+#             */
/*   Updated: 2014/03/26 15:14:22 by jpontat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "parser.h"

/*
** command ::= ANYTHING [ANYTHING]*
*/

static int	is_valid_type(int t)
{
	return ((t == T_ANYTHING) || (t == T_INFERIOR) || (t == T_SUPERIOR));
}

static int	read_redir(t_list **tok, t_ast *n, t_token **t, int *j)
{
	n->redir[*j] = (*t)->str;
	(*j)++;
	*tok = (*tok)->next;
	if (!*tok)
		return (FALSE);
	*t = (t_token *)(*tok)->content;
	if ((*t)->type != T_ANYTHING)
		return (FALSE);
	n->redir[*j] = (*t)->str;
	(*j)++;
	return (TRUE);
}

static int	read_command_sub(t_ast **tree, t_list **l, t_ast *n, t_token **t)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*t && is_valid_type((*t)->type))
	{
		if ((*t)->type == T_ANYTHING)
			n->str[i++] = (*t)->str;
		else
		{
			if (read_redir(l, n, t, &j) == FALSE)
				return (syntax_error((*t)->str, *tree, n));
		}
		*l = (*l)->next;
		*t = (*l) ? (t_token *)(*l)->content : NULL;
	}
	if (!*t && i <= 0)
		return (FALSE);
	if (i <= 0)
		return (syntax_error((*t)->str, *tree, n));
	*tree = n;
	return (TRUE);
}

int			read_command(t_ast **tree, t_list **tokens)
{
	t_ast		*node;
	t_token		*t;

	if (g_syntax_err)
		return (FALSE);
	if (!*tokens)
		return (FALSE);
	node = create_node();
	node->type = N_CMD;
	t = (t_token *)(*tokens)->content;
	if (is_valid_type(t->type))
	{
		if (read_command_sub(tree, tokens, node, &t) == TRUE)
			return (TRUE);
	}
	free(node);
	return (FALSE);
}
