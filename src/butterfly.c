/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <alisharu@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-27 12:29:58 by alisharu          #+#    #+#             */
/*   Updated: 2025-03-27 12:29:58 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rotate_to_max(t_stack **a, int i, int size)
{
	if (i > size - i - 1)
	{
		while (i++ != size)
			rra(a);
	}
	else
	{
		while (i-- > 0)
			ra(a);
	}
}

void	find_max_and_push_b(t_stack **a, t_stack **b, int size)
{
	int		i;
	t_stack	*lst;

	i = 0;
	lst = *a;
	while (lst->index != size - 1)
	{
		lst = lst->next;
		i++;
		if (lst == *a)
			return ;
	}
	rotate_to_max(a, i, size);
	pb(a, b);
}

void	rotate_to_max_b(t_stack **b, int i, int size)
{
	if (i > size - i - 1)
	{
		while (i++ != size)
			rrb(b);
	}
	else
	{
		while (i-- > 0)
			rb(b);
	}
}

void	find_max_and_push_a(t_stack **a, t_stack **b, int size)
{
	int		i;
	t_stack	*lst;

	i = 0;
	lst = *b;
	while (lst->index != size - 1)
	{
		lst = lst->next;
		i++;
		if (lst == *b)
			return ;
	}
	rotate_to_max_b(b, i, size);
	pa(a, b);
}

void	make_butterfly(t_stack **a, t_stack **b, int n)
{
	int		counter;
	t_stack	*lst;

	counter = 0;
	lst = *a;
	while (*a != NULL)
	{
		if (lst->index <= counter)
		{
			pb(a, b);
			rb(b);
			++counter;
		}
		else if (lst->index <= counter + n)
		{
			pb(a, b);
			++counter;
		}
		else
			ra(a);
		lst = *a;
	}
}
