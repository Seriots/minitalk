/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:32:06 by lgiband           #+#    #+#             */
/*   Updated: 2022/05/04 12:47:13 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*result;
	size_t	i;

	i = -1;
	if (!s)
		size = 0;
	else if (start >= ft_strlen(s))
		size = 0;
	else
		size = ft_strlen(s) - start;
	if (size > len)
		size = len;
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (0);
	result[size] = 0;
	while (++i < size)
		result[i] = *(s + i + start);
	return (result);
}
