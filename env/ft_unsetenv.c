/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpontat <jpontat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 15:03:14 by jpontat           #+#    #+#             */
/*   Updated: 2014/02/26 14:31:53 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

#include "env.h"

int			ft_unsetenv(const char *name)
{
	int		i;
	size_t	n;

	n = ft_strlen(name);
	i = 0;
	while (g_env[i])
	{
		if (ft_strncmp(g_env[i], name, n) == 0 && g_env[i][n] == '=')
			break ;
		i++;
	}
	if (!g_env[i])
		return (-1);
	free(g_env[i]);
	while (g_env[i])
	{
		g_env[i] = g_env[i + 1];
		i++;
	}
	return (0);
}
