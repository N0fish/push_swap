/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 23:36:20 by algultse          #+#    #+#             */
/*   Updated: 2024/03/18 12:22:23 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_params	compute_rotations(t_data *data, int a_pos, int b_pos)
{
	return ((t_params){\
		.a = compute_rotation(data->a, a_pos), \
		.b = compute_rotation(data->b, b_pos), \
	});
}

t_list	*find_elm_chunk_dist(t_data *data, t_list *list, int median, int *pos)
{
	t_list		*elm;
	int			ca;
	int			distance;

	distance = dist_chunk_list(data);
	elm = find_closest_pos_under_median(list, median, pos);
	if (!elm)
		return (NULL);
	ca = compute_rotation(list, *pos);
	while ((ca > 0 && ca > distance) || (ca < 0 && ca < -distance))
	{
		median += 3;
		distance -= 1;
		elm = find_closest_pos_under_median(list, median, pos);
		if (!elm)
			return (NULL);
		ca = compute_rotation(list, *pos);
	}
	return (elm);
}

t_params	find_ab_rotations(t_data *data, int dir, int median, int *value)
{
	int		a_pos;
	int		b_pos;
	t_list	*a_elm;

	b_pos = 0;
	a_elm = find_elm_chunk_dist(data, data->a, median, &a_pos);
	if (!a_elm)
		return ((t_params){0, 0});
	if (value)
		*value = a_elm->value;
	if (ft_list_size(data->b) > 1)
	{
		if (!find_neighbour(data->b, a_elm->value, dir, &b_pos))
		{
			if (find_neighbour(data->b, a_elm->value, \
				ft_ternary(dir == BIGGER, SMALLER, BIGGER), &b_pos))
				b_pos = ft_ternary(b_pos == ft_list_size(data->b) - 1, \
															0, b_pos + 1);
			else
				b_pos = 0;
		}
	}
	return (compute_rotations(data, a_pos, b_pos));
}

void	sync_rotate_lists(t_data *data, int dir, int median)
{
	t_params	rots;
	int			a_len;
	int			value;

	if (!data)
		return ;
	a_len = ft_list_size(data->a);
	rots = find_ab_rotations(data, dir, median, &value);
	while ((rots.a != 0 || rots.b != 0) && a_len > 5)
		neighbour_rotations(data, &rots);
}

void	handle_chunk(t_data *data)
{
	int	len;
	int	i;
	int	median;

	len = ft_list_size(data->a);
	median = find_median(data->a, data->chunk_size, NULL);
	i = data->chunk_size;
	while (len > 5 && --i >= 0)
	{
		sync_rotate_lists(data, SMALLER, median);
		pb(data);
		len = ft_list_size(data->a);
	}
}
