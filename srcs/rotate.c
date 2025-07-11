/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:02:05 by algultse          #+#    #+#             */
/*   Updated: 2024/03/15 14:27:42 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_list(t_list **lst)
{
	t_list	*first;
	t_list	*last;

	if (!lst || !*lst || !(*lst)->next)
		return (0);
	first = *lst;
	rewind_list(&first);
	last = *lst;
	fast_forward_list(&last);
	*lst = first->next;
	(*lst)->prev = NULL;
	first->next = NULL;
	last->next = first;
	first->prev = last;
	fast_forward_list(&last);
	return (1);
}

void	ra(t_data *stack_a)
{
	if (rotate_list(&stack_a->a))
		if (stack_a->display == 1)
			ft_printf("ra\n");
}

void	rb(t_data *stack_b)
{
	if (rotate_list(&stack_b->b))
		if (stack_b->display == 1)
			ft_printf("rb\n");
}

void	rr(t_data *stack_r)
{
	if (!stack_r->a || !stack_r->a->next || !stack_r->b || !stack_r->b->next)
		return ;
	if (rotate_list(&stack_r->a) && rotate_list(&stack_r->b))
		if (stack_r->display == 1)
			ft_printf("rr\n");
}
