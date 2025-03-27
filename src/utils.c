#include "push_swap.h"

void print_list(t_stack **list)
{
    t_stack *tmp;

    tmp = *list;
    while (tmp != NULL)
    {
        printf ("%d -> ", tmp->content);
        tmp = tmp -> next;
    }
    printf("NULL\n");
}

int ft_list_size(t_stack **list)
{
    int count;
    t_stack *tmp;

    tmp = *list;
    count = 0;
    if(tmp == NULL)
        return (0);

    while (tmp != NULL)
    {
        count++;
        tmp = tmp -> next;
    }
    return count;
}


int *list_to_arr(t_stack **list)
{
    int size;
    int *arr;
    int i;
    t_stack *temp;

    temp = *list;
    if(list == NULL || *list == NULL)
        return (NULL);

    size = ft_list_size(list);
    arr = malloc(sizeof(int) * size);

    if (arr == NULL)
        exit(ERROR_MEMORY_ALLOCATION);

    i = 0;
    while (temp != NULL)
    {
        arr[i] = temp -> content;
        temp= temp -> next;
        i++;
    }
    return arr;
}

void ft_arr_sort(int *arr, int size)
{
    int i, j, temp;
    int swapped;
    i = 0;

    while (i < size - 1) {
        swapped = 0;
        j = 0;

        while (j < size - i - 1) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
            j++;
        }

        if (swapped == 0) {
            break;
        }

        i++;
    }
}

void    init_indexs_list(t_stack **list, int* arr, int size)
{
    int index;
    t_stack *tmp;

    tmp = *list;
    index = 0;

    while (tmp != NULL)
    {
        index = 0;
        while (index < size)
        {
            if (tmp -> content == arr[index])
            {
                tmp -> index = index;
            }
            index++;
        }
        tmp = tmp -> next;
    }
}   