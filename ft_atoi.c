/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:56:56 by chaepark          #+#    #+#             */
/*   Updated: 2022/05/29 17:37:36 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	ft_print_error();
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t		i;
	int			n;
	long long	result;
	long long	tmp;

	i = 0;
	n = 1;
	result = 0;
	if (str[i] == '-')
		n = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		tmp = result * 10 + str[i++] - 48;
		if (tmp < result && n == 1)
			ft_print_error();
		if (tmp < result && n == -1)
			ft_print_error();
		result = tmp;
	}
	return (result * n);
}
