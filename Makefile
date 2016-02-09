# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/18 17:24:17 by brandazz          #+#    #+#              #
#    Updated: 2014/03/26 18:05:08 by brandazz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = 42sh

SRC = main.c					\
	  parser/lexer.c			\
	  parser/parser.c			\
	  parser/create_node.c		\
	  parser/read_exp.c			\
	  parser/read_command.c		\
	  parser/read_separator.c	\
	  parser/read_pipe.c		\
	  parser/read_or.c			\
	  parser/read_and.c			\
	  parser/syntax_error.c		\
	  parser/count_char.c		\
	  parser/interpreter.c		\
	  parser/make_pipe.c		\
	  parser/make_redir.c		\
	  parser/quotes.c			\
	  env/catch_environ.c		\
	  env/ft_getenv.c			\
	  env/ft_setenv.c			\
	  env/ft_unsetenv.c			\
	  prompts/prompts.c			\
	  prompts/pt_generic.c		\
	  builtins/builtins.c		\
	  builtins/b_env.c			\
	  builtins/b_cd.c			\
	  builtins/b_exit.c			\
	  builtins/b_echo.c			\
	  builtins/b_setenv.c		\
	  builtins/b_unsetenv.c		\
	  find_cmd.c				\
	  exec_cmd.c				\
	  sig.c						\
	  util2.c					\
	  util.c					\
	  xcall.c					\
	  fatal.c

OBJ = $(SRC:.c=.o)

CFLAGS += -I./includes

LIB = libft

CFLAGS += -I./libft/includes
LDFLAGS += -L./libft -lft

all: $(NAME)

$(NAME): $(LIB)/$(LIB:=.a) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LDFLAGS)

$(LIB): $(LIB)/$(LIB:=.a)

$(LIB)/$(LIB:=.a):
	$(MAKE) -C $(LIB)

clean:
	$(MAKE) clean -C $(LIB)
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(LIB)/$(LIB:=.a)
	/bin/rm -f $(NAME)

re: fclean all
