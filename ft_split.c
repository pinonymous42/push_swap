/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohmatsu <kohmatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:31:07 by kohmatsu          #+#    #+#             */
/*   Updated: 2022/12/27 15:24:17 by kohmatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include <stdio.h>

int	count_sep(char const *s, char c)
{
	int	amount;
	int	count;

	amount = 0;
	count = 0;
	while (*s)
	{
		if (*s == c)
		{
			if (amount != 0)
				count++;
			amount = 0;
		}
		else
			amount++;
		s++;
	}
	if (amount != 0)
		return (count + 1);
	return (count);
}

int	check(char **ans, size_t i)
{
	if (ans[i] == NULL)
	{
		while (i >= 0)
		{
			free(ans[i]);
			i--;
		}
		free(ans);
		return (0);
	}
	return (1);
}

char	**do_it(const char *s, char c, char **ans, size_t i)
{
	size_t	len;

	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			len = 0;
			while (*s && *s != c)
			{
				len++;
				s++;
			}
			ans[i] = ft_substr(s - len, 0, len);
			if (!check(ans, i))
				return (NULL);
			i++;
		}
	}
	ans[i] = NULL;
	return (ans);
}
