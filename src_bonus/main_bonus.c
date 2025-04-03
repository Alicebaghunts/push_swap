/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alice <alice@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:12:38 by alisharu          #+#    #+#             */
/*   Updated: 2025/04/03 15:15:29 by alice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	strcmp_check(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	exec_instruction(t_stack **a, t_stack **b, char *input)
{
	if (strcmp_check(input, "sa\n") == 0)
		return (sa(a), 1);
	else if (strcmp_check(input, "sb\n") == 0)
		return (sb(b), 1);
	else if (strcmp_check(input, "ss\n") == 0)
		return (ss(a, b), 1);
	else if (strcmp_check(input, "pa\n") == 0)
		return (pa(a, b), 1);
	else if (strcmp_check(input, "pb\n") == 0)
		return (pb(a, b), 1);
	else if (strcmp_check(input, "ra\n") == 0)
		return (ra(a), 1);
	else if (strcmp_check(input, "rb\n") == 0)
		return (rb(b), 1);
	else if (strcmp_check(input, "rra\n") == 0)
		return (rra(a), 1);
	else if (strcmp_check(input, "rrb\n") == 0)
		return (rrb(b), 1);
	return (0);
}

void	read_from_stdin(t_stack **a, t_stack **b)
{
	char	*input;

	while (1)
	{
		input = get_next_line(0);
		if (!input)
			break ;
		if (exec_instruction(a, b, input) == 0)
			error_handling();
		free(input);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	i = 1;
	while (i < argc)
		push_swap(argv[i++]);
	i = 1;
	while (i < argc)
		a = add_and_check_dublicate(a, argv[i++]);
	read_from_stdin(&a, &b);
	if (is_sorted(&a) && !b)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (ft_free_stack(a), ft_free_stack(b), 0);
}
