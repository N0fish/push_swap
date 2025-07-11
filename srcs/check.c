/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:42:25 by algultse          #+#    #+#             */
/*   Updated: 2024/03/18 11:50:08 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	number_unique(int nb, t_list *a)
{
	if (!a)
		return (1);
	while (a)
	{
		if (a->value == nb)
			return (0);
		a = a->next;
	}
	return (1);
}

int	check_number(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_strchr("0123456789", *str))
			return (0);
		str++;
	}
	return (1);
}

int	dist_chunk_list(t_data *data)
{
	int	distance;

	distance = data->chunk_size;
	if (data->len >= 900)
		distance *= 2.5;
	else if (data->len >= 500)
		distance *= 1.8;
	else if (data->len >= 100)
		distance *= 1 + (0.0017 * (data->len - 100));
	return (distance);
}
