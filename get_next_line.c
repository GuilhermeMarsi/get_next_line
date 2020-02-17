/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarsi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:20:16 by gmarsi            #+#    #+#             */
/*   Updated: 2020/02/17 18:25:14 by gmarsi           ###   ########.fr       */
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
	while (str[i] != '\n')
	{
		linha[i] = str[i];
		i++;
	}
	linha[i] = '\0';
	return (linha);
}

int		ft_check_line_break(char *str)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	if (s1 == 0 || s2 == 0)
		return (0);
	j = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char*)malloc(sizeof(char) * (j + 1))))
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
	return (str);
}

int		get_next_line(int fd, char **line)
{
	int			bytes_read;
	char		*buf;
	static char	*save;

	if (!(buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1)))
		|| fd < 0 || BUFFER_SIZE == 0 || !line)
		return (-1);
	if (save == NULL)
		if (!(save = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
	while ((bytes_read = read(fd, buf, BUFFER_SIZE)) > 0 || ft_strlen(save) > 0)
	{
		buf[bytes_read] = '\0';
		save = ft_strjoin(save, buf);
		if (ft_check_line_break(save))
		{
			*line = ft_get_line(save);
			save = ft_prepare_next(save);
			free(buf);
			return (1);
		}
	}
	return (0);
}
