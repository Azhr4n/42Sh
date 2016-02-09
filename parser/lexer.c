/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 17:32:50 by brandazz          #+#    #+#             */
/*   Updated: 2014/03/26 15:00:26 by jpontat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "parser.h"

static t_type	g_type[] = {
	{" \t", T_WHITESPACE},
	{";", T_SEMICOL},
	{"|", T_PIPE},
	{"&", T_AMPERSAND},
	{"<", T_INFERIOR},
	{">", T_SUPERIOR},
	{"\"", T_DQUOTE},
	{"'", T_SQUOTE},
	{"`", T_BQUOTE},
	{NULL, 0}
};

static int		get_type(const char c)
{
	int				i;

	i = 0;
	while (g_type[i].charset)
	{
		if (ft_strchr(g_type[i].charset, c))
			return (g_type[i].type);
		i++;
	}
	return (T_ANYTHING);
}

static void		add_token(t_lexer *l)
{
	t_list	*elem;

	if (l->i <= 0)
		return ;
	elem = ft_lstnew(&(l->token), sizeof(t_token));
	if (!elem)
		fatal("ft_lstnew");
	if (l->lst)
		ft_lstadd_back(&(l->lst), elem);
	else
		l->lst = elem;
	l->i = 0;
	ft_bzero(&(l->token), sizeof(t_token));
}

static int		isquote(int type)
{
	return (type == T_DQUOTE || type == T_SQUOTE || type == T_BQUOTE);
}

static int		set_qbool(t_lexer *l, const char *str)
{
	if (l->qtype)
	{
		if (l->qtype && l->qtype == *str && *(str - 1) != '\\')
			l->qtype = 0;
		return (0);
	}
	l->qtype = *str;
	return (1);
}

t_list			*lexer(const char *str)
{
	t_lexer		l;

	ft_bzero(&l, sizeof(t_lexer));
	l.token.type = T_ANYTHING;
	while (*str)
	{
		l.next_type = get_type(*str);
		if (isquote(l.next_type))
			l.qbool = set_qbool(&l, str);
		if (l.qtype && (l.next_type != get_type(l.qtype) || ESCAPED_QUOTE))
			l.next_type = T_ANYTHING;
		if (l.next_type != l.token.type && !isquote(l.next_type))
			add_token(&l);
		if (l.next_type != T_WHITESPACE && !isquote(l.next_type) && ND_QUOTE)
		{
			l.token.str[l.i++] = *str;
			l.token.type = l.next_type;
		}
		str++;
	}
	add_token(&l);
	return (l.lst);
}
