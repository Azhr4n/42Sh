/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/21 18:38:11 by brandazz          #+#    #+#             */
/*   Updated: 2014/03/26 15:07:52 by jpontat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "parser.h"
#include "sh.h"

/*
** S ::= [exp]+
*/

int				g_syntax_err;

static void		traverse_tree(t_ast *tree, t_list **traverse)
{
	t_list	*elem;

	if (tree->left)
		traverse_tree(tree->left, traverse);
	elem = ft_lstnew(tree, sizeof(t_ast));
	if (!elem)
		fatal("ft_lstnew");
	if (*traverse)
		ft_lstadd_back(traverse, elem);
	else
		*traverse = elem;
	if (tree->right)
		traverse_tree(tree->right, traverse);
}

static void		free_tree(t_ast *tree)
{
	if (tree->left)
		free_tree(tree->left);
	if (tree->right)
		free_tree(tree->right);
	free(tree);
}

static void		free_traverse(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

static t_ast	*create_ast(t_list *tokens)
{
	t_ast		*tree;

	tree = NULL;
	g_syntax_err = 0;
	read_exp(&tree, &tokens);
	if (g_syntax_err)
	{
		if (tree)
			free_tree(tree);
		return (NULL);
	}
	return (tree);
}

void			parser(t_list *tokens)
{
	t_parser	p;

	ft_bzero(&p, sizeof(t_parser));
	p.tree = create_ast(tokens);
	if (p.tree)
	{
		traverse_tree(p.tree, &p.traverse);
		free_tree(p.tree);
		interpreter(&p);
		ft_lstdel(&p.traverse, free_traverse);
	}
}
