/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointeur2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:07:50 by lgiband           #+#    #+#             */
/*   Updated: 2022/05/11 11:17:56 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "conversions.h"

int	ft_check_putpointeur(t_arg elem, void *ptr)
{
	int	i;

	i = ft_check_flags_putpointeur(elem, ptr, 0);
	elem.precision -= i;
	if (elem.precision > 0)
	{	
		if (ptr != 0)
			elem.min_champs -= i + elem.precision + 2;
		else
			elem.min_champs -= i + elem.precision;
	}
	else
	{
		if (ptr != 0)
			elem.min_champs -= i + 2;
		else
			elem.min_champs -= i;
	}
	return (ft_check_flags_putpointeur(elem, ptr, 1));
}
