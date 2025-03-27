#include "push_swap.h"

void ft_free_matrix(char** arr)
{
    int i = 0;
    while (arr[i] != NULL)
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

void ft_free_stack(t_stack *stack)
{
    t_stack *temp;
    while (stack != NULL)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}

t_stack *ft_new_list(int content)
{
    t_stack *new_node;
    new_node = malloc(sizeof(t_stack));
    if (new_node == NULL)
        return (NULL);
    new_node->content = content;
    new_node->next = NULL;
    return (new_node);
}

void ft_add_back_list(t_stack **lst, int content)
{
    t_stack *tmp;
    t_stack *new_node;

    if (lst == NULL)
        return;
    new_node = ft_new_list(content);
    if (new_node == NULL)
        return;
    if (*lst == NULL)
    {
        *lst = new_node;
        return;
    }
    tmp = ft_last_node(*lst);
    if (tmp != NULL)
        tmp->next = new_node;
}

t_stack *ft_last_node(t_stack *lst)
{
    t_stack *tmp;
    tmp = lst;
    if (lst == NULL)
        return (NULL);
    while (tmp->next != NULL)
        tmp = tmp->next;
    return (tmp);
}

