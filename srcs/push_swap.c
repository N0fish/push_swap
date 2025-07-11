/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 21:22:34 by algultse          #+#    #+#             */
/*   Updated: 2024/03/15 14:13:26 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_list_sorted(t_list *list)
{
	if (!list)
		return (0);
	rewind_list(&list);
	while (list->next)
	{
		if (list->value > list->next->value)
			return (0);
		if (!next_in_list(&list))
			return (1);
	}
	return (1);
}

void	general(t_data *data)
{
	int	b_list_len;

	data->display = WITH_DISPLAY;
	init_b_list(data);
	b_list_len = ft_list_size(data->b);
	while (b_list_len > 0)
	{
		move_to_neighbour(data, b_list_len, BIGGER);
		pa(data);
		b_list_len = ft_list_size(data->b);
	}
	while (!is_list_sorted(data->a))
		ra(data);
}

void	push_swap(t_data *data)
{
	if (data->len <= 5)
		return (sort_lst_5_or_less(data));
	general(data);
}
