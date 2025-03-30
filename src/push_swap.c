/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alice <alice@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:45:18 by alisharu          #+#    #+#             */
/*   Updated: 2025/03/28 17:09:35 by alice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handling(void)
{
	printf("Error\n");
}

int	push_swap(char *str)
{
	int		i;
	char	**arr;

	i = 0;
	if (str[0] == '\0')
	{
		error_handling();
		exit(ERROR_INVALID_INPUT);
	}
	arr = ft_split(str, ' ');
	while (arr[i] != NULL)
	{
		checking_argument(arr[i]);
		i++;
	}
	ft_free_matrix(arr);
	return (1);
}

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    int i;
    int *arr;
    int size;
    // int n = 2;

    a = NULL;
    b = NULL;
    i = 1;

    if (argc == 1)
        return (0);

    while (i < argc)
    {
        push_swap(argv[i]);
        i++;
    }

    i = 1;
    while (i < argc)
    {
        a = add_and_check_dublicate(a, argv[i]);
        i++;
    }

    if (is_sorted(&a))
        return (0);

    size = ft_list_size(&a);
    arr = list_to_arr(&a);

    init_indexs_list(&a, arr, size);
	
	printf("index - ");
	print_index(&a);
    printf("\n");

    printf("Original a stack: ");
    print_stack(&a);
    printf("Original b stack: ");
    print_stack(&b); 
    printf("\n");

	if (argc == 3)
		sort_two(&a);
	else if (argc == 4)
		sort_three(&a);
	else if (argc == 5)
		sort_four(&a,&b);
	else if (argc == 6)
		sort_five(&a,&b);
	else
	{
		make_butterfly(&a, &b, 1);
	}
	printf("Result a stack: ");
    print_stack(&a);
    printf("Result b stack: ");
    print_stack(&b); 
	printf("\n");


    pxik(&a, &b, size);

    t_stack *tmp = a;
    printf("Result a stack: ");
    print_stack(&tmp);
    printf("Result b stack: ");
    print_stack(&b); 
	printf("\n");
    return (0);
}