/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 19:04:48 by julee             #+#    #+#             */
/*   Updated: 2019/03/03 19:14:45 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		g_delay;

void	clear_screen(struct s_deq *a, struct s_deq *b, int size, char *line)
{
	printf("\033[2J");
	printf("\033[H");
	stack_visualizer(a, b, size);
	if (g_delay == 0)
		usleep(100000);
	else
		usleep(g_delay);
	free(line);
}

int		is_flag(char *flag)
{
	if (flag[0] == '-' && flag[1] && flag[1] == 'f')
		return (1);
	else if (flag[0] == '-' && flag[1] && flag[1] == 'c')
		return (2);
	else if (flag[0] == '-' && flag[1] && flag[1] == 'd')
		return (3);
	return (0);
}

void	color_management(int argc, char **argv)
{
	if (argv[2] && ft_strcmp(argv[2], "red") == 0)
		printf("\033[0;31m");
	else if (argv[2] && ft_strcmp(argv[2], "blue") == 0)
		printf("\033[0;34m");
	else if (argv[2] && ft_strcmp(argv[2], "green") == 0)
		printf("\033[0;32m");
	check_valid(argc - 3, &argv[3]);
	make_stack(argc - 3, &argv[3], 0);
	exit(0);
}

void	delay_management(int argc, char **argv)
{
	if (argv[2])
		g_delay = ft_atoi(argv[2]);
	else
		return ;
	check_valid(argc - 3, &argv[3]);
	make_stack(argc - 3, &argv[3], 0);
	exit(0);
}
