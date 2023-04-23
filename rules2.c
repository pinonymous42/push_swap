/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohmatsu <kohmatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:09:51 by kohmatsu          #+#    #+#             */
/*   Updated: 2022/12/26 18:36:44 by kohmatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include <stdio.h>

void	ra(t_list *stack_a)
{
	t_list	*next;

	next = stack_a->next;
	addback(stack_a, lstnew(stack_a, next->num, next->order, next->sort_flag));
	lstdelone(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_list *stack_b)
{
	t_list	*next;

	next = stack_b->next;
	addback(stack_b, lstnew(stack_b, next->num, next->order, next->sort_flag));
	lstdelone(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_list *stack_a, t_list *stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
}

void	rra(t_list *stack_a)
{
	t_list	*last;

	last = stack_a->next;
	while (last->next != stack_a)
		last = last->next;
	insert(stack_a, lstnew(stack_a, last->num, last->order, last->sort_flag));
	last = last->prev;
	lstdelone(last);
	write(1, "rra\n", 4);
}

void	rrb(t_list *stack_b)
{
	t_list	*last;

	last = stack_b->next;
	while (last->next != stack_b)
		last = last->next;
	insert(stack_b, lstnew(stack_b, last->num, last->order, last->sort_flag));
	last = last->prev;
	lstdelone(last);
	write(1, "rrb\n", 4);
}
