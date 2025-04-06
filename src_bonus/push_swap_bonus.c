/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alice <alice@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:21:47 by alisharu          #+#    #+#             */
/*   Updated: 2025/04/06 15:58:28 by alice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	error_handling(void)
{
	printf("Error\n");
	exit(ERROR_INVALID_INPUT);
}

int	is_sorted(t_stack **list)
{
	t_stack	*tmp;

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
		checking_argument(arr[i]);
		i++;
	}
	ft_free_matrix(arr);
	return (1);
}
