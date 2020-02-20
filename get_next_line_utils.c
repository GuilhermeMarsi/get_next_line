/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarsi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:21:05 by gmarsi            #+#    #+#             */
/*   Updated: 2020/02/19 22:31:32 by gmarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_prepare_next(char *str)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (NULL);
	if (!(temp = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1 - i))))
		return (NULL);
	i++;
	while (str[i + j])
	{
		temp[j] = str[i + j];
		j++;
	}
	temp[j] = '\0';
	free(str);
	return (temp);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;
	size_t	i;

	i = 0;
	ret = malloc(count * size);
	if (ret == NULL)
		return (NULL);
	while (i < count * size)
	{
		((char*)ret)[i] = 0;
		i += 1;
	}
	return (ret);
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

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
