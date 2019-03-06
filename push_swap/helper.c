/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:03:00 by julee             #+#    #+#             */
/*   Updated: 2019/03/02 00:11:15 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		is_sorted(struct s_deq *a)
{
	struct s_node *tmp;

	tmp = a->first;
	while (tmp->next)
	{
		if (tmp->val > tmp->next->val)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		log_5(int n)
{
	int count;
	int	a;
	int	b;

	a = 1;
	b = 5;
	if (n == 1)
		return (1);
	count = 1;
	while (!(a < n && n <= b))
	{
		a *= 5;
		b *= 5;
		count++;
	}
	return (count);
}

int		log_4(int n)
{
	int count;
	int	a;
	int	b;

	a = 1;
	b = 4;
	if (n == 1)
		return (1);
	count = 1;
	while (!(a < n && n <= b))
	{
		a *= 4;
		b *= 4;
		count++;
	}
	return (count);
}

char	which_group(struct s_node *node, struct s_lst *iden)
{
	int				val;
	struct s_lst	*tmp;

	if (node == NULL)
		ft_putstr("NULL");
	val = node->val;
	tmp = iden;
	while (tmp)
	{
		if (val == tmp->val)
			return (tmp->group);
		tmp = tmp->next;
	}
	return ('?');
}

int		power_of_5(int n)
{
	int		res;

	res = 1;
	while (--n)
		res *= 5;
	return (res);
}
