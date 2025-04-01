
#include "push_swap_bonus.h"
#include "../src/push_swap.h"

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
		sa(a);
	else if (strcmp_check(input, "sb\n") == 0)
		sb(b);
	else if (strcmp_check(input, "ss\n") == 0)
		ss(a, b);
	else if (strcmp_check(input, "pa\n") == 0)
		pa(a, b);
	else if (strcmp_check(input, "pb\n") == 0)
		pb(a, b);
	else if (strcmp_check(input, "ra\n") == 0)
		ra(a);
	else if (strcmp_check(input, "rb\n") == 0)
		rb(b);
	else if (strcmp_check(input, "rra\n") == 0)
		rra(a);
	else if (strcmp_check(input, "rrb\n") == 0)
		rrb(b);
	else
	{
		free(input);
		return (0);
	}
	free(input);
	return (1);
}

void	read_from_stdin(t_stack **a, t_stack **b)
{
	char	*input;

	input = get_next_line(0);
	while (input)
	{
		if (exec_instruction(a, b, input) == 0)
			error_handling();
		input = get_next_line(0);
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
