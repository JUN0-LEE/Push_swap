/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 13:30:09 by julee             #+#    #+#             */
/*   Updated: 2019/03/03 19:15:00 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		find_biggest_val(struct s_deq *a)
{
	struct s_node	*tmp;
	int				max;

	tmp = a->first;
	max = tmp->val;
	while (tmp)
	{
		if (max < tmp->val)
			max = tmp->val;
		tmp = tmp->next;
	}
	return (max);
}

void	make_stack(int size, char **input, int fd)
{
	struct s_deq	*a;
	struct s_deq	*b;
	int				i;
	int				width;

	a = deq_init();
	b = deq_init();
	i = -1;
	while (++i < size)
		deq_add_back(a, atoi(input[i]));
	width = find_biggest_val(a);
	stack_visualizer(a, b, width + 1);
	read_input(a, b, width + 1, fd);
	return ;
}

int		max_val(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int		min_val(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int		find_biggest(struct s_deq *deq)
{
	struct s_node	*tmp;
	int				max;

	tmp = deq->first;
	max = tmp->val;
	while (tmp)
	{
		if (max < tmp->val)
			max = tmp->val;
		tmp = tmp->next;
	}
	return (max);
}
