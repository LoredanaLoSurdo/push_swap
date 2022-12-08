/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llo-surd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:00:34 by llo-surd          #+#    #+#             */
/*   Updated: 2022/12/08 14:23:43 by llo-surd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				costa;
	int				costb;
	struct s_stack	*next;
}	t_stack;

int			check_input(char **argv);

void		move_cost(t_stack **stacka, t_stack **stackb);
int			absolute(int num);
void		exe_lowcost(t_stack **stacka, t_stack **stackb);

void		exe_move(t_stack **a, t_stack **b, int costa, int costb);

t_stack		*init_stack(int argc, char **argv);
t_stack		*add_node(int num);
void		add_to_bottom(t_stack **stack, t_stack *num);
int			get_stack_size(t_stack *stack);
void		init_index(t_stack *stacka, int size);

void		init_tp(t_stack **stacka, t_stack **stackb);
int			lowest_index(t_stack **stack);

void		pa(t_stack **stacka, t_stack **stackb);
void		pb(t_stack **stacka, t_stack **stackb);

int			sorted(t_stack *stack);

void		rra(t_stack **stacka);
void		rrb(t_stack **stackb);
void		rrr(t_stack **stacka, t_stack **stackb);

void		ra(t_stack **stacka);
void		rb(t_stack **stackb);
void		rr(t_stack **stacka, t_stack **stackb);
t_stack		*get_end(t_stack *stack);

void		sort(t_stack **stacka, t_stack **stackb);
void		hold_three(t_stack **stacka, t_stack **stackb);
void		sort_three(t_stack **stack);

void		sa(t_stack **stacka);
void		sb(t_stack **stacka);
void		ss(t_stack **stacka, t_stack **stackb);

long		ft_atoi(const char *str);

#endif