/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarsi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:18:00 by gmarsi            #+#    #+#             */
/*   Updated: 2020/02/17 18:25:11 by gmarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(int argc, char *argv[])
{
	int		fd;
	int		i;
	int		retorno;
	char	*txt;

	(void)argc;
	i = 11;
	fd = open(argv[1], O_RDONLY);
	while ((retorno = get_next_line(fd, &txt)) > 0)
	{
		printf("\n%s", txt);
		i--;
	}
	printf("\n\n");
	close(fd);
	return (0);
}
