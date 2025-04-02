/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-02 10:11:55 by alisharu          #+#    #+#             */
/*   Updated: 2025-04-02 10:11:55 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap_bonus.h"

int	*list_to_arr(t_stack **list)
{
	int		size;
	int		*arr;
	int		i;
	t_stack	*temp;

	temp = *list;
	if (list == NULL || *list == NULL)
		return (NULL);
	size = ft_list_size(list);
	arr = malloc(sizeof(int) * size);
	if (arr == NULL)
		exit(ERROR_MEMORY_ALLOCATION);
	i = 0;
	while (temp != NULL)
	{
		arr[i] = temp->content;
		temp = temp->next;
		i++;
	}
	return (arr);
}

void	ft_arr_sort(int *arr, int size)
{
	int		i;
	int		j;
	int		temp;
	int		swapped;

	i = 0;
	while (i < size - 1)
	{
		swapped = 0;
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = 1;
			}
			j++;
		}
		if (swapped == 0)
			break ;
		i++;
	}
}
