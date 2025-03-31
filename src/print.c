/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <alisharu@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-27 13:32:34 by alisharu          #+#    #+#             */
/*   Updated: 2025-03-27 13:32:34 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	print_list(t_stack **list)
{
	t_stack	*tmp;

	tmp = *list;
	while (tmp != NULL)
	{
		printf("%d -> ", tmp->content);
		tmp = tmp->next;
	}
	printf("NULL\n");
}

void	print_stack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		printf("%d ", tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
}

void	print_index(t_stack **list)
{
	t_stack	*temp;

	temp = *list;
	while (temp)
	{
		printf("%d ", temp->index);
		temp = temp->next;
	}
	printf("\n");
}
