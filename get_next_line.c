/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarsi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:20:16 by gmarsi            #+#    #+#             */
/*   Updated: 2020/02/27 22:30:57 by gmarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strpos(const char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		ret_frase(char **frase, char **line)
{
	int		posic;
	char	*aux;

	posic = ft_strpos(*frase);
	if (posic >= 0)
	{
		*line = ft_substr(*frase, 0, posic);
		aux = ft_substr(*frase, posic + 1, ft_strlen(*frase) - posic);
		free(*frase);
		*frase = aux;
		aux = NULL;
		return (1);
	}
	else
		return (0);
}

int		ft_free_buffer(char *str, int ret)
{
	if (str)
		free(str);
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	int			b_read;
	char		*buf;
	static char	*s[FD_SIZE];

	if (fd < 0 || BUFFER_SIZE <= 0 || !line ||
		(!(buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1)))))
		return (-1);
	if (s[fd] != NULL)
	{
		if (ret_frase(&s[fd], line))
			return (ft_free_buffer(buf, 1));
	}
	else
		s[fd] = ft_strdup("");
	while ((b_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[b_read] = '\0';
		if (!(s[fd] = ft_strjoin(s[fd], buf)))
			return (-1);
		if (ret_frase(&s[fd], line))
			return (ft_free_buffer(buf, 1));
	}
	*line = b_read < 0 ? NULL : s[fd];
	s[fd] = NULL;
	return (ft_free_buffer(buf, b_read));
}
