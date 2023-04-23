/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohmatsu <kohmatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:46:27 by kohmatsu          #+#    #+#             */
/*   Updated: 2022/12/26 18:36:47 by kohmatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *stack_a)
{
	t_list	*p1;
	t_list	*p2;
	t_list	*p3;
	t_list	*p_prev;
	t_list	*p_next;

	p1 = stack_a->next;
	p2 = stack_a->next->next;
	p3 = stack_a->next->next->next;
	p_prev = p1->prev;
	p_next = p2->next;
	p1->next = p_next;
	p1->prev = p2;
	p2->next = p1;
	p2->prev = p_prev;
	p_prev->next = p2;
	p3->prev = p1;
	write(1, "sa\n", 3);
}

void	sb(t_list *stack_b)
{
	t_list	*p1;
	t_list	*p2;
	t_list	*p3;
	t_list	*p_prev;
	t_list	*p_next;

	p1 = stack_b->next;
	p2 = stack_b->next->next;
	p3 = stack_b->next->next->next;
	p_prev = p1->prev;
	p_next = p2->next;
	p1->next = p_next;
	p1->prev = p2;
	p2->next = p1;
	p2->prev = p_prev;
	p_prev->next = p2;
	p3->prev = p1;
	write(1, "sb\n", 3);
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
}

void	pb(t_list *stack_a, t_list *stack_b)
{
	t_list	*next;

	next = stack_a->next;
	insert(stack_b, lstnew(stack_b, next->num, next->order, next->sort_flag));
	lstdelone(stack_a);
	write(1, "pb\n", 3);
}

void	pa(t_list *stack_b, t_list *stack_a)
{
	t_list	*next;

	next = stack_b->next;
	insert(stack_a, lstnew(stack_a, next->num, next->order, next->sort_flag));
	lstdelone(stack_b);
	write(1, "pa\n", 3);
}
