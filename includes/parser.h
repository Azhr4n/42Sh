/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 17:36:44 by brandazz          #+#    #+#             */
/*   Updated: 2014/03/26 15:09:25 by jpontat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <libft.h>

# define ARG_MAX 4096

# define FALSE 0
# define TRUE !FALSE

# define ESCAPED_QUOTE (!l.qbool && *(str - 1) == '\\')
# define ND_QUOTE (!l.qtype || *str != '\\' || *(str + 1) != l.qtype)

enum				e_type
{
	T_ANYTHING,
	T_WHITESPACE,
	T_SEMICOL,
	T_PIPE,
	T_AMPERSAND,
	T_INFERIOR,
	T_SUPERIOR,
	T_DQUOTE,
	T_SQUOTE,
	T_BQUOTE
};

typedef struct		s_token
{
	char			str[ARG_MAX];
	int				type;
}					t_token;

typedef struct		s_type
{
	char			*charset;
	int				type;
}					t_type;

typedef struct		s_lexer
{
	t_list			*lst;
	t_token			token;
	char			qtype;
	int				i;
	int				qbool;
	int				next_type;
}					t_lexer;

enum				e_ast_type
{
	N_CMD,
	N_SEPARATOR,
	N_PIPE,
	N_OR,
	N_AND
};

typedef struct		s_ast
{
	char			*str[ARG_MAX];
	char			*redir[ARG_MAX];
	int				type;
	struct s_ast	*left;
	struct s_ast	*right;
}					t_ast;

typedef struct		s_parser
{
	t_ast			*tree;
	t_list			*traverse;
	t_ast			*prev_prev_node;
	t_ast			*prev_node;
	t_ast			*node;
	int				fd[2];
	int				io[2];
}					t_parser;

typedef struct		s_redir
{
	char			*str;
	int				io_index;
	int				(*fct)(const char *);
}					t_redir;

extern int			g_syntax_err;

t_list				*lexer(const char *str);
void				parser(t_list *tokens);
int					quotes_cmd(char **cmd);
t_ast				*create_node(void);
int					read_exp(t_ast **tree, t_list **tokens);
int					read_separator(t_ast **tree, t_list **tokens);
int					read_command(t_ast **tree, t_list **tokens);
int					read_pipe(t_ast **tree, t_list **tokens);
int					read_or(t_ast **tree, t_list **tokens);
int					read_and(t_ast **tree, t_list **tokens);
int					syntax_error(const char *token, t_ast *tree, t_ast *node);
int					count_char(const char *str, char c);
void				reset_io(int io[2]);
void				make_pipe(t_parser *p);
int					redir_output(const char *file);
int					redir_output_append(const char *file);
int					redir_input(const char *file);
void				make_redir(t_parser *p);
void				interpreter(t_parser *p);

#endif
