/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:30:54 by lgiband           #+#    #+#             */
/*   Updated: 2022/05/03 11:53:36 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	while (*(s + i))
	{
		if ((*(s + i) == (char)c))
		{
			ptr = (char *)s + i;
			return (ptr);
		}
		i ++;
	}
	if (*(s + i) == (char)c)
	{
		ptr = (char *)s + i;
		return (ptr);
	}
	return (0);
}
