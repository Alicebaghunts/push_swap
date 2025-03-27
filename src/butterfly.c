
#include "push_swap.h"

int generate_chunk(int size)
{
    int chunk_size;

    if (size <= 50)
        chunk_size = 5;
    else if (size <= 100)
        chunk_size = 10;
    else
        chunk_size = 20;

    return chunk_size;
}


void	find_max_and_push_b(t_stack **a, t_stack **b, int size)
{
	int i;
	int flag;
	t_stack *lst;

	i = 0;
	flag = 0;
	lst = *a;
	while (!flag)
	{
		if (lst->index == size - 1)
		{
			if (i > size - i - 1)
			{
				while (i++ != size)
					rra(a);
			}
			else
			{
				while (i-- > 0)
					ra(a);
			}
			pb(a, b);
			break ;
		}
		lst = lst->next;
		++i;
		if (lst == *a)
			flag = 1;
	}
}

void	find_max_and_push_a(t_stack **a, t_stack **b, int size)
{
	int i;
	int flag;
	t_stack *lst;

	i = 0;
	flag = 0;
	lst = *b;
	while (!flag)
	{
		if (lst->index == size - 1)
		{
			if (i > size - i - 1)
			{
				while (i++ != size)
					rrb(b);
			}
			else
			{
				while (i-- > 0)
					rb(b);
			}
			pa(a, b);
			break ;
		}
		lst = lst->next;
		++i;
		if (lst == *b)
			flag = 1;
	}
}

void sort_stack(t_stack **a, t_stack **b)
{
    while (*b != NULL)
    {
        find_max_and_push_a(a, b, ft_list_size(b));
        pa(b, a);
    }
}

void	make_butterfly(t_stack **a, t_stack **b, int n)
{
	int counter;
	t_stack *lst;

	counter = 0;
	lst = *a;
	while (*a != NULL)
	{
		if (lst->index <= counter)
		{
			pb(a, b);
			rb(b);
			++counter;
		}
		else if (lst->index <= counter + n)
		{
			pb(a, b);
			++counter;
		}
		else
			ra(a);
		lst = *a;
	}
}

void	butterfly_algo(t_stack **a, t_stack **b, int size)
{
	int n;

	n = generate_chunk(size);
	make_butterfly(a, b, n);
	sort_stack(a, b);
}
