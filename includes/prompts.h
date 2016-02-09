/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompts.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 20:05:11 by gmarais           #+#    #+#             */
/*   Updated: 2014/03/26 14:55:44 by jpontat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPTS_H
# define PROMPTS_H

# define NOT_END_QUOTE (!bol && (bol = 1)) || (*cmd)[*i - 1] == '\\'
# define IS_QUOTE ((*cmd)[i] == '"' || (*cmd)[i] == '\'' || (*cmd)[i] == '`')

enum	e_moods
{
	M_NORMAL,
	M_HAPPY,
	M_CRYING,
	M_DEAD,
	M_BORED,
	M_ANGRY,
	M_STUNNED,
	M_ASLEEP,
	M_CONFUSED,
	M_HIGH,
	M_MUTED
};

enum	e_term_colors
{
	C_NONE,
	C_BOLD_BLACK,
	C_BOLD_RED,
	C_BOLD_GREEN,
	C_BOLD_YELLOW,
	C_BOLD_BLUE,
	C_BOLD_PURPLE,
	C_BOLD_CYAN,
	C_BOLD_WHITE,
	C_BLACK,
	C_RED,
	C_GREEN,
	C_YELLOW,
	C_BLUE,
	C_PURPLE,
	C_CYAN,
	C_WHITE
};

enum	e_arg_type
{
	A_PWD,
	A_USER,
	A_LOGIN,
	A_GROUP,
	A_LTIME,
	A_TIME
};

void	putprompt(int mood, int color, int with_arg);
void	puttermcolor(const int color);
char	*pt_get_time(int format);
char	*pt_get_pwd(void);
int		pt_fix_color(int mood, int prevcolor);

#endif
