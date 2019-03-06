/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 14:49:35 by julee             #+#    #+#             */
/*   Updated: 2019/03/03 18:52:11 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	freer(struct s_deq *a, struct s_deq *b, int *tab, struct s_lst *list)
{
	struct s_node	*afirst;
	struct s_node	*tmp;
	struct s_lst	*tmpl;

	afirst = a->first;
	while (afirst)
	{
		tmp = afirst;
		afirst = afirst->next;
		free(tmp);
	}
	free(a);
	free(b);
	if (tab != NULL)
		free(tab);
	while (list)
	{
		tmpl = list;
		list = list->next;
		free(tmpl);
	}
}

void	vec_free(struct s_vec *group)
{
	int		i;

	i = -1;
	while (++i < group->row)
		free(group->elem[i]);
	free(group->elem);
	free(group);
}

void	free_argv(int size, char **argv)
{
	int		i;

	i = -1;
	while (++i < size)
		free(argv[i]);
	free(argv);
}
