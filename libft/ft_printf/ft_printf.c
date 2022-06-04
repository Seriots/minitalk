/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:28:02 by lgiband           #+#    #+#             */
/*   Updated: 2022/05/11 10:40:26 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;

	if (!s)
		return (0);
	va_start(ap, s);
	i = ft_printfwork(ap, s);
	va_end(ap);
	return (i);
}
