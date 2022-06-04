/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:26:02 by lgiband           #+#    #+#             */
/*   Updated: 2022/05/06 16:59:47 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	if (size != 0 && size * nmemb / size != nmemb)
		return (0);
	result = malloc(size * nmemb);
	if (!result)
		return (0);
	ft_bzero(result, size * nmemb);
	return (result);
}
