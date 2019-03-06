/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 13:10:20 by julee             #+#    #+#             */
/*   Updated: 2019/02/27 22:51:35 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int				peek_front(struct s_deq *deq)
{
	int		val;

	val = deq->first->val;
	return (val);
}

int				peek_back(struct s_deq *deq)
{
	int		val;

	val = deq->last->val;
	return (val);
}

int				is_empty(struct s_deq *deq)
{
	if (deq->first == NULL)
		return (1);
	return (0);
}
