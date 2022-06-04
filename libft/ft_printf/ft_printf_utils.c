/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 10:00:48 by lgiband           #+#    #+#             */
/*   Updated: 2022/05/11 11:20:49 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i ++;
	}
	return (-1);
}

void	ft_setzero(int flags[5])
{
	int	i;

	i = -1;
	while (++i < 5)
		flags[i] = 0;
}

t_arg	ft_convert_flags(int flags[5], t_arg elem)
{
	elem.f_zero = flags[0];
	elem.f_space = flags[1];
	elem.f_plus = flags[2];
	elem.f_minus = flags[3];
	elem.f_hashtag = flags[4];
	return (elem);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ft_init(t_arg *elem)
{
	elem->f_zero = 0;
	elem->f_space = 0;
	elem->f_plus = 0;
	elem->f_minus = 0;
	elem->f_hashtag = 0;
	elem->min_champs = 0;
	elem->precision = 0;
	elem->precision_detected = 0;
	elem->attribut = 0;
}
