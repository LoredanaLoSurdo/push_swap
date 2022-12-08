/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llo-surd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:53:14 by llo-surd          #+#    #+#             */
/*   Updated: 2022/12/08 13:35:53 by llo-surd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	highest_index(t_stack *stack)
{
	int	i;

	i = INT_MIN;
	while (stack)
	{
		if (stack->index > i)
			i = stack->index;
		stack = stack->next;
	}
	return (i);
}

void	hold_three(t_stack **stacka, t_stack **stackb)
{
	int	size;
	int	push;
	int	i;

	size = get_stack_size(*stacka);
	push = 0;
	i = 0;
	while (size > 6 && i < size && push < size / 2)
	{
		if ((*stacka)->index <= size / 2)
		{
			pb(stacka, stackb);
			push++;
		}
		else
			ra(stacka);
			i++;
	}
	while (size - push > 3)
	{
		pb (stacka, stackb);
		push++;
	}
}

void	sort_three(t_stack **stack)
{
	int	largest;

	if (sorted(*stack))
		return ;
	largest = highest_index(*stack);
	if ((*stack)->index == largest)
		ra(stack);
	else if ((*stack)->next->index == largest)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}

static void	sort_a(t_stack **stacka)
{
	int	starting_pos;
	int	size;

	size = get_stack_size(*stacka);
	starting_pos = lowest_index(stacka);
	if (starting_pos > size / 2)
	{
		while (starting_pos < size)
		{
			rra(stacka);
			starting_pos++;
		}
	}
	else
	{
		while (starting_pos > 0)
		{
			ra(stacka);
			starting_pos--;
		}
	}
}

void	sort(t_stack **stacka, t_stack **stackb)
{
	hold_three(stacka, stackb);
	sort_three(stacka);
	while (*stackb)
	{
		init_tp(stacka, stackb);
		move_cost(stacka, stackb);
		exe_lowcost(stacka, stackb);
	}
	if (!sorted(*stacka))
		sort_a(stacka);
}
