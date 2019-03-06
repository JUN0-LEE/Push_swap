/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:20:24 by julee             #+#    #+#             */
/*   Updated: 2019/03/03 18:50:38 by julee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
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

struct				s_lst
{
	int				val;
	char			group;
	struct s_lst	*next;
};

struct				s_elem
{
	int				direction;
	char			group;
};

struct				s_vec
{
	struct s_elem	**elem;
	int				row;
	int				col;
};

struct s_deq		*deq_init(void);
int					deq_pop_front(struct s_deq *deq);
int					deq_pop_back(struct s_deq *deq);
void				deq_add_back(struct s_deq *deq, int val);
void				deq_add_front(struct s_deq *deq, int val);
int					deq_len(struct s_deq *deq);

int					peek_front(struct s_deq *deq);
int					peek_back(struct s_deq *deq);
int					is_empty(struct s_deq *deq);

void				print_stack(struct s_deq *s);
void				print_both_stack(struct s_deq *a, struct s_deq *b);
void				stack_visualizer(struct s_deq *a
					, struct s_deq *b, int width, struct s_lst *iden);

struct s_lst		*new_list(int val1, int val2, char group, int n);
struct s_lst		*make_list(int *tab, int size, int n);
void				set_list(struct s_lst *iden, int width, int set);
void				put_group(struct s_vec *group
					, int currow, int curcol, int width);
void				put_group_reverse(struct s_vec *group
					, int currow, int curcol, int width);

void				when_next_is_ab(struct s_lst *tmp, int width, int i);
void				when_next_is_de(struct s_lst *tmp, int width, int i);
void				set_group(struct s_lst *tmp, int width, int i);
void				set_group_reverse(struct s_lst *tmp, int width, int i);

int					log_5(int n);
int					log_4(int n);
char				which_group(struct s_node *node, struct s_lst *iden);
int					power_of_5(int n);

void				swap_val(struct s_deq *a, char *op);
void				push_val(struct s_deq *src, struct s_deq *dest, char *op);
void				rotate_val(struct s_deq *a, char *op);
void				reverse_rotate_val(struct s_deq *a, char *op);
void				rotate_both(struct s_deq *a, struct s_deq *b);

int					*copy_tab(int *tab, int size, int start);
void				merge(int *tab, int start, int mid, int end);
void				merge_sort(int *tab, int start, int end);

void				sort_stack_b_ad(struct s_deq *a, struct s_deq *b
					, struct s_lst *iden, int pushcount);
void				sort_stack_b(struct s_deq *a, struct s_deq *b
					, struct s_lst *iden);
void				sort_stack_b_err(struct s_deq *a, struct s_deq *b
					, struct s_lst *iden, int *count);
void				sort_stack_b_drr(struct s_deq *a, struct s_deq *b
					, struct s_lst *iden, int *count);
void				sort_stack(struct s_deq *a, struct s_deq *b
					, struct s_lst *iden, int len);

void				sort_stack_a_ad(struct s_deq *a, struct s_deq *b
					, struct s_lst *iden, int pushcount);
void				sort_stack_a(struct s_deq *a, struct s_deq *b
					, struct s_lst *iden);
void				sort_stack_a_arr(struct s_deq *a, struct s_deq *b
					, struct s_lst *iden, int *count);
void				sort_stack_a_brr(struct s_deq *a, struct s_deq *b
					, struct s_lst *iden, int *count);
void				make_stack(int size, char **input);

void				sort_stack_a2(struct s_deq *a, struct s_deq *b
					, struct s_lst *iden);
void				sort_stack_a_opt2(struct s_deq *a, struct s_deq *b
					, struct s_lst *iden, int *count);
void				sort_stack_a_ad2(struct s_deq *a, struct s_deq *b
					, struct s_lst *iden, int pushcount);

void				sort_stack_b_ad2(struct s_deq *a, struct s_deq *b
					, struct s_lst *iden, int pushcount);
void				sort_stack_b_opt2(struct s_deq *a, struct s_deq *b
					, struct s_lst *iden, int *count);
void				sort_stack_b2(struct s_deq *a, struct s_deq *b
					, struct s_lst *iden);

void				make_stack2(int size, char **input);
void				set_list2(struct s_lst *iden, int width, char *flag);
void				set_group2(struct s_lst *tmp
					, int width, int i, int direction);
void				sort_stack2(struct s_deq *a
					, struct s_deq *b, struct s_lst *iden);

void				set_group_vec(struct s_vec *group);
struct s_vec		*vec_alloc(int size, int step);
void				set_first(struct s_vec *group, int width);
void				set_last(struct s_vec *group, int width);
void				copy_group(struct s_lst *iden
					, struct s_vec *group, int row);

int					is_next_ab(struct s_vec *group, int currow, int curcol);
int					is_next_de(struct s_vec *group, int currow, int curcol);
void				if_next_ab(struct s_vec *group, int currow, int width);
void				if_next_de(struct s_vec *group, int currow, int width);
int					get_direction_sum(struct s_vec *group
					, int currow, int curcol);

int					is_sorted(struct s_deq *a);

void				freer(struct s_deq *a, struct s_deq *b
					, int *tab, struct s_lst *list);
void				vec_free(struct s_vec *group);
void				free_argv(int size, char **argv);

void				check_valid(int size, char **input);
void				check_duplicates(int size, char **input);
int					is_limit(char *input);
int					negative_limit(char *input);
int					positive_limit(char *input);

void				make_stack1(int size, char **input);
void				sort_small_first(struct s_deq *a
					, struct s_deq *b, int pushcount);
int					find_smallest(struct s_deq *a);
void				for_3(struct s_deq *a);
int					is_right_order(struct s_deq *a);

#endif
