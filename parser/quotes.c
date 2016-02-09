/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 20:11:37 by gmarais           #+#    #+#             */
/*   Updated: 2014/03/26 18:45:18 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

#include "prompts.h"
#include "parser.h"

static void	put_quotes_prompt(char qtype)
{
	puttermcolor(pt_fix_color(M_NORMAL, C_BOLD_YELLOW));
	if (qtype == '\'')
		ft_putstr("[simple quote]");
	if (qtype == '"')
		ft_putstr("[double quote]");
	if (qtype == '`')
		ft_putstr("[back quote]");
	putprompt(M_NORMAL, C_BOLD_YELLOW, 0);
}

static int	sub_quotes(int *i, char **cmd, char qtype)
{
	char	*tmp;
	char	*buf;
	int		bol;
	int		ret;

	bol = 0;
	while ((*cmd)[*i] && ((*cmd)[*i] != qtype || NOT_END_QUOTE))
	{
		if (!(*cmd)[*i + 1])
		{
			put_quotes_prompt(qtype);
			tmp = ft_strjoin(*cmd, "\n");
			free(*cmd);
			*cmd = tmp;
			if ((ret = get_next_line(0, &buf)) <= 0)
				return (ret);
			tmp = ft_strjoin(*cmd, buf);
			free(*cmd);
			free(buf);
			*cmd = tmp;
		}
		*i = *i + 1;
	}
	return (1);
}

int			quotes_cmd(char **cmd)
{
	int		i;
	int		ret;

	ret = 1;
	i = 0;
	while ((*cmd)[i] && ret > 0)
	{
		if ((i - 1 < 0 || (*cmd)[i - 1] != '\\') && IS_QUOTE)
			ret = sub_quotes(&i, cmd, (*cmd)[i]);
		i++;
	}
	if (ret == 0)
		return (1);
	return (ret);
}
