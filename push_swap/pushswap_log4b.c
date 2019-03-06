/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_log4b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 22:08:52 by julee             #+#    #+#             */
/*   Updated: 2019/02/27 22:44:41 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_stack_b_ad2(struct s_deq *a, struct s_deq *b
		, struct s_lst *iden, int pushcount)
{
	int		len;
	int		count;

	len = deq_len(a) + deq_len(b);
	count = len - pushcount;
	while (count--)
	{
		if (which_group(b->first, iden) == 'a')
			push_val(b, a, "pa");
		else
		{
			push_val(b, a, "pa");
			rotate_val(a, "ra");
		}
	}
}

void	sort_stack_b_opt2(struct s_deq *a, struct s_deq *b
		, struct s_lst *iden, int *count)
{
	push_val(b, a, "pa");
	if (a->first)
	{
		if ((which_group(b->first, iden) == 'a' ||
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

void	sort_stack_b2(struct s_deq *a, struct s_deq *b, struct s_lst *iden)
{
	int		count;
	int		pushcount;

	count = deq_len(b);
	pushcount = 0;
	while (count > 0)
	{
		if (which_group(b->first, iden) == 'a')
			rotate_val(b, "rb");
		else if (which_group(b->first, iden) == 'b')
		{
			push_val(b, a, "pa");
			pushcount++;
		}
		else if (which_group(b->first, iden) == 'c')
		{
			pushcount++;
			sort_stack_b_opt2(a, b, iden, &count);
		}
		else if (which_group(b->first, iden) == 'd')
			rotate_val(b, "rb");
		count--;
	}
	sort_stack_b_ad2(a, b, iden, pushcount);
}
