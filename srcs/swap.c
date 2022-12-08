/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llo-surd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:51:43 by llo-surd          #+#    #+#             */
/*   Updated: 2022/12/08 09:45:33 by llo-surd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	temp;

	if (stack == NULL || stack->next == NULL)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	temp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp;
}

void	sa(t_stack **stacka)
{
	swap(*stacka);
	write(1, "sa\n", 3);
}

void	sb(t_stack **stackb)
{
	swap(*stackb);
	write(1, "sb", 3);
}

void	ss(t_stack **stacka, t_stack **stackb)
{
	swap(*stacka);
	swap(*stackb);
	write (1, "ss\n", 3);
}
