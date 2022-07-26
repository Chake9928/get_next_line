/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okamototakeshi <okamototakeshi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:52:22 by okamototake       #+#    #+#             */
/*   Updated: 2022/07/26 17:14:44 by okamototake      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>

char			*get_next_line(int fd);
char			*ft_strdup(const char *s);
char			*ft_strchr(const char *str, int c);
char			*ft_strjoin(char const *s1, char const *s2);
static char		*ft_join_array(char const *s1, char const *s2, char *ptr);
size_t			ft_strlen(const char *str);

#endif