/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 18:54:25 by julee             #+#    #+#             */
/*   Updated: 2019/03/03 19:15:18 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		positive_limit(char *input)
{
	if (ft_strcmp(input, "2147483647") > 0)
		return (0);
	return (1);
}

int		negative_limit(char *input)
{
	if (ft_strcmp(input, "2147483648") > 0)
		return (0);
	return (1);
}

int		is_limit(char *input)
{
	if (input[0] == '-')
	{
		if (ft_strlen(input) > 11)
			return (0);
		else if (ft_strlen(input) < 11)
			return (1);
		else if (negative_limit(&input[1]) == 1)
			return (1);
	}
	else
	{
		if (ft_strlen(input) > 10)
			return (0);
		else if (ft_strlen(input) < 10)
			return (1);
		else if (positive_limit(input) == 1)
			return (1);
	}
	return (0);
}

void	check_duplicates(int size, char **input)
{
	int		i;
	int		j;

	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			if (ft_strcmp(input[i], input[j]) == 0)
			{
				ft_putstr("Error: duplicatd input\n");
				exit(0);
			}
		}
	}
	return ;
}

void	check_valid(int size, char **input)
{
	int		i;
	int		j;
	int		error;

	i = -1;
	error = 0;
	while (++i < size)
	{
		j = -1;
		while (input[i][++j])
			if (!((48 <= input[i][j] && input[i][j] <= 57)
						|| input[i][j] == 45))
				error = 1;
		if (is_limit(input[i]) == 0)
			error = 1;
	}
	if (error == 1)
	{
		ft_putstr("Error: invalid arg :(\n");
		exit(1);
	}
	check_duplicates(size, input);
}
