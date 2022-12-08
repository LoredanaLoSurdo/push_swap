/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llo-surd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:23:42 by llo-surd          #+#    #+#             */
/*   Updated: 2022/12/07 21:56:18 by llo-surd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(int argc, char **argv)
{
	t_stack		*stacka;
	long int	num;
	int			i;

	stacka = NULL;
	num = 0;
	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (i == 1)
			stacka = add_node((int)num);
		else
			add_to_bottom(&stacka, add_node((int)num));
			i++;
	}
	return (stacka);
}

t_stack	*add_node(int num)
{
	t_stack	*node;

	node = malloc(sizeof * node);
	if (!node)
		return (NULL);
	node->value = num;
	node->index = 0;
	node->pos = -1;
	node->target_pos = -1;
	node->costa = -1;
	node->costb = -1;
	node->next = NULL;
	return (node);
}

void	add_to_bottom(t_stack **stack, t_stack *num)
{
	t_stack	*end;

	if (!num)
		return ;
	if (!*stack)
	{
		*stack = num;
		return ;
	}
	end = get_end(*stack);
	end->next = num;
}

int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

void	init_index(t_stack *stacka, int size)
{
	t_stack	*i;
	t_stack	*highest;
	int		value;

	while (--size > 0)
	{
		i = stacka;
		value = INT_MIN;
		highest = NULL;
		while (i)
		{
			if (i->value == INT_MIN && i->index == 0)
				i->index = 1;
			if (i->value > value && i->index == 0)
			{
				value = i->value;
				highest = i;
				i = stacka;
			}
			else
			i = i->next;
		}
		if (highest != NULL)
			highest->index = size;
	}
}
