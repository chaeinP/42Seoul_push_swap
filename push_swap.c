/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 14:08:09 by chaepark          #+#    #+#             */
/*   Updated: 2022/06/01 02:28:15 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_move_a_to_b(t_stack *stack_a, t_stack *stack_b, int chunk)
{
	int		num;
	t_elem	*top;
	t_elem	*next;

	num = 0;
	top = stack_a->top;
	while (top)
	{
		next = top->next;
		if (top->idx <= num)
		{
			ft_push(stack_a, stack_b, "pb\n");
			num++;
		}
		else if (num < top->idx && top->idx <= num + chunk)
		{
			ft_push(stack_a, stack_b, "pb\n");
			ft_rotate(stack_b, "rb\n");
			num++;
		}
		else
			ft_rotate(stack_a, "ra\n");
		top = next;
	}
}

static int	is_max_at_top(t_stack *stack_b, int *depth, int max)
{
	t_elem	*top;
	t_elem	*bottom;
	int		temp;

	top = stack_b->top;
	bottom = stack_b->top->prev;
	temp = *depth;
	if (max == top->idx)
		return (1);
	while (1)
	{
		temp++;
		if (max == top->idx)
		{
			*depth = temp - 1;
			return (1);
		}
		else if (max == bottom->idx)
		{
			*depth = temp;
			return (0);
		}
		top = top->next;
		bottom = bottom->prev;
	}
}

static void	ft_move_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	num;
	int	depth;
	int	count;

	num = stack_b->length - 1;
	count = stack_b->length;
	while (count--)
	{
		depth = 0;
		if (is_max_at_top(stack_b, &depth, num))
		{
			while (depth--)
				ft_rotate(stack_b, "rb\n");
		}
		else
		{
			while (depth--)
				ft_rrotate(stack_b, "rrb\n");
		}
		ft_push(stack_b, stack_a, "pa\n");
		num--;
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		chunk;

	if (ac < 2)
		exit(1);
	stack_a = ft_create_stack();
	stack_b = ft_create_stack();
	ft_initialize_stack_a(ac, av, &stack_a);
	if (ft_is_sorted(stack_a))
		return (0);
	chunk = ft_get_chunk(stack_a->length);
	ft_move_a_to_b(stack_a, stack_b, chunk);
	ft_move_b_to_a(stack_a, stack_b);
	return (0);
}
