/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:43:56 by julee             #+#    #+#             */
/*   Updated: 2019/03/03 19:34:26 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_ab(struct s_deq *a, struct s_deq	*b)
{
	struct s_node	*item;

	if (is_empty(b) == 0)
	{
		ft_putstr("KO\n");
		exit(0);
	}
	else
	{
		item = a->first;
		while (item->next)
		{
			if (item->val > item->next->val)
			{
				ft_putstr("KO\n");
				exit(0);
			}
			else
				item = item->next;
		}
		ft_putstr("OK\n");
	}
}

void	read_input2(struct s_deq *a, struct s_deq *b, char *line)
{
	if (ft_strcmp(line, "sb") == 0)
		swap_val(b);
	else if (ft_strcmp(line, "ss") == 0)
	{
		swap_val(a);
		swap_val(b);
	}
	else if (ft_strcmp(line, "pa") == 0)
		push_val(b, a);
	else if (ft_strcmp(line, "pb") == 0)
		push_val(a, b);
	else if (ft_strcmp(line, "ra") == 0)
		rotate_val(a);
	else if (ft_strcmp(line, "rb") == 0)
		rotate_val(b);
	else if (ft_strcmp(line, "rr") == 0)
	{
		rotate_val(a);
		rotate_val(b);
	}
	else if (ft_strcmp(line, "rra") == 0)
		reverse_rotate_val(a);
	else if (ft_strcmp(line, "rrb") == 0)
		reverse_rotate_val(b);
}

void	read_input(struct s_deq	*a, struct s_deq *b, int fd)
{
	char	*line;

	while (get_next_line(fd, &line))
	{
		if (ft_strcmp(line, "sa") == 0)
			swap_val(a);
		else if ((ft_strcmp(line, "sb") == 0) || (ft_strcmp(line, "ss") == 0)
		|| (ft_strcmp(line, "pa") == 0) || (ft_strcmp(line, "pb") == 0)
		|| (ft_strcmp(line, "ra") == 0) || (ft_strcmp(line, "rb") == 0)
		|| (ft_strcmp(line, "rr") == 0) || (ft_strcmp(line, "rra") == 0)
		|| (ft_strcmp(line, "rrb") == 0))
			read_input2(a, b, line);
		else if (ft_strcmp(line, "rrr") == 0)
		{
			reverse_rotate_val(a);
			reverse_rotate_val(b);
		}
		else
		{
			ft_putstr("Error : invalid arg :(\n");
			exit(0);
		}
		free(line);
	}
	check_ab(a, b);
}

int		main(int argc, char **argv)
{
	int fd;

	fd = 0;
	if (argc < 2)
		ft_putstr("Too few argv :(\n");
	else
	{
		if (is_flag(argv[1]) && (fd = open(argv[2], O_RDONLY)) != -1)
		{
			check_valid(argc - 3, &argv[3]);
			make_stack(argc - 3, &argv[3], fd);
			return (0);
		}
		if (argc == 2)
			argc = split_argv(argv, argv[1]);
		check_valid(argc - 1, &argv[1]);
		make_stack(argc - 1, &argv[1], fd);
	}
	return (0);
}
