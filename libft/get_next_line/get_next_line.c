/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:46:23 by lgiband           #+#    #+#             */
/*   Updated: 2022/05/31 14:00:41 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

char	*ft_cut_last_read(char *prev_read)
{
	int		i;
	int		j;
	int		size;
	char	*next_line;

	i = 0;
	while (prev_read[i] != '\n' && prev_read[i])
		i++;
	if (prev_read[i] == '\n')
		i++;
	if (prev_read[i] == 0)
	{
		free(prev_read);
		return (0);
	}
	size = ft_strlen(prev_read + i);
	next_line = malloc(sizeof(char) * (size + 1));
	if (!next_line)
		return (0);
	next_line[size] = 0;
	j = -1;
	while (++j < size)
		next_line[j] = prev_read[i + j];
	free(prev_read);
	return (next_line);
}

char	*ft_get_line(char *prev_read)
{
	char	*line;
	int		i;

	i = 0;
	while (prev_read[i] != '\n' && prev_read[i])
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (0);
	line[i] = 0;
	i = -1;
	while (prev_read[++i] != '\n' && prev_read[i])
		line[i] = prev_read[i];
	return (line);
}

char	*ft_read(int fd, char *prev_read)
{
	char	*buf_tampon;
	int		readed;

	buf_tampon = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf_tampon)
	{
		free(prev_read);
		return (0);
	}
	readed = 1;
	while (!(ft_strchr(prev_read, '\n')) && readed != 0)
	{
		readed = read(fd, buf_tampon, BUFFER_SIZE);
		if (readed == -1)
		{
			free(prev_read);
			free(buf_tampon);
			return (0);
		}
		buf_tampon[readed] = 0;
		prev_read = ft_strjoin_gnl(prev_read, buf_tampon);
	}
	free(buf_tampon);
	return (prev_read);
}

char	*ft_copy(char *src)
{
	int		size;
	int		i;
	char	*dest;

	i = 0;
	if (!src)
		return (0);
	size = ft_strlen(src);
	dest = malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (0);
	dest[size] = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i ++;
	}
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	save[1024][BUFFER_SIZE + 1];
	char		*prev_read;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1023)
		return (0);
	prev_read = ft_copy(save[fd]);
	prev_read = ft_read(fd, prev_read);
	if (prev_read == 0)
		return (0);
	result = ft_get_line(prev_read);
	if (result && result[0] == 0)
	{
		free(prev_read);
		free(result);
		return (0);
	}
	prev_read = ft_cut_last_read(prev_read);
	ft_copy2(save[fd], prev_read);
	free(prev_read);
	return (result);
}
