/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:29:41 by lgiband           #+#    #+#             */
/*   Updated: 2022/05/04 08:38:03 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countchar(int n)
{
	int	count;

	count = 1;
	while (n > 9 || n < -9)
	{
		count ++;
		n = n / 10;
	}
	return (count);
}

static int	ft_abs(int n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}

static void	ft_calcul(int n, int i, char *result)
{
	while (n > 9 || n < -9)
	{
		result[i] = (char)((ft_abs(n % 10)) + 48);
		n = n / 10;
		i --;
	}
	result[i] = (char)(ft_abs(n) + 48);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		count;
	int		i;

	count = ft_countchar(n);
	if (n < 0)
		count ++;
	i = count - 1;
	result = (char *)malloc(sizeof(char) * (count + 1));
	if (!result)
		return (0);
	result[count] = 0;
	if (n < 0)
		result[0] = '-';
	if (n == -2147483648)
	{
		result[i--] = '8';
		n = n / 10;
	}
	ft_calcul(n, i, result);
	return (result);
}
