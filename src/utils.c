
#include "push_swap.h"

int	ft_list_size(t_stack **list)
{
	int count;
	t_stack *tmp;

	tmp = *list;
	if (tmp == NULL)
		return (0);

	count = 0;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}


t_stack	*ft_new_list(int content)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}


t_stack	*ft_last_node(t_stack *lst)
{
	t_stack	*tmp;

	tmp = lst;
	if (lst == NULL)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

int find_min_pos(t_stack **list)
{
    t_stack *tmp;
    int min;
    int pos;
    int min_pos;

    if (*list == NULL)
        return (-1);

    min = (*list)->content;
    pos = 0;
    min_pos = 0;
    tmp = *list;
    while (tmp)
    {
        if (tmp->content < min)
        {
            min = tmp->content;
            min_pos = pos;
        }
        tmp = tmp->next;
        pos++;
    }
    return (min_pos);
}

void	min_pos_rev(t_stack **list)
{
	int	min_pos;

    min_pos = find_min_pos(list);
    if (min_pos == 0)
        return;

    while (min_pos != 0)
    {
        if (min_pos > 0)
        {
            ra(list);
            min_pos--;
        }
        else
        {
            rra(list);
			min_pos++;
		}
	}
}

