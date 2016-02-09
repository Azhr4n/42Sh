/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpontat <jpontat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 14:20:59 by jpontat           #+#    #+#             */
/*   Updated: 2014/03/26 14:52:35 by jpontat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

extern char	**g_env;

void		catch_environ(void);
int			ft_unsetenv(const char *name);
char		*ft_getenv(const char *name);
int			ft_setenv(const char *name, const char *value, int overwrite);

#endif
