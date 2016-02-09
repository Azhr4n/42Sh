/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_environ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpontat <jpontat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 14:24:54 by jpontat           #+#    #+#             */
/*   Updated: 2014/02/24 20:18:08 by jpontat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "sh.h"
#include "util.h"

char	**g_env;

void	catch_environ(void)
{
	extern char **environ;

	g_env = strdup_2d(environ);
	if (!g_env)
		fatal("can't catch env");
}
