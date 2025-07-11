/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:03:35 by algultse          #+#    #+#             */
/*   Updated: 2024/03/15 14:28:10 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_rev_list(t_list **lst)
{
	t_list	*last;
	t_list	*before_last;
	t_list	*first;

	if (!lst || !*lst || !(*lst)->next)
		return (0);
	first = *lst;
	rewind_list(&first);
	last = *lst;
	fast_forward_list(&last);
	before_last = last->prev;
	*lst = last;
	(*lst)->prev = NULL;
	(*lst)->next = first;
	before_last->next = NULL;
	first->prev = *lst;
	return (1);
}

void	rra(t_data *stack_a)
{
	if (rotate_rev_list(&stack_a->a))
		if (stack_a->display == 1)
			ft_printf("rra\n");
}

void	rrb(t_data *stack_b)
{
	if (rotate_rev_list(&stack_b->b))
		if (stack_b->display == 1)
			ft_printf("rrb\n");
}

void	rrr(t_data *stack_rv)
{
	if (!stack_rv->a || !stack_rv->a->next || \
		!stack_rv->b || !stack_rv->b->next)
		return ;
	if (rotate_rev_list(&stack_rv->a) && rotate_rev_list(&stack_rv->b))
		if (stack_rv->display == 1)
			ft_printf("rrr\n");
}
