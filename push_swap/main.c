/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:02:07 by julee             #+#    #+#             */
/*   Updated: 2019/03/03 19:36:32 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
	if (argc < 2)
		ft_putstr("Too few argv :(\n");
	else
	{
		if (argc == 2)
			argc = split_argv(argv, argv[1]);
		check_valid(argc - 1, &argv[1]);
		if (argc - 1 <= 30)
			make_stack1(argc - 1, &argv[1]);
		else if (argc - 1 > 625)
			make_stack2(argc - 1, &argv[1]);
		else
			make_stack(argc - 1, &argv[1]);
	}
	return (0);
}
