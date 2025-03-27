#include "push_swap.h"

void    ra(t_stack **list)
{
    t_stack *start;
    t_stack *end;
    t_stack *tmp;

    if (*list == NULL || (*list)->next == NULL)
        return;

    start = *list;
    end = *list;

    while (end->next != NULL) {
        tmp = end;
        end = end->next;
    }

    tmp->next = start;
    end->next = start->next;
    start->next = NULL;
    *list = end;
}

void    rb(t_stack **list)
{
    t_stack *start;
    t_stack *end;
    t_stack *tmp;

    if (*list == NULL || (*list)->next == NULL)
        return;

    start = *list;
    end = *list;

    while (end->next != NULL) {
        tmp = end;
        end = end->next;
    }

    tmp->next = start;
    end->next = start->next;
    start->next = NULL;
    *list = end;
}


void    rr(t_stack **a, t_stack **b)
{
    if ((*a != NULL && (*a)->next != NULL))
        ra(a);
    if ((*b != NULL && (*b)->next != NULL))
        rb(b);
}
