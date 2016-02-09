/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 17:30:51 by brandazz          #+#    #+#             */
/*   Updated: 2014/03/26 14:56:15 by jpontat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# define PROG_NAME "42sh"

# define PERM_DENIED_EXIT_STATUS 126
# define NOT_FOUND_EXIT_STATUS 127

enum		e_error
{
	ARG_LIST_TOO_LONG,
	CMD_NOT_FOUND,
	NO_SUCH_FILE_OR_DIR,
	PERMISSION_DENIED,
	NO_OLDPWD,
	ILLEGAL_OPTION,
	NUM_ARG_REQUIRED,
	TOO_MANY_ARGS,
	SYNTAX_ERROR,
	TOO_FEW_ARGS
};

extern int	g_exit_status;
extern int	g_interrupted;
extern int	g_mood;

int			xclose(int fildes);
int			xdup(int fildes);
int			xdup2(int fildes, int fildes2);
void		failed(const char *err);
void		print_err(const char *cause, const int err);
void		fatal(const char *err);
char		*find_cmd(char **cmd);
void		exec_cmd(char *path, char **arg, int io[2], char **env);
int			find_exec_cmd(char **arg, int io[2], char **env);
void		wait_children(void);

#endif
