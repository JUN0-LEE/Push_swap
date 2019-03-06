/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_big.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 14:56:35 by julee             #+#    #+#             */
/*   Updated: 2019/03/03 18:49:59 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_stack2(struct s_deq *a, struct s_deq *b, struct s_lst *iden)
{
	int		len;
	int		width;

	width = 1;
	len = deq_len(a);
	while (width < len)
	{
		if (is_empty(b))
		{
			set_list2(iden, width, "cd");
			sort_stack_a2(a, b, iden);
		}
		else if (is_empty(a))
		{
			set_list2(iden, width, "ab");
			sort_stack_b2(a, b, iden);
		}
		width *= 4;
	}
	while (is_empty(b) == 0)
		push_val(b, a, "pa");
}

void	set_group2(struct s_lst *tmp, int width, int i, int direction)
{
	if (direction == 0)
	{
		if ((i / width) % 4 == 0)
			tmp->group = 'a';
		else if ((i / width) % 4 == 1)
			tmp->group = 'b';
		else if ((i / width) % 4 == 2)
			tmp->group = 'c';
		else if ((i / width) % 4 == 3)
			tmp->group = 'd';
	}
	else
	{
		if ((i / width) % 4 == 0)
			tmp->group = 'd';
		else if ((i / width) % 4 == 1)
			tmp->group = 'c';
		else if ((i / width) % 4 == 2)
			tmp->group = 'b';
		else if ((i / width) % 4 == 3)
			tmp->group = 'a';
	}
}

void	set_list2(struct s_lst *iden, int width, char *flag)
{
	int				i;
	struct s_lst	*tmp;

	i = 0;
	tmp = iden;
	if (ft_strcmp(flag, "cd") == 0)
		while (tmp)
		{
			if ((i / (width * 8)) % 2 == 0)
				set_group2(tmp, width, i, 0);
			else
				set_group2(tmp, width, i, 1);
			i++;
			tmp = tmp->next;
		}
	else
		while (tmp)
		{
			if ((i / (width * 8)) % 2 == 0)
				set_group2(tmp, width, i, 1);
			else
				set_group2(tmp, width, i, 0);
			i++;
			tmp = tmp->next;
		}
}

void	make_stack2(int size, char **input)
{
	struct s_deq	*a;
	struct s_deq	*b;
	int				*tab;
	struct s_lst	*new;
	int				i;

	a = deq_init();
	b = deq_init();
	tab = (int *)malloc(sizeof(int) * size);
	i = -1;
	while (++i < size)
		deq_add_back(a, ft_atoi(input[i]));
	if (is_sorted(a))
		return ;
	i = -1;
	while (++i < size)
		tab[i] = ft_atoi(input[i]);
	merge_sort(tab, 0, size - 1);
	new = make_list(tab, size, log_4(size));
	sort_stack2(a, b, new);
	freer(a, b, tab, new);
	return ;
}
