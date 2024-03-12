/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoham <marmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:18:24 by marmoham          #+#    #+#             */
/*   Updated: 2023/08/17 20:44:36 by marmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*buffer;
	char		*read_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	read_line = ft_line(buffer);
	buffer = ft_join_next(buffer);
	return (read_line);
}
/*int main()
{
     int fd1 = open("Marwa.txt", O_RDONLY);
	// static char *buffer;
	// char *res =read_file(fd1,buffer);
	// printf("%s",res);
	char *line;
    while ((line = get_next_line(fd1)) != NULL)
    {
        printf("Line: %s", line);
        free(line);
    }
	 close(fd1);
     return 0;
}*/
