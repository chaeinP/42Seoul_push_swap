/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:16:59 by chaepark          #+#    #+#             */
/*   Updated: 2022/05/29 20:19:20 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_create_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->top = NULL;
	stack->length = 0;
	return (stack);
}

t_elem	*ft_create_elem(int num)
{
	t_elem	*elem;

	elem = malloc(sizeof(t_elem));
	elem->num = num;
	elem->idx = 0;
	elem->prev = elem;
	elem->next = NULL;
	return (elem);
}
