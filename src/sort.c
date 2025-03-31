/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alice <alice@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:54:13 by alisharu          #+#    #+#             */
/*   Updated: 2025/03/30 11:16:27 by alice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_three(t_stack **list)
{
	int	a;
	int	b;
	int	c;

	a = (*list)->index;
	b = (*list)->next->index;
	c = (*list)->next->next->index;
	if (a > b && a < c)
		sa(list);
	else if (a < b && a > c)
		rra(list);
	else if (a > b && a > c && b < c)
		ra(list);
	else if (a > b && a > c && b > c)
	{
		sa(list);
		rra(list);
	}
	else if (a < b && a < c && b > c)
	{
		sa(list);
		ra(list);
	}
}

void	sort_two(t_stack **list)
{
	int	first;
	int	second;

	first = (*list)->content;
	second = (*list)->next->content;
	if (first > second)
		sa(list);
}

void	sort_four(t_stack **a, t_stack **b)
{
	if (is_sorted(a))
		return ;
	min_pos_rev(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
	if (!is_sorted(a))
		ra(a);
	return ;
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	count;

	count = 2;
	if (is_sorted(a))
		return ;
	while (count != 0)
	{
		min_pos_rev(a);
		pb(a, b);
		count--;
	}
	sort_three(a);
	pa(a, b);
	pa(a, b);
	return ;
}
