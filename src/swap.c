#include "push_swap.h"

void    sa(t_stack **list)
{
    t_stack *swp1;
    t_stack *swp2;

    if (*list == NULL || (*list)->next == NULL) {
        return;
    }

    swp1 = *list;
    swp2 = (*list)->next;

    *list = swp2;
    swp1->next = swp2->next;
    swp2->next = swp1;
}

void    sb(t_stack **list)
{
    t_stack *swp1;
    t_stack *swp2;

    if (*list == NULL || (*list)->next == NULL) {
        return;
    }

    swp1 = *list;
    swp2 = (*list)->next;

    *list = swp2;
    swp1->next = swp2->next;
    swp2->next = swp1;
}


void    ss(t_stack **a, t_stack **b)
{
    if ((*a != NULL && (*a)->next != NULL))
        sa(a);
    if ((*b != NULL && (*b)->next != NULL))
        sb(b);
}