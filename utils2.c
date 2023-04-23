/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohmatsu <kohmatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:28:38 by kohmatsu          #+#    #+#             */
/*   Updated: 2022/12/26 18:19:53 by kohmatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include <stdio.h>

void	insert(t_list *p_prev, t_list *p)
{
	t_list	*p_next;

	p_next = p_prev->next;
	p->next = p_next;
	p->prev = p_prev;
	p_prev->next = p;
	p_next->prev = p;
}

void	lstdelone(t_list *list)
{
	t_list	*p_prev;
	t_list	*p_next;
	t_list	*p;

	p = list->next;
	p_prev = p->prev;
	p_next = p->next;
	free(p);
	p_prev->next = p_next;
	p_next->prev = p_prev;
}

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	quick_sort(int *num, int left, int right)
{
	int	pivot;
	int	i;
	int	j;

	if (left >= right)
		return ;
	pivot = num[(left + right) / 2];
	i = left;
	j = right;
	while (i <= j)
	{
		while (num[i] < pivot)
			i++;
		while (num[j] > pivot)
			j--;
		if (i <= j)
		{
			swap(&num[i], &num[j]);
			i++;
			j--;
		}
	}
	quick_sort(num, left, j);
	quick_sort(num, i, right);
}

void	find_order(int *num, int i, t_list *stack_a)
{
	t_list	*tmp;
	int		low;
	int		high;

	tmp = stack_a;
	stack_a = stack_a->next;
	while (stack_a != tmp)
	{
		low = 0;
		high = i;
		binary(low, high, num, stack_a);
		stack_a = stack_a->next;
	}
}
