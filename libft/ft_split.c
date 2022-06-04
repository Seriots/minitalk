/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:30:51 by lgiband           #+#    #+#             */
/*   Updated: 2022/05/04 12:29:43 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_letters(char const *s, char c, int *position)
{
	int	i;
	int	count;

	i = *position;
	count = 0;
	while (s[i] && s[i] == c)
	{
		i++;
		*position += 1;
	}
	while (s[i] && s[i] != c)
	{
		i++;
		count ++;
	}
	return (count);
}

static char	*ft_put_word(char const *s, char c, int *position)
{
	int		nb_letters;
	char	*result;
	int		i;

	i = 0;
	nb_letters = ft_count_letters(s, c, position);
	result = (char *)malloc(sizeof(char) * (nb_letters + 1));
	if (!result)
		return (0);
	result[nb_letters] = 0;
	while (i < nb_letters)
	{
		result[i] = s[(*position)];
		i++;
		*position += 1;
	}
	return (result);
}

static int	ft_count_word(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			count ++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		nb_word;
	int		i;
	char	**result;
	int		pos[1];

	if (!s)
		return (0);
	i = 0;
	pos[0] = 0;
	nb_word = ft_count_word(s, c);
	result = (char **)malloc(sizeof(char *) * (nb_word + 1));
	if (!result)
		return (0);
	result[nb_word] = 0;
	while (i < nb_word)
	{
		result[i] = ft_put_word(s, c, pos);
		i++;
	}
	return (result);
}
