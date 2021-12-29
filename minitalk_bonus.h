/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriyas <rriyas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:12:38 by rriyas            #+#    #+#             */
/*   Updated: 2021/12/27 20:56:35 by rriyas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include	<unistd.h>
# include	<signal.h>
# include	<stdarg.h>

int		ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr_base(long long nbr, char *base);
int		ft_atoi(const char *nptr);

#endif
