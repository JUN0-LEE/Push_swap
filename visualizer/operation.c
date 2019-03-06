/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 10:42:27 by julee             #+#    #+#             */
/*   Updated: 2019/02/20 13:47:26 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_val(struct s_deq *a)
{
	int	tmp;

	if (a->first == NULL || a->first->next == NULL)
		return ;
	tmp = a->first->val;
	a->first->val = a->first->next->val;
	a->first->next->val = tmp;
}

void	push_val(struct s_deq *src, struct s_deq *dest)
{
	int		val;

	if (is_empty(src))
		return ;
	val = deq_pop_front(src);
	deq_add_front(dest, val);
}

void	rotate_val(struct s_deq *a)
{
	int val;

	if (is_empty(a))
		return ;
	val = deq_pop_front(a);
	deq_add_back(a, val);
}

void	reverse_rotate_val(struct s_deq *a)
{
	int val;

	if (is_empty(a))
		return ;
	val = deq_pop_back(a);
	deq_add_front(a, val);
}
