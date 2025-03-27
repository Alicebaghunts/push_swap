/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <alisharu@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-27 12:59:23 by alisharu          #+#    #+#             */
/*   Updated: 2025-03-27 12:59:23 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	pa(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	tmp = *src;
	if (*src == NULL)
		return ;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
}

void	pb(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	tmp = *src;
	if (*src == NULL)
		return ;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
}
