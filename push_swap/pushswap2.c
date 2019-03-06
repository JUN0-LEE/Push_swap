/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 12:05:26 by julee             #+#    #+#             */
/*   Updated: 2019/03/02 00:15:35 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_stack_b_err(struct s_deq *a, struct s_deq *b
		, struct s_lst *iden, int *count)
{
	push_val(b, a, "pa");
	if (a->first)
	{
		if (!(which_group(b->first, iden) == 'b' ||
					which_group(b->first, iden) == 'e') && (*count) - 1 != 0)
		{
			rotate_both(a, b);
			(*count)--;
		}
		else
			rotate_val(a, "ra");
	}
	else
		rotate_val(a, "ra");
}

void	sort_stack_b_ad(struct s_deq *a, struct s_deq *b
		, struct s_lst *iden, int pushcount)
{
	int		len;
	int		count;

	len = deq_len(a) + deq_len(b);
	count = len - pushcount;
	while (count > 0)
	{
		if (which_group(b->first, iden) == 'e')
			sort_stack_b_err(a, b, iden, &count);
		else if (which_group(b->first, iden) == 'b')
			push_val(b, a, "pa");
		else
			rotate_val(b, "rb");
		count--;
	}
}

void	sort_stack_b_drr(struct s_deq *a, struct s_deq *b
		, struct s_lst *iden, int *count)
{
	push_val(b, a, "pa");
	if (a->first)
	{
		if (!(which_group(b->first, iden) == 'c' ||
					which_group(b->first, iden) == 'd') && (*count) - 1 != 0)
		{
			rotate_both(a, b);
			(*count)--;
		}
		else
			rotate_val(a, "ra");
	}
	else
		rotate_val(a, "ra");
}

void	sort_stack_b(struct s_deq *a, struct s_deq *b, struct s_lst *iden)
{
	int		count;
	int		pushcount;

	count = deq_len(b);
	pushcount = 0;
	while (count > 0)
	{
		if (which_group(b->first, iden) == 'c')
		{
			push_val(b, a, "pa");
			pushcount++;
		}
		else if (which_group(b->first, iden) == 'd')
		{
			pushcount++;
			sort_stack_b_drr(a, b, iden, &count);
		}
		else
			rotate_val(b, "rb");
		count--;
	}
	sort_stack_b_ad(a, b, iden, pushcount);
	while (is_empty(b) == 0)
		push_val(b, a, "pa");
}

void	sort_stack(struct s_deq *a, struct s_deq *b
		, struct s_lst *iden, int len)
{
	int				width;
	int				step;
	int				i;
	struct s_vec	*group;

	width = 1;
	step = log_5(len);
	i = 0;
	group = vec_alloc(len, log_5(len));
	set_group_vec(group);
	while (width < len && i < step)
	{
		if (125 < len && len <= 625)
			copy_group(iden, group, i++);
		else if (25 < len && len <= 125)
			set_list(iden, width, i++ % 2);
		if (is_empty(b))
			sort_stack_a(a, b, iden);
		else if (is_empty(a))
			sort_stack_b(a, b, iden);
		width *= 5;
	}
	while (is_empty(b) == 0)
		push_val(b, a, "pa");
	vec_free(group);
}
