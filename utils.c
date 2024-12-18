/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:10:52 by paperez-          #+#    #+#             */
/*   Updated: 2024/12/05 18:38:29 by paperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_atoi(const char *str)
{
	int		result;
	int		sign;
	int		i;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
			i++;
		else
			return ('\0');
	}
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

int	gnaux(int c, int partition, int *list, int next)
{
	while (c != partition)
	{
		if (list[c] > list[next])
			next = c;
		c++;
	}
	return (next);
}

int	get_next(int *list, int partition, int num)
{
	int	c;
	int	next;
	int	current_next;

	if (partition == 0)
		return (0);
	c = partition - 1;
	next = 0;
	current_next = INT_MAX;
	while (c >= 0)
	{
		if (num - list[c] < current_next && num - list[c] > 0)
		{
			current_next = num - list[c];
			next = c;
		}
		c--;
	}
	if (current_next == INT_MAX)
		next = gnaux(c, partition, list, next);
	return (next);
}

int	getmin(int A, int B)
{
	if (A < B)
		return (A);
	else
		return (B);
}

struct	s_rots	minrot(struct s_rots rot1, struct s_rots rot2)
{
	if (rot1.cost < rot2.cost)
		return (rot1);
	return (rot2);
}
