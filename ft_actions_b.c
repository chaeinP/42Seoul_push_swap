/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:12:38 by chaepark          #+#    #+#             */
/*   Updated: 2022/06/01 16:12:59 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	t_elem	*ft_pop(t_stack *stack)
{
	t_elem	*target;

	target = stack->top;
	if (stack->length == 0)
		return (target);
	if (stack->length == 1)
		stack->top = NULL;
	else
	{
		stack->top = target->next;
		stack->top->prev = target->prev;
	}
	stack->length--;
	return (target);
}

static void	ft_unshift(t_stack *stack, t_elem *new)
{
	if (stack->length == 0)
	{
		stack->top = new;
		new->prev = new;
		new->next = NULL;
	}
	else
	{
		new->prev = stack->top->prev;
		stack->top->prev = new;
		new->next = stack->top;
		stack->top = new;
	}
	stack->length++;
}

void	ft_push(t_stack *from, t_stack *to, char *name)
{
	t_elem	*target;

	ft_putstr(name);
	target = ft_pop(from);
	if (!target)
		return ;
	ft_unshift(to, target);
}
