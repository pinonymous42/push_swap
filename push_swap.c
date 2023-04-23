/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohmatsu <kohmatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:42:11 by kohmatsu          #+#    #+#             */
/*   Updated: 2022/12/30 12:25:35 by kohmatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	exclude_from_b(t_list *stack_a, t_list *stack_b, int argc, int flag)
{
	int			count;
	int			size;

	count = 0;
	size = lstsize(stack_b);
	if (stack_a->next->sort_flag == flag)
		flag++;
	while (count < argc)
	{
		if (stack_b->next->order > size - argc - 1)
		{
			pa(stack_b, stack_a);
			stack_a->next->sort_flag = flag;
			count++;
		}
		else
			rb(stack_b);
	}
}

static void	loop(t_list *stack_a, t_list *stack_b)
{
	int	stopper;
	int	size;

	while (sort_check(stack_a) != 0 || stack_a->next->sort_flag != 1)
	{
		stopper = stack_a->next->sort_flag;
		while (stack_a->next->sort_flag == stopper)
		{
			pb(stack_a, stack_b);
		}
		give_order(stack_b, lstsize(stack_b), stack_a, stack_b);
		size = lstsize(stack_b);
		while (size > 18)
		{
			size = return_proper_num(size);
			exclude_from_b(stack_a, stack_b, size, stopper + 1);
			size = lstsize(stack_b);
		}
		sort_stack_b(stack_a, stack_b);
	}
}

static void	start_sort(t_list *stack_a, t_list *stack_b, int argc)
{
	int	count;
	int	flag;

	count = 0;
	flag = 1;
	argc = return_proper_num(argc);
	while (count < argc)
	{
		if (stack_a->next->order < argc)
		{
			pb(stack_a, stack_b);
			stack_b->next->sort_flag = flag;
			count++;
		}
		else
			ra(stack_a);
	}
	while (lstsize(stack_b) > 18)
	{
		flag++;
		argc = return_proper_num(argc);
		exclude_from_b(stack_a, stack_b, argc, flag);
	}
}

static void	beforehand(t_list *stack_a, t_list *stack_b, int argc)
{
	give_order(stack_a, argc - 1, stack_a, stack_b);
	if (lstsize(stack_a) > 18)
	{
		start_sort(stack_a, stack_b, argc - 1);
		sort_stack_b(stack_a, stack_b);
		loop(stack_a, stack_b);
	}
	else
		sort_stack_a(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*stack_a;
	t_list	head_a;
	t_list	*stack_b;
	t_list	head_b;

	if (argc == 1)
		return (ERROR);
	i = 1;
	stack_a = &head_a;
	stack_a->next = stack_a;
	stack_a->prev = stack_a;
	stack_b = &head_b;
	stack_b->next = stack_b;
	stack_b->prev = stack_b;
	finish(argv, &argc);
	while (i < argc)
	{
		check_list(&head_a, argv[i]);
		addback(&head_a, lstnew(&head_a, ft_atoi(argv[i++]), 0, 0));
	}
	if (sort_check(stack_a))
		beforehand(stack_a, stack_b, argc);
	lstfree(stack_a);
	return (FINISH);
}
