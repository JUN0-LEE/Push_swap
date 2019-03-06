/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 22:24:17 by julee             #+#    #+#             */
/*   Updated: 2019/02/27 22:46:45 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void			copy_group(struct s_lst *iden, struct s_vec *group, int row)
{
	struct s_lst	*tmp;
	int				i;

	tmp = iden;
	i = 0;
	while (tmp)
	{
		tmp->group = group->elem[row][i++].group;
		tmp = tmp->next;
	}
}

void			set_first(struct s_vec *group, int width)
{
	int		row;
	int		i;

	row = group->row - 1;
	i = -1;
	while (++i < group->col)
	{
		group->elem[row][i].direction = 0;
		if ((i / width) % 5 == 0)
			group->elem[row][i].group = 'a';
		else if ((i / width) % 5 == 1)
			group->elem[row][i].group = 'b';
		else if ((i / width) % 5 == 2)
			group->elem[row][i].group = 'c';
		else if ((i / width) % 5 == 3)
			group->elem[row][i].group = 'd';
		else if ((i / width) % 5 == 4)
			group->elem[row][i].group = 'e';
	}
}

void			set_last(struct s_vec *group, int width)
{
	int		i;

	i = -1;
	while (++i < group->col)
		if (i / width == 3 || i / width == 4)
		{
			if (group->elem[0][i].direction == 0)
				put_group_reverse(group, 0, i, 1);
			else
				put_group(group, 0, i, 1);
		}
}

void			set_group_vec(struct s_vec *group)
{
	int		width;
	int		row;
	int		i;

	width = power_of_5(group->row);
	if (group->row % 2 == 0)
	{
		set_first(group, width);
		width /= 5;
		row = group->row - 1;
		i = 0;
		while (--row >= 0)
		{
			if (i % 2 == 0)
				if_next_de(group, row, width);
			else
				if_next_ab(group, row, width);
			i++;
			width /= 5;
		}
		if (group->col > 125 && group->col <= 625)
			set_last(group, power_of_5(group->row));
	}
}

struct s_vec	*vec_alloc(int size, int step)
{
	struct s_vec	*group;
	int				i;

	group = (struct s_vec *)malloc(sizeof(struct s_vec));
	group->row = step;
	group->col = size;
	group->elem = (struct s_elem **)malloc(sizeof(struct s_elem *) * (step));
	i = -1;
	while (++i < step)
		group->elem[i] =
			(struct s_elem *)malloc(sizeof(struct s_elem) * (size));
	return (group);
}
