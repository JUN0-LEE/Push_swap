/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:46:34 by julee             #+#    #+#             */
/*   Updated: 2019/02/27 23:00:52 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		pad_cal(int width, int val)
{
	return ((width - val) / 2);
}

void	stack_visualizer(struct s_deq *a, struct s_deq *b, int width)
{
	struct s_node	*tmpa;
	struct s_node	*tmpb;
	int				i;

	tmpa = NULL;
	tmpb = NULL;
	print_upper(a, b);
	if (deq_len(a) > deq_len(b))
		print_middle_a(a, b, width, &tmpa);
	else
		print_middle_b(a, b, width, &tmpb);
	if (tmpa == NULL)
		tmpa = a->first;
	if (tmpb == NULL)
		tmpb = b->first;
	i = -1;
	while (++i < min_val(deq_len(a), deq_len(b)))
	{
		print_bottom_a(width, tmpa);
		tmpa = tmpa->next;
		print_bottom_b(width, tmpb);
		tmpb = tmpb->next;
	}
}
