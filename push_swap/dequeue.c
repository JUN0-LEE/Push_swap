/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:51:14 by julee             #+#    #+#             */
/*   Updated: 2019/02/21 18:24:42 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

struct s_deq	*deq_init(void)
{
	struct s_deq	*new;

	new = (struct s_deq *)malloc(sizeof(struct s_deq));
	if (new == NULL)
		return (NULL);
	new->first = NULL;
	new->last = NULL;
	return (new);
}

int				deq_pop_front(struct s_deq *deq)
{
	struct s_node	*item;
	int				val;

	item = deq->first;
	deq->first = item->next;
	val = item->val;
	free(item);
	if (deq->first)
		deq->first->prev = NULL;
	else
		deq->last = NULL;
	return (val);
}

int				deq_pop_back(struct s_deq *deq)
{
	struct s_node	*item;
	int				val;

	item = deq->last;
	deq->last = item->prev;
	val = item->val;
	free(item);
	if (deq->last)
		deq->last->next = NULL;
	else
		deq->first = NULL;
	return (val);
}

void			deq_add_back(struct s_deq *deq, int val)
{
	struct s_node	*new;

	new = (struct s_node *)malloc(sizeof(struct s_node));
	new->val = val;
	new->next = NULL;
	new->prev = NULL;
	if (is_empty(deq) == 1)
		deq->first = new;
	else
	{
		new->prev = deq->last;
		deq->last->next = new;
	}
	deq->last = new;
}

void			deq_add_front(struct s_deq *deq, int val)
{
	struct s_node	*new;

	new = (struct s_node *)malloc(sizeof(struct s_node));
	new->val = val;
	new->next = NULL;
	new->prev = NULL;
	if (is_empty(deq) == 1)
		deq->last = new;
	else
	{
		new->next = deq->first;
		deq->first->prev = new;
	}
	deq->first = new;
}
