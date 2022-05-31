/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 14:08:13 by chaepark          #+#    #+#             */
/*   Updated: 2022/06/01 02:58:17 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_elem
{
	int				num;
	int				idx;
	struct s_elem	*prev;
	struct s_elem	*next;
}	t_elem;

typedef struct s_stack
{
	t_elem	*top;
	int		length;
}	t_stack;

/* utils */
int		ft_strlen(const char *s);
void	ft_putstr(char *s);
void	ft_print_error(void);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
int		ft_get_chunk(int size);
int		ft_is_sorted(t_stack *stack);

t_elem	*ft_create_elem(int num);
t_stack	*ft_create_stack(void);
void	ft_initialize_stack_a(int ac, char **av, t_stack **stack);
void	ft_push(t_stack *from, t_stack *to, char *name);
void	ft_rotate(t_stack *stack, char *name);
void	ft_rrotate(t_stack *stack, char *name);

#endif
