/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamototakeshi <okamototakeshi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:55:50 by okamototake       #+#    #+#             */
/*   Updated: 2022/08/01 19:24:02 by okamototake      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_to_save_bonus(char *save, int fd)
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
			free(save);
			return (NULL);
		}
		buff[read_size] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

static char	*create_line_bonus(char *save)
{
	char	*line;
	size_t	l;
	size_t	i;

	l = 0;
	if (save[0] == '\0')
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

static char	*update_save_bonus(char *save)
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
		l++;
		updated_save[i] = save[l];
		i++;
	}
	updated_save[i] = '\0';
	free(save);
	return (updated_save);
}

char	*get_next_line(int fd)
{
	static char		*save[OPEN_MAX + 1];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	if (!save[fd])
	{
		save[fd] = ft_strdup("");
		if (!save[fd])
			return (NULL);
	}
	save[fd] = read_to_save_bonus(save[fd], fd);
	if (!save[fd])
		return (NULL);
	line = create_line_bonus(save[fd]);
	save[fd] = update_save_bonus(save[fd]);
	return (line);
}

// int	main(void)
// {
// 	int		index;
// 	//index:読み込み回数
// 	int		fd;
// 	char	*receiver;

// 	fd = open("XXX.txt", O_RDONLY);
// 	receiver = NULL;
// 	index = 0;
// 	while (1)
// 	{
// 		receiver = get_next_line(fd);
// 		if (!receiver)
// 		{
// 			printf("EOF or ERROR\n");
// 			break ;
// 		}
// 		printf("[%d]%s", index, receiver);
// 		index ++;
// 		free(receiver);
// 	}
// 	system("leaks a.out");
// 	close(fd);
// }
