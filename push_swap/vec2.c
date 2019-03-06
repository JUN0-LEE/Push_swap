/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 22:24:35 by julee             #+#    #+#             */
/*   Updated: 2019/02/27 22:45:02 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		is_next_ab(struct s_vec *group, int currow, int curcol)
{
	if (group->elem[currow + 1][curcol].group == 'a'
	|| group->elem[currow + 1][curcol].group == 'b')
		return (1);
	return (0);
}

int		is_next_de(struct s_vec *group, int currow, int curcol)
{
	if (group->elem[currow + 1][curcol].group == 'd'
	|| group->elem[currow + 1][curcol].group == 'e')
		return (1);
	return (0);
}

void	if_next_ab(struct s_vec *group, int currow, int width)
{
	int		direction;
	int		col;

	col = -1;
	while (++col < group->col)
	{
		direction = get_direction_sum(group, currow, col);
		if ((is_next_ab(group, currow, col) == 1 && (direction % 2 == 1))
		|| (is_next_ab(group, currow, col) == 0 && (direction % 2 == 0)))
			put_group(group, currow, col, width);
		else
			put_group_reverse(group, currow, col, width);
	}
}

void	if_next_de(struct s_vec *group, int currow, int width)
{
	int		direction;
	int		col;

	col = -1;
	while (++col < group->col)
	{
		direction = get_direction_sum(group, currow, col);
		if ((is_next_de(group, currow, col) == 1 && (direction % 2 == 1))
		|| (is_next_de(group, currow, col) == 0 && (direction % 2 == 0)))
			put_group(group, currow, col, width);
		else
			put_group_reverse(group, currow, col, width);
	}
}

int		get_direction_sum(struct s_vec *group, int currow, int curcol)
{
	int		sum;
	int		i;

	sum = 0;
	i = currow;
	while (++i < group->row)
		sum += group->elem[i][curcol].direction;
	return (sum);
}
