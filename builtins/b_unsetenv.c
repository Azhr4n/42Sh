/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_unsetenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 16:07:31 by pivanovi          #+#    #+#             */
/*   Updated: 2014/03/14 15:48:57 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompts.h"
#include "builtins.h"
#include "env.h"
#include "sh.h"

void		b_unsetenv(char **buffer)
{
	int		i;

	if (buffer[1])
	{
		i = 1;
		while (buffer[i])
		{
			ft_unsetenv(buffer[i]);
			i++;
		}
		g_mood = M_CRYING;
	}
	else
		print_err("unsetenv", TOO_FEW_ARGS);
}
