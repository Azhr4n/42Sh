/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 12:39:29 by brandazz          #+#    #+#             */
/*   Updated: 2014/03/14 11:18:01 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <libft.h>

#include "sig.h"
#include "prompts.h"
#include "sh.h"

static char		*g_siglist[] = {
	"Bogus signal",
	"Hangup",
	"Interrupt",
	"Quit",
	"Illegal instruction",
	"BPT trace/trap",
	"ABORT instruction",
	"EMT instruction",
	"Floating point exception",
	"Killed",
	"Bus error",
	"Segmentation fault",
	"Bad system call",
	"Broken pipe",
	"Alarm clock",
	"Terminated",
	"Urgent IO condition",
	"Stopped (signal)",
	"Stopped",
	"Continue",
	"Child death or stop",
	"Stopped (tty input)",
	"Stopped (tty output)",
	"I/O ready",
	"CPU limit",
	"File limit",
	"Alarm (virtual)",
	"Alarm (profile)",
	"Window changed",
	"Information request",
	"User signal 1",
	"User signal 2",
	NULL
};

void			print_signal(int signum)
{
	if (signum >= 1 && signum <= 31)
	{
		ft_putstr_fd(g_siglist[signum], 2);
		ft_putstr_fd(": ", 2);
		ft_putnbr_fd(signum, 2);
		ft_putchar_fd('\n', 2);
	}
}

static void		sig_handler(int signum)
{
	(void)signum;
	g_interrupted = 1;
}

void			init_sig(void)
{
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(struct sigaction));
	sa.sa_handler = sig_handler;
	if (sigaction(SIGINT, &sa, 0) < 0)
		fatal("sigaction");
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		fatal("signal");
	if (sigaction(SIGTSTP, &sa, 0) < 0)
		fatal("sigaction");
}
