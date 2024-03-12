/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoham <marmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:39:15 by marmoham          #+#    #+#             */
/*   Updated: 2023/08/17 20:48:46 by marmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_join_next(char *buffer)
{
	int		i;
	int		j;
	char	*rest_text;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	rest_text = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		rest_text[j++] = buffer[i++];
	free(buffer);
	return (rest_text);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_file(int fd, char *result)
{
	char	*buffer;
	int		byte_read;

	if (!result)
		result = ft_calloc(1, 1);
	buffer = malloc((long)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	byte_read = 1;
	while (byte_read != 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free (result);
			free (buffer);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		result = ft_strjoin(result, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*read_line;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_calloc(1, 1);
	buffer[fd] = read_file(fd, buffer[fd]);
	if (!buffer[fd] || buffer[fd][0] == '\0')
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	read_line = ft_line(buffer[fd]);
	buffer[fd] = ft_join_next(buffer[fd]);
	return (read_line);
}
int main()
{
	int fd1 = open("Marwa.txt", O_RDONLY);
	int fd2 = open("Test2.txt", O_RDONLY);
	int fd3 = open("Test3.txt", O_RDONLY);
	char *line;
	 line = get_next_line(fd1);
    while (line )
    {
		printf("Line : %s", line);
        free(line);
		line = get_next_line(fd2);
		printf("Line : %s", line);
		free(line);
		line = get_next_line(fd3);
		printf("Line : %s", line);
		free(line);
        line = get_next_line(fd1);
    }
	close(fd1);
	close(fd2);
	close(fd3);
    return 0;
}
