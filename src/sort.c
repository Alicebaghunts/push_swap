/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <alisharu@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-27 15:54:13 by alisharu          #+#    #+#             */
/*   Updated: 2025-03-27 15:54:13 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **list)
{
	int	first;
	int	second;
	int	third;

	first = *list -> value;
	second = first -> next -> value;
	third = second -> next -> value;
	if ((first > second) && (second < third))
		sa(list);
	else if ((first > second) && (first > third) && (third < second))
	{
		ra(list);
		sa(list);
	}
	else if ((first < second) && (second > third) && (third > first))
	{
		rra(list);

		sa(list);
	}
	else if ((first < second) && (first < third) && (second > third))
	{
		sa(list);
		ra(list);
	}
}
