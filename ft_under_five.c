/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_under_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:58:06 by chaepark          #+#    #+#             */
/*   Updated: 2022/06/03 21:36:13 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_three(t_stack *stack_a)
{
	int	top;
	int	middle;
	int	bottom;

	top = stack_a->top->idx;
	middle = stack_a->top->next->idx;
	bottom = stack_a->top->prev->idx;
	if (top > middle && top < bottom)
		ft_swap(stack_a, "sa\n");
	else if (top < middle && top > bottom)
		ft_rrotate(stack_a, "rra\n");
	else if (top > middle && top > bottom && middle > bottom)
	{
		ft_swap(stack_a, "sa\n");
		ft_rrotate(stack_a, "rra\n");
	}
	else if (top > middle && top > bottom && middle < bottom)
		ft_rotate(stack_a, "ra\n");
	else
	{
		ft_swap(stack_a, "sa\n");
		ft_rotate(stack_a, "ra\n");
	}
	return ;
}

static void	ft_push_0_and_1(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->top->idx != 0 && stack_a->top->idx != 1)
		ft_rotate(stack_a, "ra\n");
	ft_push(stack_a, stack_b, "pb\n");
}

static void	ft_push_0(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->top->idx != 0)
		ft_rotate(stack_a, "ra\n");
	ft_push(stack_a, stack_b, "pb\n");
}

void	ft_under_five(t_stack *stack_a, t_stack *stack_b)
{
	(void) stack_b;
	if (stack_a->length == 2)
		ft_swap(stack_a, "sa\n");
	else if (stack_a->length == 3)
		ft_sort_three(stack_a);
	else if (stack_a->length == 4)
	{
		ft_push_0(stack_a, stack_b);
		ft_sort_three(stack_a);
		ft_push(stack_b, stack_a, "pa\n");
	}
	else
	{
		ft_push_0_and_1(stack_a, stack_b);
		ft_push_0_and_1(stack_a, stack_b);
		if (!ft_is_sorted(stack_a, 2))
			ft_sort_three(stack_a);
		ft_push(stack_b, stack_a, "pa\n");
		ft_push(stack_b, stack_a, "pa\n");
		if (stack_a->top->idx != 0)
			ft_swap(stack_a, "sa\n");
	}
}
