/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 22:17:01 by julee             #+#    #+#             */
/*   Updated: 2019/02/27 22:42:56 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void			when_next_is_ab(struct s_lst *tmp, int width, int i)
{
	if (0 * width <= i % (width * 25) && i % (width * 25) <= 10 * width - 1)
		set_group_reverse(tmp, width, i);
	else if (10 * width <= i % (width * 25)
			&& i % (width * 25) <= 15 * width - 1)
	{
		if (75 * width <= i % (width * 125) && i % (width * 125) < 125 * width)
			set_group_reverse(tmp, width, i);
		else
			set_group(tmp, width, i);
	}
	else
		set_group(tmp, width, i);
}

void			when_next_is_de(struct s_lst *tmp, int width, int i)
{
	if (15 * width <= i % (width * 25) && i % (width * 25) <= 25 * width - 1)
		set_group_reverse(tmp, width, i);
	else if (10 * width <= i % (width * 25)
			&& i % (width * 25) <= 15 * width - 1)
	{
		if (0 * width <= i % (width * 125) && i % (width * 125) < 50 * width)
			set_group_reverse(tmp, width, i);
		else
			set_group(tmp, width, i);
	}
	else
		set_group(tmp, width, i);
}

void			set_group(struct s_lst *tmp, int width, int i)
{
	if ((i / width) % 5 == 0)
		tmp->group = 'a';
	else if ((i / width) % 5 == 1)
		tmp->group = 'b';
	else if ((i / width) % 5 == 2)
		tmp->group = 'c';
	else if ((i / width) % 5 == 3)
		tmp->group = 'd';
	else if ((i / width) % 5 == 4)
		tmp->group = 'e';
}

void			set_group_reverse(struct s_lst *tmp, int width, int i)
{
	if ((i / width) % 5 == 0)
		tmp->group = 'e';
	else if ((i / width) % 5 == 1)
		tmp->group = 'd';
	else if ((i / width) % 5 == 2)
		tmp->group = 'c';
	else if ((i / width) % 5 == 3)
		tmp->group = 'b';
	else if ((i / width) % 5 == 4)
		tmp->group = 'a';
}
