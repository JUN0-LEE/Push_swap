/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 18:31:32 by julee             #+#    #+#             */
/*   Updated: 2019/03/03 18:38:55 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	make_stack(int size, char **input, int fd)
{
	struct s_deq	*a;
	struct s_deq	*b;
	int				i;

	a = deq_init();
	b = deq_init();
	i = -1;
	while (++i < size)
		deq_add_back(a, ft_atoi(input[i]));
	read_input(a, b, fd);
	return ;
}

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

int		is_flag(char *flag)
{
	if (flag[0] == '-' && flag[1] && flag[1] == 'f')
		return (1);
	return (0);
}
