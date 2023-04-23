/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohmatsu <kohmatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:52:06 by kohmatsu          #+#    #+#             */
/*   Updated: 2022/12/27 15:42:17 by kohmatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*domain;

	if (count == 0 || size == 0)
		return (ft_calloc(1, 1));
	if (SIZE_MAX / size < count)
		return (NULL);
	else
	{
		domain = malloc(count * size);
		if (!domain)
			return (NULL);
		ft_bzero(domain, (count * size));
		return (domain);
	}
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	s_len;
	size_t	i;

	i = 0;
	s_len = ft_strlen(src);
	if (dstsize == 0)
		return (s_len);
	while (src[i] && i < (dstsize - 1))
	{
		*dst = src[i];
		dst++;
		i++;
	}
	*dst = '\0';
	return (s_len);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ans;

	ans = (unsigned char *)b;
	while (len--)
	{
		*ans = (unsigned char)c;
		ans++;
	}
	return (b);
}

void	finish(char **argv, int *argc)
{
	char	**argv_tmp;
	int		j;

	j = 1;
	if (ft_strchr(argv[1], ' '))
	{
		if (*argc != 2)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		*argc += count_sep(argv[1], ' ') - 1;
		argv_tmp = (char **)malloc(sizeof(char *) * (*argc - 1));
		if (!argv_tmp)
			exit(ERROR);
		do_it(argv[1], ' ', argv_tmp, 0);
		while (j < *argc)
		{
			argv[j] = argv_tmp[j - 1];
			j++;
		}
		free(argv_tmp);
	}
}
