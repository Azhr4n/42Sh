/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_exp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/21 14:43:25 by brandazz          #+#    #+#             */
/*   Updated: 2014/02/21 14:43:26 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** exp ::= separator_exp
*/
int		read_exp(t_ast **tree, t_list **tokens)
{
	if (read_separator(tree, tokens) == TRUE)
		return (TRUE);
	return (FALSE);
}
