/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:50:45 by paperez-          #+#    #+#             */
/*   Updated: 2024/12/11 13:05:58 by paperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	sorted(long *list, int length)
{
	int	c;

	c = 1;
	while (c < length)
	{
		if (list[c - 1] > list[c])
			return (1);
		c++;
	}
	return (0);
}

long     *checkrepetition(struct s_l list)
{
        int     c;
        int     c2;

        c = 0;
        while (c < list.length)
        {
                c2 = list.length - 1;
                while (c2 > c)
                {
                        if (list.list[c] == list.list[c2])
                                return (NULL);
                        else
                                c2--;
                }
                c++;
        }
        return (list.list);
}

struct s_l	addmin(struct s_l list, int min)
{
	int c;

	c = 0;
	if (min >= 0)
		return (list);
	while (c < list.length)
	{
		list.list[c] = list.list[c] - min;
		c++;
	}
	return (list);
}
