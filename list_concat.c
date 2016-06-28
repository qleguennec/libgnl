/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_concat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 19:11:46 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/28 16:35:03 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "list.h"
#include <stdlib.h>

static void	copy
	(t_list *l, void **s)
{
	while (l)
	{
		*s -= l->size;
		ft_memcpy(*s, l->data, l->size);
		l = l->next;
	}
}

int			list_concat
	(t_list *alst)
{
	size_t	len;
	t_list	*l;
	void	*s;

	if (!alst)
		return (0);
	len = 0;
	l = alst;
	while (l)
	{
		len += l->size;
		l = l->next;
	}
	if (!(s = malloc(len)))
		return (0);
	s += len;
	copy(alst, &s);
	free(alst->data);
	list_del(&alst->next);
	alst->data = s;
	alst->size = len;
	return (1);
}
