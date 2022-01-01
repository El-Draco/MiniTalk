/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriyas <rriyas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:38:44 by rriyas            #+#    #+#             */
/*   Updated: 2021/12/29 12:21:53 by rriyas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int id, struct __siginfo *st, void *v)
{
	static unsigned char	ch;
	static int				bit;

	v = NULL;
	if (bit < 8)
	{
		if (id == SIGUSR1)
			ch = (1 << bit) | ch;
		bit++;
	}
	if (bit == 8)
	{
		write(1, &ch, 1);
		ch = 0;
		bit = 0;
	}
	kill(st->si_pid, SIGUSR1);
}

int	initiate_server(int argc)
{
	int	pid;

	if (argc != 1)
	{
		ft_putstr("Server initation does not require any extra arguments.\n");
		ft_putstr("Format: ./server");
		return (-1);
	}
	pid = getpid();
	ft_putstr("\n**Minitalk Server**\n");
	ft_putstr("\nServer is now fully functional.\n");
	ft_putstr("You may start the client and send data!\nServer Process ID:\n");
	ft_putnbr_base(pid, "0123456789");
	return (0);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (initiate_server(argc) != 0)
		return (0);
	(void) argv;
	ft_putstr("\n");
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &signal_handler;
	sa.sa_mask = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
