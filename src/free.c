/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alice <alice@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:44:09 by alisharu          #+#    #+#             */
/*   Updated: 2025/03/28 17:14:59 by alice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_matrix(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

int	generate_chunk(int size)
{
	int	chunk_size;

	if (size <= 50)
		chunk_size = 5;
	else if (size <= 100)
		chunk_size = 10;
	else
		chunk_size = 20;
	return (chunk_size);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	while (*b != NULL)
	{
		find_max_and_push_a(a, b, ft_list_size(b));
		pa(b, a);
	}
}