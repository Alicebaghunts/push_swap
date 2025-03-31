/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <alisharu@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-27 12:57:49 by alisharu          #+#    #+#             */
/*   Updated: 2025-03-27 12:57:49 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ra(t_stack **list)
{
	t_stack	*first;
	t_stack	*last;

	if (!*list || !(*list)->next)
		return ;
	first = *list;
	*list = (*list)->next;
	if (*list == NULL)
		return ;
	last = first;
	while (last->next != NULL)
		last = last->next;
	first->next = NULL;
	last->next = first;
	ft_putstr("ra\n");
}

void	rb(t_stack **list)
{
	t_stack	*first;
	t_stack	*last;

	if (!*list || !(*list)->next)
		return ;
	first = *list;
	*list = (*list)->next;
	if (*list == NULL)
		return ;
	last = first;
	while (last->next != NULL)
		last = last->next;
	first->next = NULL;
	last->next = first;
	ft_putstr("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	if (*a != NULL && (*a)->next != NULL)
		ra(a);
	if (*b != NULL && (*b)->next != NULL)
		rb(b);
	ft_putstr("rr\n");
}
