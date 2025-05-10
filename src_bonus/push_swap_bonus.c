/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-06 13:46:44 by alisharu          #+#    #+#             */
/*   Updated: 2025-04-06 13:46:44 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	error_handling(void)
{
	ft_putstr("Error\n");
	exit(ERROR_INVALID_INPUT);
}

int	is_sorted(t_stack **list)
{
	t_stack	*tmp;

	if (!*list)
		return (0);
	tmp = *list;
	while (tmp -> next != NULL)
	{
		if (tmp -> content > tmp->next -> content)
			return (0);
		tmp = tmp -> next;
	}
	return (1);
}

int	push_swap(char *str)
{
	int		i;
	char	**arr;

	i = 0;
	if (str[0] == '\0')
		error_handling();
	arr = ft_split(str, ' ');
	while (arr[i] != NULL)
	{
		if (checking_argument(arr[i++]) == 1)
		{
			ft_free_matrix(arr);
			error_handling();
		}
	}
	ft_free_matrix(arr);
	return (1);
}
