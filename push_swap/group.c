/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:08:00 by julee             #+#    #+#             */
/*   Updated: 2019/03/02 00:11:25 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

struct s_lst	*new_list(int val1, int val2, char group, int n)
{
	struct s_lst	*new;

	new = (struct s_lst *)malloc(sizeof(new));
	new->next = NULL;
	if (n == 1)
		new->val = val1;
	else
		new->val = val2;
	new->group = group;
	return (new);
}

struct s_lst	*make_list(int *tab, int size, int n)
{
	struct s_lst	*new;
	struct s_lst	*begin;
	int				i;

	new = new_list(tab[0], tab[size - 1], 'a', n % 2);
	begin = new;
	if (n % 2 == 1)
	{
		i = 0;
		while (++i < size)
		{
			new->next = new_list(tab[i], 0, 'a', 1);
			new = new->next;
		}
	}
	if (n % 2 == 0)
	{
		i = size - 1;
		while (--i >= 0)
		{
			new->next = new_list(tab[i], 0, 'a', 1);
			new = new->next;
		}
	}
	return (begin);
}

void			set_list(struct s_lst *iden, int width, int set)
{
	int				i;
	struct s_lst	*tmp;

	i = 0;
	tmp = iden;
	if (set == 1)
		while (tmp)
		{
			when_next_is_ab(tmp, width, i);
			i++;
			tmp = tmp->next;
		}
	else if (set == 0)
		while (tmp)
		{
			when_next_is_de(tmp, width, i);
			i++;
			tmp = tmp->next;
		}
}

void			put_group(struct s_vec *group
		, int currow, int curcol, int width)
{
	group->elem[currow][curcol].direction = 0;
	if ((curcol / width) % 5 == 0)
		group->elem[currow][curcol].group = 'a';
	else if ((curcol / width) % 5 == 1)
		group->elem[currow][curcol].group = 'b';
	else if ((curcol / width) % 5 == 2)
		group->elem[currow][curcol].group = 'c';
	else if ((curcol / width) % 5 == 3)
		group->elem[currow][curcol].group = 'd';
	else if ((curcol / width) % 5 == 4)
		group->elem[currow][curcol].group = 'e';
}

void			put_group_reverse(struct s_vec *group
		, int currow, int curcol, int width)
{
	group->elem[currow][curcol].direction = 1;
	if ((curcol / width) % 5 == 0)
		group->elem[currow][curcol].group = 'e';
	else if ((curcol / width) % 5 == 1)
		group->elem[currow][curcol].group = 'd';
	else if ((curcol / width) % 5 == 2)
		group->elem[currow][curcol].group = 'c';
	else if ((curcol / width) % 5 == 3)
		group->elem[currow][curcol].group = 'b';
	else if ((curcol / width) % 5 == 4)
		group->elem[currow][curcol].group = 'a';
}
