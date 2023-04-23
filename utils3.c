/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohmatsu <kohmatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 23:01:50 by kohmatsu          #+#    #+#             */
/*   Updated: 2022/12/28 11:15:31 by kohmatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include <stdio.h>

void	binary(int low, int high, int *num, t_list *stack_a)
{
	int	mid;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (num[mid] == stack_a->num)
		{
			stack_a->order = mid;
			break ;
		}
		else if (num[mid] < stack_a->num)
			low = mid + 1;
		else
			high = mid - 1;
	}
}

int	lstsize(t_list *list)
{
	int		count;
	t_list	*tmp;

	count = 0;
	tmp = list;
	list = list->next;
	while (list != tmp)
	{
		count++;
		list = list->next;
	}
	return (count);
}

int	return_proper_num(int argc)
{
		argc /= 2;
	return (argc);
}

int	sort_check(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	list = list->next;
	while (list->next != tmp)
	{
		if (list->num > list->next->num)
			return (1);
		list = list->next;
	}
	return (0);
}

void	sort_stack_a(t_list *stack_a, t_list *stack_b)
{
	int	size;

	size = lstsize(stack_a);
	if (size <= 3)
	{
		if (size == 2)
		{
			if (stack_a->next->order > stack_a->next->next->order)
				sa(stack_a);
		}
		else if (size == 3)
			sort_stack_a_under_3(stack_a);
	}
	else
	{
		give_order(stack_a, size, stack_a, stack_b);
		sort_stack_a_under_6(stack_a, stack_b, size);
	}
}
