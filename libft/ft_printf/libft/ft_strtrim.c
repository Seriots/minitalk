/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:31:58 by lgiband           #+#    #+#             */
/*   Updated: 2022/05/03 12:08:01 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ischarset(char c, char const *set)
{
	int	i;

	i = 0;
	while (*(set + i))
	{
		if (*(set + i) == c)
			return (1);
		i ++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	first;
	unsigned int	last;

	first = 0;
	last = ft_strlen(s1);
	if (s1 == NULL)
		return (0);
	else if (set == 0)
		return ((char *)s1);
	while (ft_ischarset(*(s1 + first), set) && s1[first])
		first ++;
	while (ft_ischarset(*(s1 + last - 1), set) && last > first)
		last --;
	return (ft_substr(s1, first, last - first));
}
