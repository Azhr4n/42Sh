/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:25:16 by brandazz          #+#    #+#             */
/*   Updated: 2013/12/31 12:31:23 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

static int		ft_nb_elem(char const *s, char c)
{
	int		nb_elem;

	nb_elem = 1;
	while (*s && *s == c)
	{
		s++;
	}
	while (*s)
	{
		if (*s == c)
		{
			nb_elem++;
			while (*s && *s == c)
			{
				s++;
			}
		}
		else
		{
			s++;
		}
	}
	return (nb_elem);
}

static size_t	ft_elem_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

static char		*ft_split(char const *s, char c, char **location)
{
	size_t	elem_len;

	while (*s == c && *s)
	{
		s++;
	}
	if (!*s)
		return (NULL);
	elem_len = ft_elem_len(s, c);
	if (elem_len == 0)
		elem_len = 1;
	*location = ft_strsub(s, 0, elem_len);
	return ((char *)s + elem_len);
}

static void		ft_clean(char **split, int nb_elem)
{
	while (nb_elem >= 0)
	{
		free(split[nb_elem]);
		nb_elem--;
	}
	free(split);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		nb_elem;
	size_t	size;
	char	**split;

	nb_elem = ft_nb_elem(s, c);
	size = (nb_elem + 1) * sizeof(char *);
	split = (char **)malloc(size);
	if (split == NULL)
		return (NULL);
	i = 0;
	while (i < nb_elem)
	{
		if ((s = ft_split(s, c, &split[i])) == NULL)
			break ;
		if (split[i] == NULL)
		{
			ft_clean(split, i - 1);
			return (NULL);
		}
		i++;
	}
	split[i] = 0;
	return (split);
}
