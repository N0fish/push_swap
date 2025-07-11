/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 01:25:24 by algultse          #+#    #+#             */
/*   Updated: 2024/03/15 14:29:21 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_data *data)
{
	int	top;
	int	middle;
	int	bottom;

	top = data->a->value;
	middle = data->a->next->value;
	bottom = data->a->next->next->value;
	if (top > middle && middle < bottom && bottom > top)
		sa(data);
	else if (top > middle && middle > bottom && bottom < top)
	{
		sa(data);
		rra(data);
	}
	else if (top > middle && middle < bottom && bottom < top)
		ra(data);
	else if (top < middle && middle > bottom && bottom > top)
	{
		sa(data);
		ra(data);
	}
	else if (top < middle && middle > bottom && bottom < top)
		rra(data);
}

int	find_min(t_list *lst)
{
	lst = find_most(lst, SMALLER, NULL);
	if (!lst)
		return (0);
	return (lst->value);
}

void	sort_4(t_data *data)
{
	int	min;

	min = find_min(data->a);
	while (data->a->value != min)
		ra(data);
	pb(data);
	sort_3(data);
	pa(data);
}

void	sort_5(t_data *data)
{
	int	median;
	int	count;
	int	i;

	median = find_median(data->a, 3, NULL);
	count = 0;
	i = 0;
	while (count < 2 && i < 5)
	{
		if (data->a->value < median)
		{
			pb(data);
			count++;
		}
		else
			ra(data);
		i++;
	}
	sort_3(data);
	if (data->b != NULL && data->b->next != NULL && \
		data->b->value < data->b->next->value)
		sb(data);
	pa(data);
	pa(data);
}

void	sort_lst_5_or_less(t_data *stack)
{
	while (!is_list_sorted(stack->a))
	{
		if (ft_list_size(stack->a) == 2)
			if (stack->a->value > stack->a->next->value)
				sa(stack);
		if (ft_list_size(stack->a) == 3)
			sort_3(stack);
		if (ft_list_size(stack->a) == 4)
			sort_4(stack);
		if (ft_list_size(stack->a) == 5)
			sort_5(stack);
	}
}
