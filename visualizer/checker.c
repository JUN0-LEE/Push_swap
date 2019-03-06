/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:43:56 by julee             #+#    #+#             */
/*   Updated: 2019/03/03 19:14:24 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_argv(int size, char **argv)
{
	int		i;

	i = -1;
	while (++i < size)
		free(argv[i]);
	free(argv);
}

int		split_argv(char **argv, char *argv1)
{
	int		i;
	char	**tmp;
	int		argc;

	tmp = ft_strsplit(argv1, ' ');
	argc = 0;
	while (tmp[argc])
		argc++;
	i = -1;
	while (++i < argc)
		argv[i + 1] = ft_strdup(tmp[i]);
	free_argv(argc, tmp);
	return (argc + 1);
}

int		main(int argc, char **argv)
{
	int		fd;

	fd = 0;
	if (argc < 2)
		printf("Too few argv :(\n");
	else
	{
		if (is_flag(argv[1]) == 1 && (fd = open(argv[2], O_RDONLY)) != -1)
		{
			check_valid(argc - 3, &argv[3]);
			make_stack(argc - 3, &argv[3], fd);
			return (0);
		}
		else if (is_flag(argv[1]) == 2)
			color_management(argc, argv);
		else if (is_flag(argv[1]) == 3)
			delay_management(argc, argv);
		if (argc == 2)
			argc = split_argv(argv, argv[1]);
		check_valid(argc - 1, &argv[1]);
		make_stack(argc - 1, &argv[1], fd);
	}
	return (0);
}
