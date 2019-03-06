/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:44:19 by julee             #+#    #+#             */
/*   Updated: 2019/02/27 22:53:38 by julee            ###   ########.fr       */
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
int					deq_len(struct s_deq *deq);

int					max_val(int a, int b);
int					min_val(int a, int b);
int					find_biggest(struct s_deq *deq);
int					pad_cal(int width, int val);
void				stack_visualizer(struct s_deq *a
					, struct s_deq *b, int width);

void				swap_val(struct s_deq *a);
void				push_val(struct s_deq *src, struct s_deq *dest);
void				rotate_val(struct s_deq *a);
void				reverse_rotate_val(struct s_deq *a);

int					find_biggest_val(struct s_deq *a);
void				make_stack(int size, char **input, int fd);
void				read_input(struct s_deq	*a
					, struct s_deq *b, int size, int fd);
void				read_input2(struct s_deq *a, struct s_deq *b, char *line);
void				check_ab(struct s_deq *a, struct s_deq	*b);

void				print_bottom_a(int width, struct s_node *tmpa);
void				print_bottom_b(int width, struct s_node *tmpb);
void				print_upper(struct s_deq *a, struct s_deq *b);
void				print_middle_a(struct s_deq *a, struct s_deq *b
					, int width, struct s_node **tmpa);
void				print_middle_b(struct s_deq *a, struct s_deq *b
					, int width, struct s_node **tmpb);

int					positive_limit(char *input);
int					negative_limit(char *input);
int					is_limit(char *input);
void				check_duplicates(int size, char **input);
void				check_valid(int size, char **input);

void				delay_management(int argc, char **argv);
void				color_management(int argc, char **argv);
int					is_flag(char *flag);
int					split_argv(char **argv, char *argv1);
void				free_argv(int size, char **argv);
void				clear_screen(struct s_deq *a, struct s_deq *b
					, int size, char *line);

#endif
