/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 23:07:31 by lgiband           #+#    #+#             */
/*   Updated: 2022/05/03 11:56:14 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	s1_size;
	size_t	s2_size;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	result = malloc(sizeof(char) * (s1_size + s2_size + 1));
	if (!result)
		return (0);
	result[s1_size + s2_size] = 0;
	while (s1[++i])
		result[i] = *(s1 + i);
	while (s2[++j])
		result[i + j] = *(s2 + j);
	return (result);
}
