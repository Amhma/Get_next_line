/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:55:24 by amahla            #+#    #+#             */
/*   Updated: 2022/05/07 17:56:05 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_str_to_save(char *save)
{
	int		i;
	int		j;
	char	*temp;

	j = 0;
	i = 0;
	while (*(save + i) && *(save + i) != '\n')
		i++;
	if (*(save + i) == '\n')
		i++;
	temp = calloc_gnl(ft_strlen_gnl(save + i) + 1, sizeof(char));
	if (!temp)
		return (NULL);
	while (*(save + i))
		*(temp + j++) = *(save + i++);
	free(save);
	if (!ft_strlen_gnl(temp))
	{
		free(temp);
		temp = NULL;
	}
	return (temp);
}

char	*ft_str_to_print(char *save)
{
	int		i;
	int		j;
	int		size;
	char	*line;

	i = 0;
	j = 0;
	size = 0;
	while (*(save + size) && *(save + size) != '\n')
		size++;
	if (*(save + size) == '\n')
		size++;
	line = calloc_gnl(size + 1, sizeof(char));
	if (!line)
		return (NULL);
	while (*(save + i) && *(save + i) != '\n')
		*(line + j++) = *(save + i++);
	if (*(save + i) == '\n')
		*(line + j) = *(save + i);
	if (!ft_strlen_gnl(line))
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*ft_str_temp(char *save, int fd)
{
	int		rd;
	char	*buffer;

	rd = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (buffer && rd > 0 && !ft_strchr_nl(save))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[rd] = '\0';
		save = ft_strjoin_gnl(save, buffer);
	}
	if (buffer)
		free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char		*save;
	char			*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_str_temp(save, fd);
	if (!save)
		return (NULL);
	line = ft_str_to_print(save);
	save = ft_str_to_save(save);
	return (line);
}
