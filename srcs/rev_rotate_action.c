/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_action.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llo-surd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:47:03 by llo-surd          #+#    #+#             */
/*   Updated: 2022/12/08 13:02:56 by llo-surd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*second_last(t_stack *stack);

static void	rev_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*end;
	t_stack	*scnd_last;

	end = get_end(*stack);
	scnd_last = second_last(*stack);
	temp = *stack;
	*stack = end;
	(*stack)->next = temp;
	scnd_last->next = NULL;
}

void	rra(t_stack **stacka)
{
	rev_rotate(stacka);
	write (1, "rra\n", 4);
}

void	rrb(t_stack **stackb)
{
	rev_rotate(stackb);
	write (1, "rrb\n", 4);
}

void	rrr(t_stack **stacka, t_stack **stackb)
{
	rev_rotate(stacka);
	rev_rotate(stackb);
	write(1, "rrr\n", 4);
}

t_stack	*second_last(t_stack *stack)
{
	while (stack->next->next)
		stack = stack->next;
	return (stack);
}
