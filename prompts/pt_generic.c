/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_generic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 20:03:49 by gmarais           #+#    #+#             */
/*   Updated: 2014/03/26 15:21:33 by jpontat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <libft.h>
#include <time.h>

#include "env.h"
#include "prompts.h"

static char	*g_color_code[] = {
	"",
	"\033[1;30m",
	"\033[1;31m",
	"\033[1;32m",
	"\033[1;33m",
	"\033[1;34m",
	"\033[1;35m",
	"\033[1;36m",
	"\033[1;37m",
	"\033[0;30m",
	"\033[0;31m",
	"\033[0;32m",
	"\033[0;33m",
	"\033[0;34m",
	"\033[0;35m",
	"\033[0;36m",
	"\033[0;37m"
};

void	puttermcolor(const int color)
{
	if (color > 0 && color <= C_WHITE)
		ft_putstr(g_color_code[color]);
}

char	*pt_get_time(int format)
{
	char	*res;
	time_t	tmp;

	tmp = time(NULL);
	res = ctime(&tmp);
	res[ft_strlen(res) - 9] = 0;
	if (format == A_TIME)
	{
		while (ft_strchr(res, ' '))
			res++;
	}
	return (res);
}

char	*pt_get_pwd(void)
{
	char		*tmp;
	char		*home;
	static char	res[256];

	tmp = ft_strnew(256);
	tmp = getcwd(tmp, 256);
	ft_strcpy(res, tmp);
	free(tmp);
	tmp = NULL;
	home = ft_getenv("HOME");
	if (home)
		tmp = ft_strstr(res, home);
	if (tmp)
	{
		tmp = tmp + ft_strlen(home) - 1;
		ft_strcpy(res, tmp);
		res[0] = '~';
	}
	return (res);
}
