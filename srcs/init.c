/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 20:58:38 by algultse          #+#    #+#             */
/*   Updated: 2024/03/18 12:18:11 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_chunks(t_data *data, int argc)
{
	data->argc = argc;
	data->len = data->argc - data->start;
	data->chunks = 10;
	if (data->len >= 500)
		data->chunks = 13;
	if (data->len >= 900)
		data->chunks = 16;
	if (data->len < data->chunks)
		data->chunks = 1;
	data->chunk_size = data->len / data->chunks;
}

t_data	*init_data(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		exit(1);
	data->a = NULL;
	data->b = NULL;
	data->argv = argv;
	data->start = 1;
	data->display = NO_DISPLAY;
	data->len = 0;
	data->split = false;
	if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		data->argv = ft_split(argv[1], ' ');
		if (!data->argv)
			ft_error(data);
		data->split = true;
		if (!data->argv[0])
			ft_error(data);
		data->start = 0;
		argc = (int)count_array((void **)data->argv);
	}
	init_chunks(data, argc);
	return (data);
}

void	init_lists(t_data *data)
{
	long	nb;

	while (data->start < data->argc)
	{
		if (!check_number(data->argv[data->start]))
			ft_error(data);
		nb = ft_atoi_long(data->argv[data->start]);
		if (nb > INT_MAX || nb < INT_MIN)
			ft_error(data);
		if (!number_unique((int)nb, data->a))
			ft_error(data);
		add_to_list(data, &(data->a), (int)nb);
		data->start++;
	}
}

void	init_b_list(t_data *data)
{
	int	total_length;

	total_length = ft_list_size(data->a);
	while (total_length > 5 && !is_list_sorted(data->a))
	{
		handle_chunk(data);
		total_length = ft_list_size(data->a);
	}
	if (is_list_sorted(data->a))
		return ;
	sort_lst_5_or_less(data);
}
