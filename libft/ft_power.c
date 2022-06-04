/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:44:00 by lgiband           #+#    #+#             */
/*   Updated: 2022/05/16 12:41:22 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power > 0)
		return (nb * ft_power(nb, power - 1));
	else
		return (1);
}

/*#include <stdio.h>
int main()
{
	int test = ft_recursive_power(9, 8);
	printf("%d", test);
	return (0);
}*/
