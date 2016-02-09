/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xcall.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 15:40:31 by brandazz          #+#    #+#             */
/*   Updated: 2014/03/14 15:40:48 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "sh.h"

int		xclose(int fildes)
{
	int		ret;

	ret = close(fildes);
	if (ret < 0)
		failed("close failed");
	return (ret);
}

int		xdup(int fildes)
{
	int		fildes2;

	fildes2 = dup(fildes);
	if (fildes < 0)
		failed("dup failed");
	return (fildes2);
}

int		xdup2(int fildes, int fildes2)
{
	int		ret;

	ret = dup2(fildes, fildes2);
	if (ret < 0)
		failed("dup2 failed");
	return (ret);
}
