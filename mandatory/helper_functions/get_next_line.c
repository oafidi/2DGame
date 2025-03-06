/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oafidi <oafidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 21:48:08 by oafidi            #+#    #+#             */
/*   Updated: 2025/03/05 02:51:11 by oafidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*ft_read(int fd, char *buffer, char *storage)
{
	int		bytes_read;
	char	*new_storage;

	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(storage), NULL);
		if (bytes_read == 0)
			return (storage);
		buffer[bytes_read] = '\0';
		new_storage = ft_strjoin(storage, buffer);
		free(storage);
		if (!new_storage)
			return (NULL);
		storage = new_storage;
		if (ft_strchr(storage, '\n'))
			break ;
	}
	return (storage);
}

static char	*ft_get_line(char *storage)
{
	char	*line;
	int		i;

	if (!storage)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	line = ft_substr(storage, 0, i + 1);
	return (line);
}

static char	*ft_update_storage(char *storage)
{
	char	*new_storage;
	int		i;

	if (!storage)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	new_storage = ft_strdup(storage + i);
	free(storage);
	if (!new_storage || new_storage[0] == '\0')
		return (free(new_storage), NULL);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;
	char		*buffer;

	if (fd < 0 || fd > 10240 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	buffer = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	storage = ft_read(fd, buffer, storage);
	free(buffer);
	buffer = NULL;
	if (!storage)
		return (NULL);
	line = ft_get_line(storage);
	storage = ft_update_storage(storage);
	return (line);
}
