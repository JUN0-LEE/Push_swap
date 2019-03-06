/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_log4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 22:03:31 by julee             #+#    #+#             */
/*   Updated: 2019/02/27 22:44:29 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_stack_a_ad2(struct s_deq *a, struct s_deq *b
		, struct s_lst *iden, int pushcount)
{
	int		len;
	int		count;

	len = deq_len(a) + deq_len(b);
	count = len - pushcount;
	while (count--)
	{
		if (which_group(a->first, iden) == 'a')
		{
			push_val(a, b, "pb");
			rotate_val(b, "rb");
		}
		else
			push_val(a, b, "pb");
	}
}

void	sort_stack_a_opt2(struct s_deq *a, struct s_deq *b
		, struct s_lst *iden, int *count)
{
	push_val(a, b, "pb");
	if (a->first)
	{
		if ((which_group(a->first, iden) == 'a' ||
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

void	sort_stack_a2(struct s_deq *a, struct s_deq *b, struct s_lst *iden)
{
	int		count;
	int		pushcount;

	count = deq_len(a);
	pushcount = 0;
	while (count > 0)
	{
		if (which_group(a->first, iden) == 'a')
			rotate_val(a, "ra");
		else if (which_group(a->first, iden) == 'b')
		{
			pushcount++;
			sort_stack_a_opt2(a, b, iden, &count);
		}
		else if (which_group(a->first, iden) == 'c')
		{
			push_val(a, b, "pb");
			pushcount++;
		}
		else if (which_group(a->first, iden) == 'd')
			rotate_val(a, "ra");
		count--;
	}
	sort_stack_a_ad2(a, b, iden, pushcount);
}
