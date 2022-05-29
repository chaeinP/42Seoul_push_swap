/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:05:08 by chaepark          #+#    #+#             */
/*   Updated: 2022/05/29 00:35:50 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ch_char(char s, char c)
{
	if (s == c || s == '\0')
		return (1);
	return (0);
}

static size_t	ft_dst_len(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (ch_char(s[i], c) == 0 && ch_char(s[i + 1], c) == 1)
			count++;
		i++;
	}
	return (count);
}

static int	make_split_arr(char **dst, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (ch_char(s[i], c) == 1)
			i++;
		else
		{
			j = 0;
			while (ch_char(s[i + j], c) == 0)
				j++;
			dst[k] = (char *)malloc(sizeof(char) * (j + 1));
			if (!dst[k])
				return (0);
			ft_strlcpy(dst[k++], &s[i], j + 1);
			i += j;
		}
	}
	return (1);
}

static char	**ft_malloc_free(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	size_t	dst_len;

	dst_len = ft_dst_len(s, c);
	dst = (char **)malloc(sizeof(char *) * (dst_len + 1));
	if (!dst)
		return (0);
	if (!make_split_arr(dst, s, c))
		return (ft_malloc_free(dst));
	dst[dst_len] = 0;
	return (dst);
}
