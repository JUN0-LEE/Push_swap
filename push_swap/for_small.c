/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_small.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 14:53:34 by julee             #+#    #+#             */
/*   Updated: 2019/03/03 18:49:43 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		is_right_order(struct s_deq *a)
{
	if (a->first->val < a->first->next->val)
		return (1);
	return (0);
}

void	for_3(struct s_deq *a)
{
	while (is_sorted(a) == 0)
	{
		if (is_right_order(a) == 0)
			swap_val(a, "sa");
		else
			reverse_rotate_val(a, "rra");
	}
}

int		find_smallest(struct s_deq *a)
{
	struct s_node	*tmp;
	int				index;
	int				i;
	int				min;

	tmp = a->first;
	min = tmp->val;
	index = 0;
	i = 0;
	while (tmp)
	{
		if (min > tmp->val)
		{
			min = tmp->val;
			index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (index);
}

void	sort_small_first(struct s_deq *a, struct s_deq *b, int pushcount)
{
	int		seq;
	int		len;

	len = deq_len(a);
	while (pushcount > 0)
	{
		seq = find_smallest(a);
		if (seq <= len / 2)
			while (seq--)
				rotate_val(a, "ra");
		else
		{
			seq = deq_len(a) - seq;
			while (seq--)
				reverse_rotate_val(a, "rra");
		}
		push_val(a, b, "pb");
		pushcount--;
	}
	for_3(a);
	while (is_empty(b) == 0)
		push_val(b, a, "pa");
}

void	make_stack1(int size, char **input)
{
	struct s_deq	*a;
	struct s_deq	*b;
	int				i;

	if (size == 1)
		return ;
	a = deq_init();
	b = deq_init();
	i = -1;
	while (++i < size)
		deq_add_back(a, ft_atoi(input[i]));
	if (is_sorted(a))
		return ;
	if (size <= 3)
		for_3(a);
	else
		sort_small_first(a, b, size - 3);
	freer(a, b, 0, 0);
}
