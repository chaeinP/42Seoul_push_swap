/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:50:38 by chaepark          #+#    #+#             */
/*   Updated: 2022/06/03 21:43:07 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack, char *name)
{
	t_elem	*top;
	t_elem	*bottom;
	t_elem	*temp;

	ft_putstr(name);
	if (stack->length < 2)
		return ;
	top = stack->top;
	bottom = stack->top->prev;
	temp = stack->top->next;
	top->prev = temp;
	top->next = temp->next;
	temp->prev = bottom;
	temp->next->prev = top;
	temp->next = top;
	stack->top = temp;
}

void	ft_rotate(t_stack *stack, char *name)
{
	t_elem	*target;

	ft_putstr(name);
	if (stack->length < 2)
		return ;
	target = stack->top;
	stack->top = target->next;
	target->next = NULL;
	target->prev->next = target;
}

void	ft_rrotate(t_stack *stack, char *name)
{
	t_elem	*target;

	ft_putstr(name);
	if (stack->length < 2)
		return ;
	target = stack->top->prev;
	target->next = stack->top;
	target->prev->next = NULL;
	stack->top = target;
}
