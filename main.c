/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarsi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:18:00 by gmarsi            #+#    #+#             */
/*   Updated: 2020/02/27 19:46:56 by gmarsi           ###   ########.fr       */
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
	int		retorno;
	char	*txt;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	while ((retorno = get_next_line(fd, &txt)) > 0)
		printf("\nRetorno: %i --> %s", retorno, txt);
	printf("\nRetorno: %i --> %s", retorno, txt);
	printf("\n");
	close(fd);
	return (0);
}
