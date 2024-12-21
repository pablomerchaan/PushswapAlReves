/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emitrot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:23:35 by paperez-          #+#    #+#             */
/*   Updated: 2024/12/21 14:28:11 by paperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char	*get_step_name(int type)
{
	if (type == 0)
		return ("pa");
	else if (type == 1)
		return ("pb");
	else if (type == 2)
		return ("sa");
	else if (type == 3)
		return ("sb");
	else if (type == 4)
		return ("ss");
	else if (type == 5)
		return ("ra");
	else if (type == 6)
		return ("rb");
	else if (type == 7)
		return ("rr");
	else if (type == 8)
		return ("rra");
	else if (type == 9)
		return ("rrb");
	else if (type == 10)
		return ("rrr");
	return ("WRONG TYPE");
}

void	emit_step(int type)
{
	ft_printf ("%s\n", get_step_name(type));
}

void	do_print(int type_1, int type_2, int comp_1, int comp_2)
{
	int	c;

	c = 0;
	while (c < comp_1)
	{
		emit_step(type_1);
		c++;
	}
	c = 0;
	while (c < comp_2)
	{
		emit_step(type_2);
		c++;
	}
}

void	emit_from_rots(struct s_rots rot)
{
	if (rot.type == 0)
	{
		if (rot.steps_a == 0)
			do_print (7, 6, rot.cost - rot.steps_b, rot.steps_b);
		else
			do_print (7, 5, rot.cost - rot.steps_a, rot.steps_a);
	}
	if (rot.type == 1)
	{
		if (rot.steps_a == 0)
			do_print (10, 9, rot.cost - rot.steps_b, rot.steps_b);
		else
			do_print (10, 8, rot.cost - rot.steps_a, rot.steps_a);
	}
	if (rot.type == 2)
		do_print (5, 9, rot.steps_a, rot.steps_b);
	if (rot.type == 3)
		do_print (8, 6, rot.steps_a, rot.steps_b);
	emit_step(1);
}
