/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarsi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:20:16 by gmarsi            #+#    #+#             */
/*   Updated: 2020/02/20 22:11:30 by gmarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *str)
{
	int		i;
	char	*linha;

	i = 0;
	if (!(linha = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	while (str[i] != '\n' && str[i])
	{
		linha[i] = str[i];
		i++;
	}
	linha[i] = '\0';
	return (linha);
}

int		ft_check_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int			b_read;
	char		buf[BUFFER_SIZE + 1];
	static char	*s[FD_SIZE];

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	while ((b_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[b_read] = '\0';
		s[fd] = s[fd] == NULL ? ft_strdup(buf) : ft_strjoin(s[fd], buf);
		if (ft_check_line(s[fd]))
			break ;
	}
	*line = ft_get_line(s[fd]);
	if (ft_check_line(s[fd]) == 0 && b_read == 0)
	{
		free(s[fd]);
		return (0);
	}
	s[fd] = ft_prepare_next(s[fd]);
	return (1);
}
