/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_setenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 15:46:24 by pivanovi          #+#    #+#             */
/*   Updated: 2014/03/14 15:50:38 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "prompts.h"
#include "builtins.h"
#include "sh.h"
#include "env.h"
#include "util.h"

void		b_setenv(char **buffer)
{
	if (!buffer[1])
		ft_print_env(g_env);
	else if (buffer[3])
		print_err("setenv", TOO_MANY_ARGS);
	else
	{
		if (ft_strchr(buffer[1], '='))
		{
			print_err(buffer[1], SYNTAX_ERROR);
			return ;
		}
		g_mood = M_STUNNED;
		if (ft_setenv(buffer[1], buffer[2], 1) < 0)
			fatal("ft_setenv");
	}
}
