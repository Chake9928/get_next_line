/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamototakeshi <okamototakeshi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:52:29 by okamototake       #+#    #+#             */
/*   Updated: 2022/07/27 00:18:46 by okamototake      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

static char	*read_to_save(char *save, int fd)
{
	char	*buff;
	int		read_size;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	read_size = 1;
	while (ft_strchr(save, '\n') == NULL && read_size != 0)
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_size] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

static char	*create_line(char *save)
{
	char	*line;
	size_t	l;
	size_t	i;

	l = 0;
	if (!save)
		return (NULL);
	while (save[l] != '\n' && save[l] != '\0')
		l++;
	if (save[l] == '\n')
		l++;
	line = (char *)malloc(sizeof(char) * l + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < l)
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*update_save(char *save)
{
	char	*updated_save;
	size_t	i;
	size_t	l;

	l = 0;
	while (save[l] != '\n' && save[l] != '\0')
		l++;
	if (ft_strlen(save) == l)
	{
		free(save);
		return (NULL);
	}
	updated_save = (char *)malloc((ft_strlen(save) - l + 1) * sizeof(char));
	if (updated_save == NULL)
		return (NULL);
	i = 0;
	while (save[l])
	{
		updated_save[i] = save[l];
		i++;
		l++;
	}
	updated_save[i] = '\0';
	free(save);
	return (updated_save);
}

char	*get_next_line(int fd)
{
	static char		*save;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!save)
	{
		save = ft_strdup("");
		if (!save)
			return (NULL);
	}
	save = read_to_save(save, fd);
	if (!save)
		return (NULL);
	line = create_line(save);
	save = update_save(save);
	return (line);
}
