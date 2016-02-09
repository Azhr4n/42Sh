/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 16:34:43 by brandazz          #+#    #+#             */
/*   Updated: 2014/03/10 13:36:04 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "sh.h"
#include "util.h"

char		*add_file_to_path(const char *path, const char *file)
{
	char	*str;

	str = ft_strnew(ft_strlen(path) + 1 + ft_strlen(file));
	if (!str)
		fatal("ft_strnew");
	ft_strcpy(str, path);
	ft_strcat(str, "/");
	ft_strcat(str, file);
	return (str);
}

char		**strdup_2d(char **str)
{
	char	**ptr;
	size_t	n;
	int		i;

	i = 0;
	n = 0;
	while (str[n])
		n++;
	ptr = (char **)malloc(sizeof(char *) * (n + 1));
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, sizeof(char *) * (n + 1));
	while (str[i])
	{
		n = ft_strlen(str[i]) + 1;
		ptr[i] = (char *)malloc(sizeof(char) * n);
		if (!ptr[i])
			return (NULL);
		ft_bzero(ptr[i], n);
		ft_strcpy(ptr[i], str[i]);
		i++;
	}
	return (ptr);
}

void		strfree_2d(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void		del_lst(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}
