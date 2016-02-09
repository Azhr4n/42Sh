/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpontat <jpontat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 12:07:08 by jpontat           #+#    #+#             */
/*   Updated: 2014/03/15 14:16:13 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

#include "builtins.h"
#include "sh.h"

void			b_exit(char **buffer)
{
	unsigned int	val;
	int				i;

	if (buffer[1])
	{
		i = 0;
		while (buffer[1][i])
		{
			if (!ft_isdigit(buffer[1][i]))
			{
				print_err(buffer[1], NUM_ARG_REQUIRED);
				exit(255);
			}
			i++;
		}
		val = ft_atoi(buffer[1]);
		g_exit_status = val;
	}
	ft_putendl("exit");
	exit(g_exit_status);
}
