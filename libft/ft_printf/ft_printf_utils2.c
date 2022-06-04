/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:34:55 by lgiband           #+#    #+#             */
/*   Updated: 2022/05/11 10:42:59 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_print_minchamps(t_arg elem)
{
	int	i;

	i = 0;
	while (i < elem.min_champs)
	{
		if (elem.f_zero == 1 && elem.f_minus == 0 && elem.attribut != 'c'
			&& elem.attribut != 's' && elem.precision_detected == 0)
			write(1, "0", 1);
		else
			write (1, " ", 1);
		i ++;
	}
	return (i);
}

int	ft_print_precision(t_arg elem)
{
	int	i;

	i = 0;
	while (i < elem.precision)
	{
		write(1, "0", 1);
		i++;
	}
	return (i);
}
