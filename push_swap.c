/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 14:08:09 by chaepark          #+#    #+#             */
/*   Updated: 2022/05/30 00:42:40 by chaepark         ###   ########.fr       */
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
	chunk = 3;
	ft_move_a_to_b(stack_a, stack_b, chunk);

	t_elem *cur;
	cur = stack_a->top;
	while (cur)
	{
		printf("a: %d \n", cur->num);
		cur = cur->next;
	}

	cur = stack_b->top;
	while (cur)
	{
		printf("b: %d \n", cur->idx);
		cur = cur->next;
	}
	return (0);
}
