/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 20:14:13 by algultse          #+#    #+#             */
/*   Updated: 2024/03/13 16:47:15 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_list(t_list *lst)
{
	int	tmp;

	if (!lst || !lst->next)
		return (0);
	tmp = lst->value;
	lst->value = lst->next->value;
	lst->next->value = tmp;
	return (1);
}

void	sa(t_data *stack_a)
{
	t_list	*tmp;

	tmp = stack_a->a;
	rewind_list(&tmp);
	if (swap_list(tmp))
		if (stack_a->display == 1)
			ft_printf("sa\n");
}

void	sb(t_data *stack_b)
{
	if (swap_list(stack_b->b))
		if (stack_b->display == 1)
			ft_printf("sb\n");
}

void	ss(t_data *stack_ss)
{
	if (!stack_ss->a || !stack_ss->a->next \
		|| !stack_ss->b || !stack_ss->b->next)
		return ;
	if (swap_list(stack_ss->a) && swap_list(stack_ss->b))
		if (stack_ss->display == 1)
			ft_printf("ss\n");
}
