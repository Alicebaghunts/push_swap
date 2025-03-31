/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <alisharu@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-27 12:58:34 by alisharu          #+#    #+#             */
/*   Updated: 2025-03-27 12:58:34 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

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
	ft_putstr("rra\n");
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
	ft_putstr("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	if (*a != NULL && (*a)->next != NULL)
		rra(a);
	if (*b != NULL && (*b)->next != NULL)
		rrb(b);
	ft_putstr("rrr\n");
}
