/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-02 10:12:52 by alisharu          #+#    #+#             */
/*   Updated: 2025-04-02 10:12:52 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap_bonus.h"

void	rra(t_stack **list)
{
	t_stack	*end;
	t_stack	*start;
	t_stack	*tmp;

	start = *list;
	end = *list;
	tmp = NULL;
	if (*list == NULL || (*list)->next == NULL)
		return ;
	while (end->next != NULL)
	{
		tmp = end;
		end = end->next;
	}
	end->next = start;
	tmp->next = NULL;
	*list = end;
}

void	rrb(t_stack **list)
{
	t_stack	*end;
	t_stack	*start;
	t_stack	*tmp;

	start = *list;
	end = *list;
	tmp = NULL;
	if (*list == NULL || (*list)->next == NULL)
		return ;
	while (end->next != NULL)
	{
		tmp = end;
		end = end->next;
	}
	end->next = start;
	tmp->next = NULL;
	*list = end;
}

void	rrr(t_stack **a, t_stack **b)
{
	if (*a != NULL && (*a)->next != NULL)
		rra(a);
	if (*b != NULL && (*b)->next != NULL)
		rrb(b);
}
