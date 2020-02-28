/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarsi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:21:05 by gmarsi            #+#    #+#             */
/*   Updated: 2020/02/28 19:51:11 by gmarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (ft_strlen((char*)s1) + 1))))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size_str;
	size_t	size_sub;
	char	*sub;

	if (s == NULL)
		return (NULL);
	i = 0;
	size_str = ft_strlen(s);
	if (start > size_str)
		start = size_str;
	if (size_str >= start + len)
		size_sub = len;
	else
		size_sub = size_str - start;
	if (!(sub = (char*)malloc(size_sub + 1)))
		return (NULL);
	while (i < size_sub)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[size_sub] = '\0';
	return (sub);
}
