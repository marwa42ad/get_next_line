/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoham <marmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:39:21 by marmoham          #+#    #+#             */
/*   Updated: 2023/08/15 14:10:08 by marmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdint.h>
# define MAX_FD 1024

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *string, int searchedChar );
void	*ft_calloc(size_t Count, size_t Size);
size_t	ft_strlen(const char *str);
char	*ft_join_next(char *buffer);
char	*ft_line(char *buffer);
char	*read_file(int fd, char *result);
#endif
