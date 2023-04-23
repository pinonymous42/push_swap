/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kohmatsu <kohmatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:42:12 by kohmatsu          #+#    #+#             */
/*   Updated: 2022/12/28 11:12:59 by kohmatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERROR 1
# define FINISH 0
# define INIT -1
# define R 1
# define RR 0

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	long			num;
	int				order;
	int				sort_flag;
	struct s_list	*next;
	struct s_list	*prev;
}t_list;

long	ft_atoi(const char *str);
void	check_list(t_list *list, char *str);
void	lstfree(t_list *list);
t_list	*lstnew(t_list *list, long num, int order, int sort_flag);
void	addback(t_list *list, t_list *new);
void	insert(t_list *p_prev, t_list *p);
void	lstdelone(t_list *list);
void	swap(int *a, int *b);
void	quick_sort(int *num, int left, int right);
void	find_order(int *num, int i, t_list *stack_a);
void	binary(int low, int high, int *num, t_list *stack_a);
int		lstsize(t_list *list);
int		return_proper_num(int argc);
int		sort_check(t_list *list);
void	sort_stack_a(t_list *stack_a, t_list *stack_b);
void	sort_stack_a_under_3(t_list *stack_a);
void	judge_sort(t_list *list, int *sort);
void	give_order(t_list *list, int argc, t_list *stack_a, t_list *stack_b);
void	sort_stack_a_under_6(t_list *stack_a, t_list *stack_b, int size);
void	sort_stack_b(t_list *stack_a, t_list *stack_b);
void	sort_stack_b_under_3(t_list *stack_b, t_list *stack_a);
void	sort_stack_b_under_6(t_list *stack_b, t_list *stack_a, int size);
int		rotation_flag(t_list *list, int size, int num);
void	utils_stack_a(t_list *stack_a, int *sort);
void	utils_stack_b(t_list *stack_b, int *sort);
void	cut_as_utils(t_list *stack_b, t_list *stack_a, int size);
char	*ft_strtrim(char const *s1, char const *set);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
int		count_sep(char const *s, char c);
int		check(char **ans, size_t i);
char	**do_it(const char *s, char c, char **ans, size_t i);
void	finish(char **argv, int *argc);
int		str_check(char *str);
void	sa(t_list *stack_a);
void	sb(t_list *stack_b);
void	ss(t_list *stack_a, t_list *stack_b);
void	pb(t_list *stack_a, t_list *stack_b);
void	pa(t_list *stack_b, t_list *stack_a);
void	ra(t_list *stack_a);
void	rb(t_list *stack_b);
void	rr(t_list *stack_a, t_list *stack_b);
void	rra(t_list *stack_a);
void	rrb(t_list *stack_b);
void	rrr(t_list *stack_a, t_list *stack_b);

#endif