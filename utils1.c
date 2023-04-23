/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohmatsu <kohmatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:55:09 by kohmatsu          #+#    #+#             */
/*   Updated: 2022/12/28 11:14:07 by kohmatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include <stdio.h>

long	ft_atoi(const char *str)
{
	int		minus;
	long	i;

	minus = 1;
	i = 0;
	while (('\t' <= *str && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		i = i * 10 + (*str - '0');
		str++;
	}
	if (i * minus < INT_MIN || INT_MAX < i * minus)
	{
		write(2, "Error\n", 6);
		exit(ERROR);
	}
	return (i * minus);
}

void	check_list(t_list *list, char *str)
{
	int		num;
	t_list	*tmp;

	if (str_check(str))
	{
		write(2, "Error\n", 6);
		exit(ERROR);
	}
	num = ft_atoi(str);
	tmp = list;
	list = list->next;
	while (list != tmp)
	{
		if (list->num == num)
		{
			write(2, "Error\n", 6);
			exit(ERROR);
		}
		list = list->next;
	}
}

void	lstfree(t_list *list)
{
	t_list	*tmp;
	t_list	*stop;

	stop = list;
	list = list->next;
	while (list->next != stop)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	free(list);
	list = NULL;
}

t_list	*lstnew(t_list *list, long num, int order, int sort_flag)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
	{
		lstfree(list);
		exit(ERROR);
	}
	new->num = num;
	new->order = order;
	new->sort_flag = sort_flag;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	addback(t_list *list, t_list *new)
{
	t_list	*tmp;

	tmp = list;
	list = list->next;
	while (list->next != tmp)
		list = list->next;
	insert(list, new);
}
