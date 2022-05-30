/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 14:43:48 by chaepark          #+#    #+#             */
/*   Updated: 2022/05/31 00:09:55 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

void	ft_print_error(void)
{
	ft_putstr("ERROR\n");
	exit(1);
}

int	ft_get_chunk(int size)
{
	int	chunk;

	chunk = 0.000000053 * size * size + 0.03 * size + 14.5;
	if (chunk > size)
		chunk = size / 3;
	return (chunk);
}

int	ft_is_sorted(t_stack *stack)
{
	int		i;
	t_elem	*cur;

	i = 0;
	cur = stack->top;
	while (cur)
	{
		if (i != cur->idx)
			return (0);
		i++;
		cur = cur->next;
	}
	return (1);
}
