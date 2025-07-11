/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:38:32 by algultse          #+#    #+#             */
/*   Updated: 2024/03/18 12:07:29 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "libft.h"

/**/
# define WITH_DISPLAY 1
# define NO_DISPLAY 0
# define BIGGER 1
# define SMALLER 0

typedef struct s_params {
	int	a;
	int	b;
}				t_params;

typedef struct s_list {
	int				value;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

typedef struct s_data {
	struct s_list	*a;
	struct s_list	*b;
	char			**argv;
	int				start;
	int				argc;
	int				display;
	int				len;
	int				split;
	int				chunks;
	int				chunk_size;
}				t_data;

/* init */
t_data		*init_data(int argc, char **argv);
void		init_lists(t_data *data);
void		init_b_list(t_data *data);
/* push_swap */
void		general(t_data *data);
void		push_swap(t_data *data);
int			is_list_sorted(t_list *list);
int			ft_list_size(t_list *begin_list);
void		sort_3(t_data *data);
/* check */
int			check_number(char *str);
int			dist_chunk_list(t_data *data);
int			number_unique(int nb, t_list *a);
/* error */
void		ft_error(t_data *data);
void		data_free(t_data *data);
/* utils */
void		add_to_list(t_data *data, t_list **list, int nb);
void		rewind_list(t_list **list);
void		fast_forward_list(t_list **list);
int			next_in_list(t_list **list);
/* list_utils */
int			is_neighbour(t_list *target, t_list *source, int dir);
int			is_most(t_list *list, int dir);
int			find_median(t_list *list, int block_size, int *closest_pos);
int			compute_rotation(t_list *list, int pos);
t_list		*find_closest_pos_under_median(t_list *list, int median, \
														int *closest_pos);
/* list_ops */
t_list		*find_neighbour(t_list *list, int value, int dir, int *pos);
t_list		*find_most(t_list *list, int dir, int *pos);
void		move_to_neighbour(t_data *data, int b_list_size, int dir);
void		move_b_list_neighbour(t_data *data, int value, int dir);
/* data_utils */
void		print_data(t_data *data);
size_t		count_array(void **arr);
void		print_list(t_list *list, char *name);
/**/
void		pa(t_data *stack);
void		pb(t_data *stack);
/**/
void		sa(t_data *stack_a);
void		sb(t_data *stack_b);
void		ss(t_data *stack_ss);
/**/
void		rra(t_data *stack_a);
void		rrb(t_data *stack_b);
void		rrr(t_data *stack_rv);
/**/
void		ra(t_data *stack_a);
void		rb(t_data *stack_b);
void		rr(t_data *stack_r);
/**/
void		sort_lst_5_or_less(t_data *stack);
/* chunk */
t_params	find_ab_rotations(t_data *data, int dir, int median, int *value);
t_params	compute_rotations(t_data *data, int a_pos, int b_pos);
void		handle_chunk(t_data *data);
void		sync_rotate_lists(t_data *data, int dir, int median);
/* neighbour */
void		rr_ab(t_data *data, int a_pos, int b_pos);
void		ra_rrb(t_data *data, int a_pos, int b_pos, int b_list_size);
void		rb_rra(t_data *data, int a_pos, int b_pos, int a_list_size);
void		rrr_ab(t_data *data, t_params pos, t_params sizes);
void		neighbour_rotations(t_data *data, t_params *rots);

#endif