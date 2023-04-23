/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohmatsu <kohmatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:52:52 by kohmatsu          #+#    #+#             */
/*   Updated: 2022/12/26 18:35:39 by kohmatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include <stdio.h>

void	sort_stack_b_under_3(t_list *stack_b, t_list *stack_a)
{
	int	*sort;
	int	i;

	i = 0;
	sort = malloc(sizeof(int) * 3);
	if (sort_check(stack_b))
	{
		judge_sort(stack_b, sort);
		utils_stack_b(stack_b, sort);
	}
	while (lstsize(stack_b) != 0)
	{
		pa(stack_b, stack_a);
		ra(stack_a);
	}
	free(sort);
}

void	sort_stack_b_under_6(t_list *stack_b, t_list *stack_a, int size)
{
	cut_as_utils(stack_b, stack_a, size);
	while (lstsize(stack_b) != 0)
	{
		pa(stack_b, stack_a);
		ra(stack_a);
	}
}

int	rotation_flag(t_list *list, int size, int num)
{
	int	i;

	i = 0;
	list = list->next;
	while (i < return_proper_num(size))
	{
		if (list->order == num)
			return (R);
		i++;
		list = list->next;
	}
	return (RR);
}

void	utils_stack_a(t_list *stack_a, int *sort)
{
	if (sort[0] == 1)
	{
		if (sort[1] == 0)
		{
			if (sort[2] == 1)
				sa(stack_a);
			else
				ra(stack_a);
		}
		else
		{
			sa(stack_a);
			rra(stack_a);
		}
	}
	else
	{
		if (sort[2] == 1)
		{
			sa(stack_a);
			ra(stack_a);
		}
		else
			rra(stack_a);
	}
}

void	utils_stack_b(t_list *stack_b, int *sort)
{
	if (sort[0] == 1)
	{
		if (sort[1] == 0)
		{
			if (sort[2] == 1)
				sb(stack_b);
			else
				rb(stack_b);
		}
		else
		{
			sb(stack_b);
			rrb(stack_b);
		}
	}
	else
	{
		if (sort[2] == 1)
		{
			sb(stack_b);
			rb(stack_b);
		}
		else
			rrb(stack_b);
	}
}
