/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 17:40:05 by pivanovi          #+#    #+#             */
/*   Updated: 2014/03/14 10:57:26 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int			ft_check_nb_c(char **str, char c)
{
	int		nb;
	int		i;
	int		j;

	nb = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] && str[i][j] != c)
			j++;
		if (str[i][j] == c)
			nb++;
		i++;
	}
	return (nb);
}

int			ft_check_if_c(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void		ft_print_env(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		ft_putendl(env[i]);
		i++;
	}
}
