/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alice <alice@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:24:39 by alisharu          #+#    #+#             */
/*   Updated: 2025/04/03 15:06:15 by alice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] == ' ')
		i++;
	if (str[i] != '\0')
		return ;
	error_handling();
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
	is_space(str);
	arr = ft_split(str, ' ');
	while (arr[i] != NULL)
	{
		checking_argument(arr[i]);
		i++;
	}
	ft_free_matrix(arr);
	return (1);
}

void	sort(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
	else
		make_butterfly(a, b, optimaizer(size));
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*arr;
	int		size;
	int		i;

	a = NULL;
	b = NULL;
	i = 1;
	if (argc == 1)
		return (0);
	while (i < argc)
		push_swap(argv[i++]);
	i = 1;
	while (i < argc)
		a = add_and_check_dublicate(a, argv[i++]);
	if (is_sorted(&a))
		return (ft_free_stack(a), 0);
	size = ft_list_size(&a);
	arr = list_to_arr(&a);
	init_indexs_list(&a, arr, size);
	sort(&a, &b, size);
	pxik(&a, &b, size);
	return (ft_free_stack(b), ft_free_stack(a), 0);
}
