/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:50:45 by paperez-          #+#    #+#             */
/*   Updated: 2024/12/19 14:42:37 by paperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	sorted(int *list, int length)
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

int	*checkrepetition(struct s_l list)
{
	int	c;
	int	c2;

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

struct s_minmax	geetminmax(struct s_l list)
{
	struct s_minmax	m;
	int				c;

	c = 0;
	m.max = INT_MIN;
	m.min = INT_MAX;
	while (c < list.length)
	{
		if (list.list[c] < m.min)
			m.min = list.list[c];
		if (list.list[c] > m.max)
			m.max = list.list[c];
		c++;
	}
	return (m);
}

int	checkerrors(char *arg)
{
	int	c;

	c = 0;
	while (arg[c] != '\0')
	{
		if (arg[c] == ' ' || arg[c] == '-' || (arg[c] >= '0' && arg[c] <= '9'))
			c++;
		else
			return (1);
	}
	return (0);
}
