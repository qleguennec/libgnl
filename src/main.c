/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 21:06:02 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/09 14:42:49 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			main
	(int argc, char **argv)
{
	size_t	i;
	int		fd;
	int		gnl_return;
	char	*line;

	i = 1;
	line = NULL;
	if (argc == 1)
	{
		ft_putendl("usage: gnl-test file");
		return (1);
	}
	while (i < (size_t)argc)
	{
		fd = open(argv[i], 0, 0);
		printf("debug\topen %s on fd %d\n", argv[i], fd);
		while (1)
		{
			gnl_return = get_next_line(fd, &line);
			if (line)
			{
				ft_putstr("debug\t");
				ft_putendl(line);
			}
			else
			{
				ft_putstr("debug\t");
				ft_putendl("line is set to NULL");
			}
			if (gnl_return <= 0)
			{
				ft_putstr("debug\tgnl exited with ");
				ft_putnbr(gnl_return);
				ft_putendl("");
				break ;
			}
		}
		i++;
		if (i < (size_t)argc)
			printf("debug\t\n");
	}
	return (0);
}
