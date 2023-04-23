/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohmatsu <kohmatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:44:50 by kohmatsu          #+#    #+#             */
/*   Updated: 2022/12/26 18:35:47 by kohmatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include <stdio.h>

void	sort_stack_a_under_3(t_list *stack_a)
{
	int	*sort;

	sort = malloc(sizeof(int) * 3);
	if (sort_check(stack_a))
	{
		judge_sort(stack_a, sort);
		utils_stack_a(stack_a, sort);
	}
	free(sort);
}

void	judge_sort(t_list *list, int *sort)
{
	sort[0] = 0;
	sort[1] = 0;
	sort[2] = 0;
	if (list->next->num > list->next->next->num)
		sort[0] = 1;
	if (list->next->next->num > list->next->next->next->num)
		sort[1] = 1;
	if (list->next->next->next->num > list->next->num)
		sort[2] = 1;
}

void	give_order(t_list *list, int argc, t_list *stack_a, t_list *stack_b)
{
	t_list	*tmp;
	int		i;
	int		*num;

	tmp = list;
	i = 0;
	num = malloc(sizeof(int) * argc);
	if (!num)
	{
		lstfree(stack_a);
		lstfree(stack_b);
		exit(ERROR);
	}
	list = list->next;
	while (list != tmp)
	{
		num[i] = list->num;
		i++;
		list = list->next;
	}
	quick_sort(num, 0, i - 1);
	find_order(num, i, tmp);
	free(num);
}

void	sort_stack_a_under_6(t_list *stack_a, t_list *stack_b, int size)
{
	int	i;
	int	flag;

	i = 0;
	if (sort_check(stack_a))
	{
		while (size != 3)
		{
			while (stack_a->next->order != i)
			{
				flag = rotation_flag(stack_a, size, i);
				if (flag == R)
					ra(stack_a);
				else
					rra(stack_a);
			}
			pb(stack_a, stack_b);
			i++;
			size--;
		}
		sort_stack_a_under_3(stack_a);
		while (lstsize(stack_b) != 0)
			pa(stack_b, stack_a);
	}
}

void	sort_stack_b(t_list *stack_a, t_list *stack_b)
{
	int	size;

	size = lstsize(stack_b);
	if (size <= 3)
	{
		if (size == 2)
		{
			if (stack_b->next->order > stack_b->next->next->order)
				sb(stack_b);
		}
		else if (size == 3)
			sort_stack_b_under_3(stack_b, stack_a);
	}
	else
	{
		give_order(stack_b, size, stack_a, stack_b);
		sort_stack_b_under_6(stack_b, stack_a, size);
	}
}
