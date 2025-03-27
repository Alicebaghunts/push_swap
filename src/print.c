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
