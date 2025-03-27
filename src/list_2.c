/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <alisharu@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-27 12:56:57 by alisharu          #+#    #+#             */
/*   Updated: 2025-03-27 12:56:57 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_list_size(t_stack **list)
{
	int		count;
	t_stack	*tmp;

	tmp = *list;
	count = 0;
	if (tmp == NULL)
		return (0);
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

void	init_indexs_list(t_stack **list, int *arr, int size)
{
	int		index;
	t_stack	*tmp;

	tmp = *list;
	index = 0;
	while (tmp != NULL)
	{
		index = 0;
		while (index < size)
		{
			if (tmp->content == arr[index])
				tmp->index = index;
			index++;
		}
		tmp = tmp->next;
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
