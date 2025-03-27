#include "push_swap.h"

void error_handling()
{
    printf("Error\n");
}

int push_swap(char *str)
{
    int i = 0;
    char **arr;

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
    return 1;
}

int main (int argc, char **argv)
{
    int i;
    t_stack *head;

    i = 1;
    if (argc == 1)
        return (0);

    while (i < argc)
    {
        push_swap(argv[i]);
        i++;
    }

    head = NULL;
    i = 1;
    while (i < argc)
    {
        head = add_and_check_dublicate(head, argv[i]);
        i++;
    }
t_stack * last = head;
// 2 list
t_stack *list2 = malloc(sizeof(t_stack));
list2->content = 10;
list2->next = NULL;

for (int i = 1; i < 6; i++) {
    ft_add_back_list(&list2, i + 10);
}

printf("a ....");
print_list(&last);
printf("\n");
int *arr = list_to_arr(&last);
int size = ft_list_size(&last);
printf("arr elems ....");
for(int i = 0; i < size; i++)
{
    printf("%d, ", arr[i]);
}

printf("\n");
printf("\n");

ft_arr_sort(arr,size);
printf("sort arr elems ....");
for(int i = 0; i < size; i++)
{
    printf("%d, ", arr[i]);
}
printf("\n");


printf("\n");

init_indexs_list(&last,arr,size);
t_stack *tmp = last;
printf("index list....");
for(int i = 0; i < size; i++)
{
    printf("%d, ", tmp -> index);
    tmp = tmp -> next; 

}

printf("\n");



// printf("Before sa_sb on list2 and last:\n");
// printf("a ");
// print_list(&last);
// printf("b ");
// print_list(&list2);

// rrr(&list2, &last);

// printf("After sa_sb on list2 and last:\n");
// printf("a ");
// print_list(&last);
// printf("b ");
// print_list(&list2);
    return (0);
}
