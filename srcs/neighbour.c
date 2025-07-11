/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neighbour.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 23:35:59 by algultse          #+#    #+#             */
/*   Updated: 2024/03/18 12:00:43 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_ab(t_data *data, int a_pos, int b_pos)
{
	a_pos--;
	b_pos--;
	while (a_pos >= 0 || b_pos >= 0)
	{
		if (b_pos >= 0 && a_pos >= 0)
			rr(data);
		else if (b_pos >= 0)
			rb(data);
		else
			ra(data);
		a_pos--;
		b_pos--;
	}
}

void	ra_rrb(t_data *data, int a_pos, int b_pos, int b_list_size)
{
	while (--a_pos >= 0)
		ra(data);
	while (--b_list_size >= b_pos)
		rrb(data);
}

void	rb_rra(t_data *data, int a_pos, int b_pos, int a_list_size)
{
	while (--b_pos >= 0)
		rb(data);
	while (--a_list_size >= a_pos)
		rra(data);
}

void	rrr_ab(t_data *data, t_params pos, t_params sizes)
{
	sizes.a--;
	sizes.b--;
	while (sizes.a >= pos.a || sizes.b >= pos.b)
	{
		if (sizes.a >= pos.a && sizes.b >= pos.b)
			rrr(data);
		else if (sizes.b >= pos.b)
			rrb(data);
		else
			rra(data);
		sizes.a--;
		sizes.b--;
	}
}

void	neighbour_rotations(t_data *data, t_params *rots)
{
	if (!data || !rots)
		return ;
	if (rots->a < 0 && rots->b < 0)
		rrr(data);
	else if (rots->a > 0 && rots->b > 0)
		rr(data);
	else
	{
		if (rots->a < 0)
			rra(data);
		else if (rots->a > 0)
			ra(data);
		if (rots->b < 0)
			rrb(data);
		else if (rots->b > 0)
			rb(data);
	}
	if (rots->a != 0)
		rots->a += ft_ternary(rots->a < 0, 1, -1);
	if (rots->b != 0)
		rots->b += ft_ternary(rots->b < 0, 1, -1);
}
