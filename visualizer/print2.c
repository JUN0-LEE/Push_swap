/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 23:46:51 by julee             #+#    #+#             */
/*   Updated: 2019/02/28 00:23:41 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_upper(struct s_deq *a, struct s_deq *b)
{
	int		alen;
	int		blen;
	int		len;
	int		i;

	alen = deq_len(a);
	blen = deq_len(b);
	len = alen + blen;
	i = -1;
	while (++i < len - max_val(alen, blen))
		printf("\n");
}

void	print_middle_a(struct s_deq *a, struct s_deq *b
		, int width, struct s_node **tmpa)
{
	int		alen;
	int		blen;
	int		i;
	int		j;

	alen = deq_len(a);
	blen = deq_len(b);
	(*tmpa) = a->first;
	i = -1;
	while (++i < alen - blen)
	{
		printf("%*s", pad_cal(width, (*tmpa)->val), "");
		j = -1;
		while (++j < (*tmpa)->val)
			printf("-");
		printf("\n");
		(*tmpa) = (*tmpa)->next;
	}
}

void	print_middle_b(struct s_deq *a, struct s_deq *b
		, int width, struct s_node **tmpb)
{
	int		alen;
	int		blen;
	int		i;
	int		j;

	alen = deq_len(a);
	blen = deq_len(b);
	(*tmpb) = b->first;
	i = -1;
	while (++i < blen - alen)
	{
		printf("%*s", width, "");
		printf("%*s", pad_cal(width, (*tmpb)->val), "");
		j = -1;
		while (++j < (*tmpb)->val)
			printf("-");
		printf("\n");
		(*tmpb) = (*tmpb)->next;
	}
}

void	print_bottom_a(int width, struct s_node *tmpa)
{
	int		i;

	printf("%*s", pad_cal(width, tmpa->val), "");
	i = -1;
	while (++i < tmpa->val)
		printf("-");
	printf("%*s", pad_cal(width, tmpa->val), "");
}

void	print_bottom_b(int width, struct s_node *tmpb)
{
	int		i;

	printf("%*s", pad_cal(width, tmpb->val), "");
	i = -1;
	while (++i < tmpb->val)
		printf("-");
	printf("%*s", pad_cal(width, tmpb->val), "");
	printf("\n");
}
