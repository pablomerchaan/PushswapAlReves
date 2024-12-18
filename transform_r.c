/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:07:57 by paperez-          #+#    #+#             */
/*   Updated: 2024/11/26 19:31:33 by paperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

long	*transform_ra(long *list, int idx, int length)
{
	int	tmp;
	int	c;

	tmp = list[idx];
	c = idx;
	while (c + 1 < length)
	{
		list[c] = list[c + 1];
		c++;
	}
	list[c] = tmp;
	return (list);
}

long	*transform_rb(long *list, int idx)
{
	int	tmp;
	int	c;

  if (idx == 0)
    return (list);

	tmp = list[idx - 1];
	c = idx - 1;
	while (c > 0)
	{
		list[c] = list[c - 1];
		c--;
	}
	list[0] = tmp;
	return (list);
}

long	*transform_rr(long *list, int idx, int length)
{
	transform_ra (list, idx, length);
	transform_rb (list, idx);
	return (list);
}
