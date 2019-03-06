/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:44:19 by julee             #+#    #+#             */
/*   Updated: 2019/02/20 14:34:57 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

struct				s_node
{
	int				val;
	struct s_node	*next;
	struct s_node	*prev;
};

struct				s_deq
{
	struct s_node	*first;
	struct s_node	*last;
};

struct s_deq		*deq_init(void);
int					deq_pop_front(struct s_deq *deq);
int					deq_pop_back(struct s_deq *deq);
void				deq_add_back(struct s_deq *deq, int val);
void				deq_add_front(struct s_deq *deq, int val);
int					peek_front(struct s_deq *deq);
int					peek_back(struct s_deq *deq);
int					is_empty(struct s_deq *deq);

void				print_args(int argc, char **argv);
void				print_stack(struct s_deq *s);
void				print_both_stack(struct s_deq *a, struct s_deq *b);

void				swap_val(struct s_deq *a);
void				push_val(struct s_deq *src, struct s_deq *dest);
void				rotate_val(struct s_deq *a);
void				reverse_rotate_val(struct s_deq *a);

void				check_valid(int size, char **input);
void				check_duplicates(int size, char **input);
int					is_limit(char *input);
int					negative_limit(char *input);
int					positive_limit(char *input);

void				read_input(struct s_deq	*a, struct s_deq *b, int fd);
void				read_input2(struct s_deq *a, struct s_deq *b, char *line);
void				check_ab(struct s_deq *a, struct s_deq	*b);

void				make_stack(int size, char **input, int fd);
void				free_argv(int size, char **argv);
int					split_argv(char **argv, char *argv1);
int					is_flag(char *flag);

#endif
