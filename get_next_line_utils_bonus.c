/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoham <marmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:39:07 by marmoham          #+#    #+#             */
/*   Updated: 2023/08/15 11:39:36 by marmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)

{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)

{
	while (*s != (unsigned char)c)
	{
		if (*s == '\0')
		{
			return (NULL);
		}
		s++;
	}
	return ((char *)s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		sizetotal;
	char	*res;
	int		i;
	int		j;

	i = 0;
	sizetotal = ft_strlen(s1) + ft_strlen(s2);
	if (!s1)
	{
		s1 = malloc (1);
		s1[0] = '\0';
	}
	res = malloc(sizeof(char) * (sizetotal + 1));
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		res[i++] = s2[j++];
	res[sizetotal] = '\0';
	free (s1);
	return (res);
}

void	*ft_calloc(size_t count, size_t size)

{
	char	*memory;
	size_t	i;

	i = 0;
	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	memory = malloc(count * size);
	if (!memory)
		return (NULL);
	while (i < (count * size))
	{
		memory[i] = 0;
		i++;
	}
	return (memory);
}
