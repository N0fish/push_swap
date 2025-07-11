/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 20:14:35 by algultse          #+#    #+#             */
/*   Updated: 2024/03/13 16:45:53 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_list **target, t_list **source)
{
	t_list	*tmp;

	if (!source || !*source)
		return (0);
	tmp = *source;
	*source = (*source)->next;
	if (*source)
		(*source)->prev = NULL;
	tmp->next = *target;
	tmp->prev = NULL;
	if (*target)
		(*target)->prev = tmp;
	*target = tmp;
	return (1);
}

void	pa(t_data *stack)
{
	if (!stack->b)
		return ;
	if (push(&stack->a, &stack->b) && stack->display == 1)
		ft_printf("pa\n");
}

void	pb(t_data *stack)
{
	if (!stack->a)
		return ;
	if (push(&stack->b, &stack->a) && stack->display == 1)
		ft_printf("pb\n");
}
