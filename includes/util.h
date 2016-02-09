/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 16:34:24 by brandazz          #+#    #+#             */
/*   Updated: 2014/03/26 14:56:57 by jpontat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <libft.h>

char		*add_file_to_path(const char *path, const char *file);
char		**strdup_2d(char **str);
void		strfree_2d(char **str);
void		del_lst(void *content, size_t content_size);

int			ft_check_nb_c(char **str, char c);
int			ft_check_if_c(char *str, char c);
void		ft_print_env(char **env);

#endif
