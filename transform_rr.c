/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:07:38 by paperez-          #+#    #+#             */
/*   Updated: 2024/11/26 19:29:26 by paperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

long	*transform_rra(long *list, int idx, int length)
{
	int	tmp;
	int	c;

	tmp = list[length - 1];
	c = length - 1;
	while (c > idx)
	{
		list[c] = list[c - 1];
		c--;
	}
	list[idx] = tmp;
	return (list);
}

long	*transform_rrb(long *list, int idx)
{
	int	tmp;
	int	c;

  if (idx == 0)
    return (list);

	c = 0;
	tmp = list[0];
	while (c < idx - 1)
	{
		list[c] = list[c + 1];
		c++;
	}
	list[c] = tmp;
	return (list);
}

long	*transform_rrr(long *list, int idx, int length)
{
	long	*r;

	r = transform_rra(list, idx, length);
	r = transform_rrb(list, idx);
	return (r);
}
