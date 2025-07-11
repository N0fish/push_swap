/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:40:28 by algultse          #+#    #+#             */
/*   Updated: 2024/03/18 12:00:07 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_neighbour(t_list *target, t_list *source, int dir)
{
	t_list	*tmp;

	if (target == NULL || source == NULL)
		return (0);
	tmp = find_neighbour(source, source->value, dir, NULL);
	return (tmp != NULL && tmp->value == target->value);
}

int	is_most(t_list *list, int dir)
{
	t_list	*tmp;

	tmp = find_most(list, dir, NULL);
	return (tmp != NULL && tmp->value == list->value);
}

int	find_median(t_list *list, int block_size, int *closest_pos)
{
	int	val;
	int	pos;

	if (closest_pos != NULL)
		*closest_pos = -1;
	list = find_most(list, SMALLER, NULL);
	if (!list)
		return (0);
	val = list->value;
	while (--block_size > 0)
	{
		list = find_neighbour(list, val, BIGGER, &pos);
		if (!list)
			return (val);
		if (closest_pos != NULL && (\
			*closest_pos == -1 || (!(pos < ft_list_size(list) - pos) && \
			*closest_pos > pos) || (pos < ft_list_size(list) - pos && \
			pos < *closest_pos)))
			*closest_pos = pos;
		val = list->value;
	}
	return (val);
}

int	compute_rotation(t_list *list, int pos)
{
	int	len;

	len = ft_list_size(list);
	if (len == 1)
		return (0);
	return (ft_ternary(pos < len / 2, pos, pos - len));
}

t_list	*find_closest_pos_under_median(t_list *list, int median, \
													int *closest_pos)
{
	t_list	*val;
	int		pos;

	if (!closest_pos)
		return (NULL);
	*closest_pos = -1;
	pos = 0;
	list = find_most(list, SMALLER, &pos);
	if (!list || list->value > median)
		return (NULL);
	val = list;
	while (list->value <= median)
	{
		if (*closest_pos == -1 || \
			abs(compute_rotation(list, pos)) \
			< abs(compute_rotation(list, *closest_pos)))
		{
			*closest_pos = pos;
			val = list;
		}
		list = find_neighbour(list, list->value, BIGGER, &pos);
		if (!list || list->value > median)
			return (val);
	}
	return (val);
}
