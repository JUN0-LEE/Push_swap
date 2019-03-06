/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 21:48:13 by julee             #+#    #+#             */
/*   Updated: 2019/02/21 17:58:16 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		*copy_tab(int *tab, int size, int start)
{
	int		*new;
	int		i;

	new = (int *)malloc(sizeof(int) * size);
	i = -1;
	while (++i < size)
		new[i] = tab[start + i];
	return (new);
}

void	merge(int *tab, int start, int mid, int end)
{
	int		i;
	int		j;
	int		k;
	int		*tmp1;
	int		*tmp2;

	tmp1 = copy_tab(tab, mid - start + 1, start);
	tmp2 = copy_tab(tab, end - mid, mid + 1);
	i = 0;
	j = 0;
	k = start;
	while (i < mid - start + 1 && j < end - mid)
	{
		if (tmp1[i] <= tmp2[j])
			tab[k++] = tmp1[i++];
		else
			tab[k++] = tmp2[j++];
	}
	while (i < mid - start + 1)
		tab[k++] = tmp1[i++];
	while (j < end - mid)
		tab[k++] = tmp2[j++];
	free(tmp1);
	free(tmp2);
}

void	merge_sort(int *tab, int start, int end)
{
	int		m;

	if (start < end)
	{
		m = start + (end - start) / 2;
		merge_sort(tab, start, m);
		merge_sort(tab, m + 1, end);
		merge(tab, start, m, end);
	}
}
