/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitas <adavitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:34:34 by adavitas          #+#    #+#             */
/*   Updated: 2025/07/16 18:35:30 by adavitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_strchr(char *str, int c);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
char	*get_next_line(int fd);

#endif
