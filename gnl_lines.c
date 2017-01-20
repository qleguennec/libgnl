/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 13:44:24 by qle-guen          #+#    #+#             */
/*   Updated: 2017/01/20 15:38:16 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../libft/malloc.h"
#include "libgnl.h"
// TODO remove debug includes
#include <assert.h>

int		gnl_lines(int fd, t_vect *lines, int opts)
{
	char	*dup;
	int		ret;
	t_vect	buf;
	t_vect	line;

	vect_init(&buf);
	vect_init(&line);
	while ((ret = get_next_line(fd, &buf, &line, opts | GNL_STR)) == 1)
	{
		if (!line.used)
			continue ;
		assert(ft_strlen(line.data) == line.used - 1);
		MALLOC_N(dup, line.used);
		ft_memcpy(dup, line.data, line.used);
		VECT_ADD(lines, dup);
		line.used = 0;
	}
	free(line.data);
	free(buf.data);
	return (ret);
}
