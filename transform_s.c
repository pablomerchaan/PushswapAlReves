/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:07:51 by paperez-          #+#    #+#             */
/*   Updated: 2024/11/26 19:32:07 by paperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

long	*transform_sa(long *list, int idx)
{
	int	tmp;

	tmp = list[idx - 1];
	list[idx - 1] = list[idx - 2];
	list[idx - 2] = tmp;
	return (list);
}

long	*transform_sb(long *list, int idx)
{
	int	tmp;

	tmp = list[idx];
	list[idx] = list[idx + 1];
	list[idx + 1] = tmp;
	return (list);
}

long	*transform_ss(long *list, int idx)
{
	int	tmp;

	tmp = list[idx - 1];
	list[idx - 1] = list[idx - 2];
	list[idx - 2] = tmp;
	tmp = list[idx];
	list[idx] = list[idx + 1];
	list[idx + 1] = tmp;
	return (list);
}
