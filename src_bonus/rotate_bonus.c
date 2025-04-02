/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-02 10:13:01 by alisharu          #+#    #+#             */
/*   Updated: 2025-04-02 10:13:01 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap_bonus.h"

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
}

void	rr(t_stack **a, t_stack **b)
{
	if (*a != NULL && (*a)->next != NULL)
		ra(a);
	if (*b != NULL && (*b)->next != NULL)
		rb(b);
}
