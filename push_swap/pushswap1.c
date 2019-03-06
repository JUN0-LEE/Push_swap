/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 12:05:19 by julee             #+#    #+#             */
/*   Updated: 2019/03/02 00:11:47 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_stack_a_arr(struct s_deq *a, struct s_deq *b
		, struct s_lst *iden, int *count)
{
	push_val(a, b, "pb");
	if (a->first)
	{
		if (!(which_group(a->first, iden) == 'a' ||
			which_group(a->first, iden) == 'd') && (*count) - 1 != 0)
		{
			rotate_both(a, b);
			(*count)--;
		}
		else
			rotate_val(b, "rb");
	}
	else
		rotate_val(b, "rb");
}

void	sort_stack_a_ad(struct s_deq *a, struct s_deq *b
		, struct s_lst *iden, int pushcount)
{
	int		len;
	int		count;

	len = deq_len(a) + deq_len(b);
	count = len - pushcount;
	while (count > 0)
	{
		if (which_group(a->first, iden) == 'a')
			sort_stack_a_arr(a, b, iden, &count);
		else if (which_group(a->first, iden) == 'd')
			push_val(a, b, "pb");
		else
			rotate_val(a, "ra");
		count--;
	}
}

void	sort_stack_a_brr(struct s_deq *a, struct s_deq *b
		, struct s_lst *iden, int *count)
{
	push_val(a, b, "pb");
	if (a->first)
	{
		if (!(which_group(a->first, iden) == 'b' ||
			which_group(a->first, iden) == 'c') && (*count) - 1 != 0)
		{
			rotate_both(a, b);
			(*count)--;
		}
		else
			rotate_val(b, "rb");
	}
	else
		rotate_val(b, "rb");
}

void	sort_stack_a(struct s_deq *a, struct s_deq *b, struct s_lst *iden)
{
	int		count;
	int		pushcount;

	count = deq_len(a);
	pushcount = 0;
	while (count > 0)
	{
		if (which_group(a->first, iden) == 'b')
		{
			pushcount++;
			sort_stack_a_brr(a, b, iden, &count);
		}
		else if (which_group(a->first, iden) == 'c')
		{
			push_val(a, b, "pb");
			pushcount++;
		}
		else
			rotate_val(a, "ra");
		count--;
	}
	sort_stack_a_ad(a, b, iden, pushcount);
	while (is_empty(a) == 0)
		push_val(a, b, "pb");
}

void	make_stack(int size, char **input)
{
	struct s_deq	*a;
	struct s_deq	*b;
	int				*tab;
	struct s_lst	*new;
	int				i;

	a = deq_init();
	b = deq_init();
	tab = (int *)malloc(sizeof(int) * size);
	i = -1;
	while (++i < size)
		deq_add_back(a, ft_atoi(input[i]));
	if (is_sorted(a) == 1)
		return ;
	i = -1;
	while (++i < size)
		tab[i] = ft_atoi(input[i]);
	merge_sort(tab, 0, size - 1);
	new = make_list(tab, size, 1);
	sort_stack(a, b, new, size);
	freer(a, b, tab, new);
	return ;
}
