/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 02:00:29 by algultse          #+#    #+#             */
/*   Updated: 2024/03/15 14:22:19 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_most(t_list *list, int dir, int *pos)
{
	t_list	*res;
	t_list	*start;

	res = NULL;
	rewind_list(&list);
	start = list;
	while (list != NULL)
	{
		if ((dir == BIGGER && (res == NULL || list->value > res->value)) || \
			(dir == SMALLER && (res == NULL || list->value < res->value)))
			res = list;
		list = list->next;
	}
	if (pos != NULL)
	{
		*pos = 0;
		list = start;
		while (list && list->value != res->value)
		{
			(*pos)++;
			list = list->next;
		}
	}
	return (res);
}

t_list	*find_neighbour(t_list *list, int value, int dir, int *pos)
{
	t_list	*res;
	t_list	*start;

	res = NULL;
	rewind_list(&list);
	start = list;
	while (list != NULL)
	{
		if ((dir == BIGGER && list->value > value && \
			(res == NULL || list->value < res->value)) || (dir == SMALLER && \
			list->value < value && (res == NULL || list->value > res->value)))
			res = list;
		list = list->next;
	}
	if (pos != NULL && res)
	{
		*pos = 0;
		list = start;
		while (list && list->value != res->value)
		{
			(*pos)++;
			list = list->next;
		}
	}
	return (res);
}

void	move_to_neighbour(t_data *data, int b_list_size, int dir)
{
	int		a_pos;
	int		b_pos;
	int		a_list_size;
	t_list	*b_block;

	b_pos = -1;
	a_pos = -1;
	b_block = find_most(data->b, dir, &b_pos);
	find_neighbour(data->a, b_block->value, dir, &a_pos);
	a_list_size = ft_list_size(data->a);
	if (a_pos < a_list_size - a_pos && b_pos < b_list_size - b_pos)
		rr_ab(data, a_pos, b_pos);
	else if (a_pos < a_list_size - a_pos)
		ra_rrb(data, a_pos, b_pos, b_list_size);
	else if (b_pos < b_list_size - b_pos)
		rb_rra(data, a_pos, b_pos, a_list_size);
	else
		rrr_ab(data, (t_params){.a = a_pos, .b = b_pos}, \
			(t_params){.a = a_list_size, .b = b_list_size});
}

void	move_b_list_neighbour(t_data *data, int value, int dir)
{
	int		pos_b;
	int		b_list_size;

	b_list_size = ft_list_size(data->b);
	pos_b = -1;
	find_neighbour(data->b, value, dir, &pos_b);
	if (pos_b < b_list_size - pos_b)
		while (--pos_b >= 0)
			rb(data);
	else
		while (--b_list_size >= pos_b)
			rrb(data);
}
