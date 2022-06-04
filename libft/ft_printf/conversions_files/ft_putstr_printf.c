/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:43:35 by lgiband           #+#    #+#             */
/*   Updated: 2022/05/11 11:17:37 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "conversions.h"
#include <unistd.h>

int	ft_check_putstr(t_arg elem, char *s)
{
	elem.min_champs -= ft_check_flags_putstr(elem, s, 0);
	return (ft_check_flags_putstr(elem, s, 1));
}

int	ft_check_flags_putstr(t_arg elem, char *s, int print)
{
	int	i;

	i = 0;
	if (elem.f_minus == 0)
	{
		if (print)
			i += ft_print_minchamps(elem);
		i += ft_putstr(s, elem, print);
	}
	else
	{
		i += ft_putstr(s, elem, print);
		if (print)
			i += ft_print_minchamps(elem);
	}
	return (i);
}

int	ft_putstr(const char *s, t_arg elem, int print)
{
	int	i;

	i = -1;
	if (s == 0)
	{
		if ((print && elem.precision >= 6) || (print && elem.precision == 0))
			write(1, "(null)", 6);
		if (elem.precision >= 6 || elem.precision == 0)
			return (6);
		else
			return (0);
	}
	if (elem.precision_detected != 0)
	{
		while (s[++i] && i < elem.precision)
			if (print)
				write(1, &s[i], 1);
	}
	else
	{
		while (s[++i])
			if (print)
				write(1, &s[i], 1);
	}
	return (i);
}
