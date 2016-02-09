/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpontat <jpontat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 15:18:06 by jpontat           #+#    #+#             */
/*   Updated: 2014/03/26 14:52:15 by jpontat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

typedef struct	s_built
{
	char		*cmd;
	void		(*fct)(char **);
}				t_built;

int				find_exec_builtin(char **buff, int io[2]);
void			b_env(char **buffer);
void			b_cd(char **buffer);
void			b_exit(char **buffer);
void			b_echo(char **buffer);
void			b_setenv(char **buffer);
void			b_unsetenv(char **buffer);

#endif
