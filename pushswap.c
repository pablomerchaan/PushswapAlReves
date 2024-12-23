/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:25:49 by paperez-          #+#    #+#             */
/*   Updated: 2024/12/21 16:56:15 by paperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	rotaux(struct s_l list, int round, struct s_minmax m, int current_cost)
{
	struct s_rots		goodrot;
	struct s_intsaux	ints;
	int					current_round;

	current_round = 1;
	ints.steps = 0;
	while (current_round <= round)
	{
		if (current_round == round)
			ints.current_max = INT_MAX;
		else
			ints.current_max = current_round * (m.max - m.min) / 9 + m.min;
		ints.i = -1;
		while (ints.i != list.length)
		{
			goodrot = auxaux(ints, list, goodrot, current_cost);
			transformrot(list, goodrot);
			emit_from_rots(goodrot);
			list.partition += 1;
			ints = completeints(ints, list, goodrot);
		}
		current_round++;
	}
	return (ints.steps);
}

struct s_rots	auxaux(struct s_intsaux ints,
			struct s_l list, struct s_rots goodrot, int current_cost)
{
	struct s_rots	candidate;

	ints.i = list.partition;
	goodrot.type = -1;
	ints.good_cost = INT_MAX;
	while (ints.i < list.length)
	{
		if (list.list[ints.i] <= ints.current_max)
		{
			candidate = check(list.list, list.length, list.partition, ints.i);
			current_cost = candidate.cost;
			current_cost += lookahead(list, candidate, ints.current_max, 100);
			if (goodrot.type == -1 || current_cost < ints.good_cost)
			{
				goodrot = candidate;
				ints.good_cost = current_cost;
			}
		}
		ints.i++;
	}
	return (goodrot);
}

int	emitlaststeps(struct s_intsrot intsr, int length, struct s_l list)
{
	struct s_change		rotation;

	rotation.type = 9;
	rotation.idx = length;
	intsr.j = 0;
	if (intsr.i == length - 1)
		intsr.i = -1;
	while (intsr.j <= intsr.i)
	{
		transform(list.list, rotation, list.length);
		emit_step(rotation.type);
		intsr.j++;
	}
	intsr.steps += (list.length - intsr.i);
	intsr.steps += list.length;
	intsr.i = 0;
	while (intsr.i < length)
	{
		emit_step(0);
		intsr.i++;
	}
	return (intsr.steps);
}

int	rotations(int *lst, int min, int max, int length)
{
	struct s_intsrot	intsr;
	struct s_l			list;
	struct s_minmax		m;

	intsr.steps = 0;
	m.min = min;
	m.max = max;
	list.partition = 0;
	list.length = length;
	list.list = lst;
	intsr.round = 9;
	intsr.current_cost = 0;
	if (length < 4)
	{
		intsr.steps += sortthree(lst, length);
		return (intsr.steps);
	}
	else if (length < 15)
		intsr.steps += rotaux(list, 1, m, intsr.current_cost);
	else
		intsr.steps += rotaux(list, intsr.round, m, intsr.current_cost);
	intsr.i = get_next(list.list, length, INT_MIN);
	intsr.steps += emitlaststeps(intsr, length, list);
	return (intsr.steps);
}

int	main(int argc, char **argv)
{
	struct s_minmax	m;
	struct s_l		list;
	char			**argvtmp;
	int				sw;

	sw = getsw(argc);
	list.list = NULL;
	list.length = 0;
	if (argc < 2)
		return (0);
	m.max = INT_MIN;
	m.min = INT_MAX;
	argvtmp = solveargv(argc, argv);
	argc = solveargc(argc, argv);
	list.list = malloc (sizeof(int) * (argc));
	list = makelist(argc, argvtmp, list, m);
	if (list.list == NULL || sorted(list.list, list.length) == 0)
	{
		free(argvtmp);
		return (0);
	}
	m = geetminmax(list);
	rotations (list.list, m.min, m.max, list.length);
	freeboth (list.list, argvtmp, sw);
	return (0);
}
