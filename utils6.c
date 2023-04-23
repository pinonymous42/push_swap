/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohmatsu <kohmatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:26:29 by kohmatsu          #+#    #+#             */
/*   Updated: 2022/12/27 15:31:05 by kohmatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cut_as_utils(t_list *stack_b, t_list *stack_a, int size)
{
	int	i;
	int	flag;

	i = 0;
	if (sort_check(stack_b))
	{
		while (size != 3)
		{
			while (stack_b->next->order != i)
			{
				flag = rotation_flag(stack_b, size, i);
				if (flag == R)
					rb(stack_b);
				else
					rrb(stack_b);
			}
			pa(stack_b, stack_a);
			ra(stack_a);
			i++;
			size--;
		}
		sort_stack_b_under_3(stack_b, stack_a);
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*first;
	char	*last;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return ((char *)s1);
	first = (char *)s1;
	last = (char *)(s1 + ft_strlen(s1) - 1);
	while (*first && ft_strchr(set, *first))
			first++;
	while (last != first && ft_strchr(set, *last))
			last--;
	return (ft_substr(s1, (first - s1), (last - first + 1)));
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ans;

	ans = (char *)s;
	while (*ans != (char)c)
	{
		if (*ans == '\0')
			return (0);
		ans++;
	}
	return (ans);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	tmp;

	tmp = len;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_calloc(1, 1));
	if (ft_strlen(s + start) < len)
		tmp = ft_strlen(s + start);
	ret = (char *)malloc(sizeof(char) * (tmp + 1));
	if (!ret)
		return (0);
	ft_strlcpy(ret, s + start, tmp + 1);
	return (ret);
}
