/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:55:27 by chaepark          #+#    #+#             */
/*   Updated: 2022/06/03 22:00:28 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reindex_stack(t_stack *stack, t_elem *new)
{
	t_elem	*cur;
	int		len;

	cur = stack->top;
	len = stack->length;
	while (len--)
	{
		if (cur->num == new->num)
			ft_print_error();
		if (cur->num > new->num)
			cur->idx++;
		else
			new->idx++;
		cur = cur->next;
	}
}

static void	ft_stack_add_bottom(t_stack *stack, t_elem *new)
{
	t_elem	*bottom;

	if (!stack->top)
		stack->top = new;
	else
	{
		bottom = stack->top->prev;
		bottom->next = new;
		new->prev = bottom;
		stack->top->prev = new;
		ft_reindex_stack(stack, new);
	}
	stack->length++;
}

void	ft_initialize_stack_a(int ac, char **av, t_stack **stack)
{
	char	**str;
	int		num;
	int		i;
	int		j;
	t_elem	*new;

	i = 1;
	while (i < ac)
	{
		str = ft_split(av[i], ' ');
		if (!str)
			exit(1);
		j = 0;
		while (str[j])
		{
			num = ft_atoi(str[j]);
			new = ft_create_elem(num);
			ft_stack_add_bottom(*stack, new);
			free(str[j++]);
		}
		i++;
		free(str);
	}
}
