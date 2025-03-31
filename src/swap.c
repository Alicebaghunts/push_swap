/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <alisharu@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-27 12:55:57 by alisharu          #+#    #+#             */
/*   Updated: 2025-03-27 12:55:57 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sa(t_stack **list)
{
	t_stack	*swp1;
	t_stack	*swp2;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	swp1 = *list;
	swp2 = (*list)->next;
	*list = swp2;
	swp1->next = swp2->next;
	swp2->next = swp1;
	ft_putstr("sa\n");
}

void	sb(t_stack **list)
{
	t_stack	*swp1;
	t_stack	*swp2;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	swp1 = *list;
	swp2 = (*list)->next;
	*list = swp2;
	swp1->next = swp2->next;
	swp2->next = swp1;
	ft_putstr("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	if (*a != NULL && (*a)->next != NULL)
		sa(a);
	if (*b != NULL && (*b)->next != NULL)
		sb(b);
	ft_putstr("ss\n");
}
