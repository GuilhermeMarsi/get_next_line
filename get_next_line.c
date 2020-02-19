/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarsi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:20:16 by gmarsi            #+#    #+#             */
/*   Updated: 2020/02/19 20:42:31 by gmarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

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

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	if (s1 == 0 || s2 == 0)
		return (0);
	j = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(str = (char*)malloc(sizeof(char) * j)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	k = 0;
	while (s2[k])
	{
		str[i + k] = s2[k];
		k++;
	}
	str[i + k] = '\0';
	free((char*)s1);
	return (str);
}

int		get_next_line(int fd, char **line)
{
	int			b_read;
	char		*buf;
	static char	*s;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line ||
	!(buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (!s && !(s = (char*)malloc(sizeof(char) * 1)))
		return (-1);
	while (!(ft_check_line(s)) && (b_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[b_read] = '\0';
		s = ft_strjoin(s, buf);
	}
	*line = ft_get_line(s);
	if (ft_check_line(s) == 0 && b_read == 0)
	{
		free(s);
		free(buf);
		return (0);
	}
	s = ft_prepare_next(s);
	free(buf);
	return (1);
}
