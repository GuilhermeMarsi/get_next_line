/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarsi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:21:25 by gmarsi            #+#    #+#             */
/*   Updated: 2020/02/18 21:26:48 by gmarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
char	*ft_prepare_next(char *str);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);

#endif
