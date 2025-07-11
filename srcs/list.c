/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 01:35:10 by algultse          #+#    #+#             */
/*   Updated: 2024/03/04 12:17:09 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_list(t_data *data, t_list **list, int nb)
{
	t_list	*next;
	t_list	*tmp;

	tmp = *list;
	fast_forward_list(&tmp);
	next = malloc(sizeof(t_list));
	if (!next)
		ft_error(data);
	next->next = NULL;
	next->prev = NULL;
	next->value = nb;
	if (*list == NULL)
	{
		*list = next;
		return ;
	}
	next->prev = tmp;
	tmp->next = next;
}

void	rewind_list(t_list **list)
{
	if (!list || !*list)
		return ;
	while ((*list)->prev)
		*list = (*list)->prev;
}

void	fast_forward_list(t_list **list)
{
	if (!list || !*list)
		return ;
	while ((*list)->next)
		*list = (*list)->next;
}

int	next_in_list(t_list **list)
{
	if (!list || !*list || !(*list)->next)
		return (0);
	*list = (*list)->next;
	return (1);
}

int	ft_list_size(t_list *begin_list)
{
	int	res;

	res = 0;
	rewind_list(&begin_list);
	while (begin_list)
	{
		begin_list = begin_list->next;
		res++;
	}
	return (res);
}
