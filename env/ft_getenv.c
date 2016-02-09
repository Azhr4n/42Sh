/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpontat <jpontat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 15:04:36 by jpontat           #+#    #+#             */
/*   Updated: 2014/02/24 17:46:50 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "env.h"

char		*ft_getenv(const char *name)
{
	int		i;
	size_t	len;

	len = ft_strlen(name);
	i = 0;
	while (g_env[i])
	{
		if (ft_strncmp(g_env[i], name, len) == 0 && g_env[i][len] == '=')
			return (&(g_env[i][len + 1]));
		i++;
	}
	return (NULL);
}
