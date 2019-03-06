/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 19:09:51 by julee             #+#    #+#             */
/*   Updated: 2019/03/03 19:15:25 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_ab(struct s_deq *a, struct s_deq	*b)
{
	struct s_node	*item;

	if (is_empty(b) == 0)
	{
		printf("KO\n");
		exit(0);
	}
	else
	{
		item = a->first;
		while (item->next)
		{
			if (item->val > item->next->val)
			{
				printf("KO\n");
				exit(0);
			}
			else
				item = item->next;
		}
		printf("OK\n");
	}
}

void	read_input2(struct s_deq *a, struct s_deq *b, char *line)
{
	if (strcmp(line, "sb") == 0)
		swap_val(b);
	else if (strcmp(line, "ss") == 0)
	{
		swap_val(a);
		swap_val(b);
	}
	else if (strcmp(line, "pa") == 0)
		push_val(b, a);
	else if (strcmp(line, "pb") == 0)
		push_val(a, b);
	else if (strcmp(line, "ra") == 0)
		rotate_val(a);
	else if (strcmp(line, "rb") == 0)
		rotate_val(b);
	else if (strcmp(line, "rr") == 0)
	{
		rotate_val(a);
		rotate_val(b);
	}
	else if (strcmp(line, "rra") == 0)
		reverse_rotate_val(a);
	else if (strcmp(line, "rrb") == 0)
		reverse_rotate_val(b);
}

void	read_input(struct s_deq	*a, struct s_deq *b, int size, int fd)
{
	char	*line;

	while (get_next_line(fd, &line))
	{
		if (strcmp(line, "sa") == 0)
			swap_val(a);
		else if ((strcmp(line, "sb") == 0) || (strcmp(line, "ss") == 0)
		|| (strcmp(line, "pa") == 0) || (strcmp(line, "pb") == 0)
		|| (strcmp(line, "ra") == 0) || (strcmp(line, "rb") == 0)
		|| (strcmp(line, "rr") == 0) || (strcmp(line, "rra") == 0)
		|| (strcmp(line, "rrb") == 0))
			read_input2(a, b, line);
		else if (strcmp(line, "rrr") == 0)
		{
			reverse_rotate_val(a);
			reverse_rotate_val(b);
		}
		else
		{
			printf("Error : invalid arg :(\n");
			exit(0);
		}
		clear_screen(a, b, size, line);
	}
	check_ab(a, b);
}
