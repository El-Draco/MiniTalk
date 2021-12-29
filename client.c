/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriyas <rriyas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:38:49 by rriyas            #+#    #+#             */
/*   Updated: 2021/12/29 12:10:04 by rriyas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_to_server(unsigned char c, int s_id)
{
	int				i;
	unsigned char	bit;

	i = -1;
	while (++i < 8)
	{
		bit = c & 1;
		if (bit == 1)
			kill(s_id, SIGUSR1);
		else
			kill(s_id, SIGUSR2);
		c = c >> 1;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	char	*str;
	int		s_id;
	int		i;

	if (argc != 3 || !argv[2])
	{
		ft_putstr("Invalid Client initiation format.\n");
		ft_putstr("Format: ./client Process_ID Data_To_Send\n");
		return (-1);
	}
	s_id = ft_atoi(argv[1]);
	if (s_id <= 0)
	{
		ft_putstr("Invalid Process ID :(");
		return (0);
	}
	str = argv[2];
	i = -1;
	while (str[++i])
		send_to_server(str[i], s_id);
	return (0);
}
