/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:31:54 by algultse          #+#    #+#             */
/*   Updated: 2024/03/18 12:07:11 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
		exit(1);
	data = init_data(argc, argv);
	init_lists(data);
	data->display = WITH_DISPLAY;
	push_swap(data);
	data_free(data);
	return (0);
}
