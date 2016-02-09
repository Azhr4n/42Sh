/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_echo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpontat <jpontat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 09:14:12 by jpontat           #+#    #+#             */
/*   Updated: 2014/03/14 11:15:03 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>

#include "builtins.h"

void		b_echo(char **buffer)
{
	int	i;
	int	ret;

	i = 1;
	if (buffer[1] == 0)
	{
		write(1, "\n", 1);
		return ;
	}
	if ((ret = ft_strcmp(buffer[1], "-n")) == 0)
		i++;
	while (buffer[i])
	{
		write(1, buffer[i], ft_strlen(buffer[i]));
		i++;
		if (i > 1 && buffer[i] != 0)
			write(1, " ", 1);
	}
	if (ret != 0)
		write(1, "\n", 1);
}
