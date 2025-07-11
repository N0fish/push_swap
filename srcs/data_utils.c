/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:38:40 by algultse          #+#    #+#             */
/*   Updated: 2024/03/13 16:38:43 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	count_array(void **arr)
{
	size_t	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}

void	print_data(t_data *data)
{
	print_list(data->a, "a");
	print_list(data->b, "b");
}

void	print_list(t_list *list, char *name)
{
	size_t	i;

	i = 0;
	rewind_list(&list);
	while (list)
	{
		ft_printf("%s[%d] value: %d\n", name, (int) i, list->value);
		if (!next_in_list(&list))
			return ;
		i++;
	}
}
