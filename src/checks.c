/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <alisharu@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-27 12:41:45 by alisharu          #+#    #+#             */
/*   Updated: 2025-03-27 12:41:45 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	checking_argument(char *arg)
{
	int		num;
	char	*itoa_num;

	num = 0;
	if (arg[0] == '\0')
	{
		error_handling();
		exit(ERROR_INVALID_INPUT);
	}
	if ((arg[0] == '0') && (arg[1] == '\0'))
		return ;
	num = ft_atoi(arg);
	if (num == 0)
	{
		error_handling();
		exit(ERROR_INVALID_INPUT);
	}
	printf("%d\n",num);
	itoa_num = ft_itoa(num);
	if (ft_strcmp(arg, itoa_num) != 0)
	{
		free(itoa_num);
		error_handling();
		exit(ERROR_INVALID_INPUT);
	}
	free(itoa_num);
}

int	checking_list(t_stack **list, int content)
{
	t_stack	*tmp;

	tmp = *list;
	while (tmp != NULL)
	{
		if (tmp->content == content)
		{
			ft_free_stack(*list);
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

t_stack	*add_and_check_dublicate(t_stack *head, char *str)
{
	char	**arr;
	int		i;

	arr = ft_split(str, ' ');
	i = 0;
	while (arr[i] != NULL)
	{
		if (checking_list(&head, ft_atoi(arr[i])) == 0)
		{
			ft_free_matrix(arr);
			error_handling();
			exit(ERROR_INVALID_INPUT);
		}
		ft_add_back_list(&head, ft_atoi(arr[i]));
		i++;
	}
	ft_free_matrix(arr);
	return (head);
}
