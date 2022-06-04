/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:31:53 by lgiband           #+#    #+#             */
/*   Updated: 2022/05/03 12:01:54 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	ptr = 0;
	i = 0;
	while (*(s + i))
	{
		if ((*(s + i) == (char)c))
		{
			ptr = (char *)s + i;
		}
		i ++;
	}
	if (*(s + i) == (char)c)
		ptr = (char *)s + i;
	return (ptr);
}
