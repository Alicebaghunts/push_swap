/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-06 13:47:40 by alisharu          #+#    #+#             */
/*   Updated: 2025-04-06 13:47:40 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	checking_argument(char *arg)
{
	long	num;
	char	*itoa_num;

	num = 0;
	if (arg[0] == '\0')
		return (1);
	if ((arg[0] == '0') && (arg[1] == '\0'))
		return (0);
	num = ft_atol(arg);
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	itoa_num = ft_itoa((int)num);
	if (ft_strcmp(arg, itoa_num) != 0)
		return (free(itoa_num), 1);
	return (free(itoa_num), 0);
}

void	checking_list(t_stack **list, int content)
{
	t_stack	*tmp;

	tmp = *list;
	while (tmp != NULL)
	{
		if (tmp->content == content)
		{
			ft_free_stack(*list);
			error_handling();
		}
		tmp = tmp->next;
	}
}

t_stack	*add_and_check_dublicate(t_stack *head, char *str)
{
	char	**arr;
	int		i;

	arr = ft_split(str, ' ');
	if (arr == NULL)
		error_handling();
	i = 0;
	while (arr[i] != NULL)
	{
		checking_list(&head, ft_atoi(arr[i]));
		ft_add_back_list(&head, ft_atoi(arr[i]));
		i++;
	}
	ft_free_matrix(arr);
	return (head);
}

void	init_indexs_list(t_stack **list, int *arr, int size)
{
	int		i;
	t_stack	*tmp;

	ft_arr_sort(arr, size);
	tmp = *list;
	while (tmp != NULL)
	{
		i = 0;
		while (i < size)
		{
			if (tmp->content == arr[i])
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
	free(arr);
}

void	ft_add_back_list(t_stack **lst, int content)
{
	t_stack	*tmp;
	t_stack	*new_node;

	if (lst == NULL)
		return ;
	new_node = ft_new_list(content);
	if (new_node == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new_node;
		return ;
	}
	tmp = ft_last_node(*lst);
	if (tmp != NULL)
		tmp -> next = new_node;
}
