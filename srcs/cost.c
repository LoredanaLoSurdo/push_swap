/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llo-surd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:28:58 by llo-surd          #+#    #+#             */
/*   Updated: 2022/12/07 16:47:11 by llo-surd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_cost(t_stack **stacka, t_stack **stackb)
{
	t_stack	*tempa;
	t_stack	*tempb;
	int		sizea;
	int		sizeb;

	tempa = *stacka;
	tempb = *stackb;
	sizea = get_stack_size(tempa);
	sizeb = get_stack_size(tempb);
	while (tempb)
	{
		tempb->costb = tempb->pos;
		if (tempb->pos > sizeb / 2)
			tempb->costb = (sizeb - tempb->pos) * -1;
		tempb->costa = tempb->target_pos;
		if (tempb->target_pos > sizea / 2)
			tempb->costa = (sizea - tempb->target_pos) * -1;
		tempb = tempb->next;
	}
}

int	absolute(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

void	exe_lowcost(t_stack **stacka, t_stack **stackb)
{
	t_stack	*temp;
	int		lowcost;
	int		costa;
	int		costb;

	temp = *stackb;
	lowcost = INT_MAX;
	while (temp)
	{
		if (absolute(temp->costa) + absolute(temp->costb) < absolute(lowcost))
		{
			lowcost = absolute(temp->costb) + absolute (temp->costa);
			costa = temp->costa;
			costb = temp->costb;
		}
		temp = temp->next;
	}
	exe_move(stacka, stackb, costa, costb);
}
