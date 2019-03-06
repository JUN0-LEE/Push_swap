/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 10:42:27 by julee             #+#    #+#             */
/*   Updated: 2019/03/02 01:37:52 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_val(struct s_deq *a, char *op)
{
	int		tmp;

	if (a->first == NULL || a->first->next == NULL)
		return ;
	tmp = a->first->val;
	a->first->val = a->first->next->val;
	a->first->next->val = tmp;
	ft_putendl(op);
}

void	push_val(struct s_deq *src, struct s_deq *dest, char *op)
{
	int		val;

	if (is_empty(src))
		return ;
	val = deq_pop_front(src);
	deq_add_front(dest, val);
	ft_putendl(op);
}

void	rotate_val(struct s_deq *a, char *op)
{
	int val;

	if (is_empty(a))
		return ;
	val = deq_pop_front(a);
	deq_add_back(a, val);
	if (ft_strcmp(op, "rr"))
		ft_putendl(op);
}

void	rotate_both(struct s_deq *a, struct s_deq *b)
{
	rotate_val(a, "rr");
	rotate_val(b, "rr");
	ft_putendl("rr");
}

void	reverse_rotate_val(struct s_deq *a, char *op)
{
	int val;

	if (is_empty(a))
		return ;
	val = deq_pop_back(a);
	deq_add_front(a, val);
	ft_putendl(op);
}
