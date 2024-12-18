/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:51:30 by paperez-          #+#    #+#             */
/*   Updated: 2024/11/28 16:52:11 by paperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

struct s_rots	check_rrarrb(int *list, int length, int partition, int idx)
{
	struct s_rots	rot;
	int				steps_a;
	int				steps_b;
	int				next;

	next = get_next(list, partition, list[idx]);
  if (idx == partition)
  {
    steps_a = 0;
  }
  else
  {
	  steps_a = length - idx;
  }
  if (next == partition - 1)
  {
    steps_b = 0;
  }
  else
  {
	  steps_b = next + 1;
  }
	rot.type = 1;
	if (steps_a < steps_b)
		rot.cost = steps_b;
	else
		rot.cost = steps_a;
	rot.steps_a = rot.cost - steps_b;
	rot.steps_b = rot.cost - steps_a;
	return (rot);
}

struct s_rots	check_rarb(int *list, int partition, int idx)
{
	struct s_rots	rot;
	int				steps_a;
	int				steps_b;
	int				next;

	next = get_next(list, partition, list[idx]);
	steps_a = idx - partition;
	steps_b = partition - next - 1;
	if (steps_b < 0)
		steps_b = 0;
	rot.type = 0;
	if (steps_a < steps_b)
		rot.cost = steps_b;
	else
		rot.cost = steps_a;
	rot.steps_a = rot.cost - steps_b;
	rot.steps_b = rot.cost - steps_a;
	return (rot);
}

struct s_rots	check_rrarb(int *list, int length, int partition, int idx)
{
	struct s_rots	rot;
	int				steps_a;
	int				steps_b;
	int				next;

	next = get_next(list, partition, list[idx]);
  if (idx == partition)
  {
    steps_a = 0;
  }
  else
  {
	  steps_a = length - idx;
  }
	steps_b = partition - next - 1;
	if (steps_b < 0)
		steps_b = 0;
	rot.type = 3;
	rot.cost = steps_a + steps_b;
	rot.steps_a = steps_a;
	rot.steps_b = steps_b;
	return (rot);
}

struct s_rots	check_rarrb(int *list, int partition, int idx)
{
	struct s_rots	rot;
	int				steps_a;
	int				steps_b;
	int				next;

	next = get_next(list, partition, list[idx]);
	steps_a = idx - partition;
  if (next == partition - 1)
  {
    steps_b = 0;
  }
  else
  {
	  steps_b = next + 1;
  }
	rot.type = 2;
	rot.cost = steps_a + steps_b;
	rot.steps_a = steps_a;
	rot.steps_b = steps_b;
	return (rot);
}

struct s_rots	check(int *list, int length, int partition, int idx)
{
	struct s_rots	current_max;
	struct s_rots	candidate;

	current_max = check_rarb(list, partition, idx);
	candidate = check_rrarrb(list, length, partition, idx);
	if (candidate.cost < current_max.cost)
		current_max = candidate;
	candidate = check_rarrb(list, partition, idx);
	if (candidate.cost < current_max.cost)
		current_max = candidate;
	candidate = check_rrarb(list, length, partition, idx);
	if (candidate.cost < current_max.cost)
		current_max = candidate;
	return (current_max);
}
