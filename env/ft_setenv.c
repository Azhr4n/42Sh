/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpontat <jpontat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 19:48:52 by jpontat           #+#    #+#             */
/*   Updated: 2014/03/10 15:48:35 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

#include "env.h"
#include "parser.h"

static int	realloc_env(void)
{
	int		i;
	char	**new_env;

	i = 0;
	while (g_env[i])
		i++;
	new_env = (char **)malloc(sizeof(char *) * (i + 2));
	if (!new_env)
		return (-1);
	ft_bzero(new_env, sizeof(char *) * (i + 2));
	i = 0;
	while (g_env[i])
	{
		new_env[i] = g_env[i];
		i++;
	}
	free(g_env);
	g_env = new_env;
	return (i);
}

static int	ft_setenv_sub(const char *name, const char *value)
{
	int		size;
	char	*tmp;
	char	*var;

	size = realloc_env();
	if (size < 0)
		return (-1);
	tmp = ft_strjoin(name, "=");
	if (value)
		var = ft_strjoin(tmp, value);
	else
		var = ft_strdup(tmp);
	free(tmp);
	g_env[size] = var;
	return (0);
}

int			ft_setenv(const char *name, const char *value, int overwrite)
{
	int		i;
	int		n;
	char	*tmp;

	i = 0;
	n = ft_strlen(name);
	while (g_env[i] && !(!strncmp(g_env[i], name, n) && g_env[i][n] == '='))
		i++;
	if (g_env[i])
	{
		if (!overwrite)
			return (0);
		tmp = ft_strjoin(name, "=");
		free(g_env[i]);
		if (value)
		{
			g_env[i] = ft_strjoin(tmp, value);
			free(tmp);
		}
		else
			g_env[i] = tmp;
		return (0);
	}
	return (ft_setenv_sub(name, value));
}
