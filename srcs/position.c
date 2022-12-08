/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llo-surd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:50:47 by llo-surd          #+#    #+#             */
/*   Updated: 2022/12/08 13:14:43 by llo-surd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_position(t_stack **stack);
static int	get_target(t_stack **a, int b_index, int t_index, int target_pos);

void	init_tp(t_stack **stacka, t_stack **stackb)
{
	t_stack	*tempb;
	int		target_pos;

	tempb = *stackb;
	get_position(stacka);
	get_position(stackb);
	target_pos = 0;
	while (tempb)
	{
		target_pos = get_target(stacka, tempb->index, INT_MAX, target_pos);
			tempb->target_pos = target_pos;
		tempb = tempb->next;
	}
}

static void	get_position(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	temp = *stack;
	i = 0;
	while (temp)
	{
		temp->pos = i;
		temp = temp->next;
		i++;
	}
}

static int	get_target(t_stack **a, int b_index, int t_index, int target_pos)
{
	t_stack	*tempa;

	tempa = *a;
	while (tempa)
	{
		if (tempa->index > b_index && tempa->index < t_index)
		{
			t_index = tempa->index;
			target_pos = tempa->pos;
		}
		tempa = tempa->next;
	}
	if (t_index != INT_MAX)
		return (target_pos);
	tempa = *a;
	while (tempa)
	{
		if (tempa->index < t_index)
		{
			t_index = tempa->index;
			target_pos = tempa->pos;
		}
		tempa = tempa->next;
	}
	return (target_pos);
}

int	lowest_index(t_stack **stack)
{
	t_stack	*temp;
	int		lowest_index;
	int		position;

	temp = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	position = temp->pos;
	while (temp)
	{
		if (temp->index < lowest_index)
		{
			lowest_index = temp->index;
			position = temp->pos;
		}
		temp = temp->next;
	}
	return (position);
}
