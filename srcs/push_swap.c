/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llo-surd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:48:33 by llo-surd          #+#    #+#             */
/*   Updated: 2022/12/08 13:36:22 by llo-surd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		free_stacks(t_stack **stack);
static void	sort_method(t_stack **stacka, t_stack **stackb, int size);

int	sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	sort_method(t_stack **stacka, t_stack **stackb, int size)
{
	if (size == 2 && !sorted(*stacka))
		sa(stacka);
	else if (size == 3)
		sort_three(stacka);
	else if (size > 3 && !sorted(*stacka))
		sort(stacka, stackb);
}

void	free_stacks(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !(*stack))
	{
		return ;
	}
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

int	main(int argc, char **argv)
{
	t_stack	*stacka;
	t_stack	*stackb;
	int		size;

	if (argc < 2)
	{
		return (0);
	}
	if (check_input(argv) != 0)
	{
		return (0);
	}
	stackb = NULL;
	stacka = init_stack(argc, argv);
	size = get_stack_size(stacka);
	init_index(stacka, size + 1);
	sort_method(&stacka, &stackb, size);
	free_stacks(&stacka);
	free_stacks(&stackb);
	return (0);
}
