#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "../libft/libft.h"
#define ERROR_INVALID_INPUT 2
#define ERROR_MEMORY_ALLOCATION 3

#

typedef struct s_stack
{
    int             content;
    int             index;
    struct s_stack *next;
}   t_stack;

void     print_list(t_stack **list);
void    error_handling(void);
int     push_swap(char *str);
void    checking_argument(char *arg);
void    ft_free_stack(t_stack *stack);
void     ft_free_matrix(char**arr);
void    checking_argument(char *arg);
void	ft_add_back_list(t_stack **lst, int content);
int     checking_list(t_stack **list, int content);
t_stack	*ft_new_list(int content);
t_stack *add_and_check_dublicate(t_stack *head, char *str);
t_stack	*ft_last_node(t_stack *lst);

void    sa(t_stack **list);
void    sb(t_stack **list);
void    ss(t_stack **a, t_stack **b);
void    pa(t_stack **src, t_stack **dest);
void    pb(t_stack **src, t_stack **dest);
void    ra(t_stack **list);
void    rb(t_stack **list);
void    rr(t_stack **a, t_stack **b);
void    rra(t_stack **list);
void    rrb(t_stack **list);
void    rrr(t_stack **a, t_stack **b);

void ft_arr_sort(int *arr, int size);
int *list_to_arr(t_stack **list);
int ft_list_size(t_stack **list);
void    init_indexs_list(t_stack **list, int* arr, int size);

void	find_max_and_push_b(t_stack **a, t_stack **b, int size);
void	find_max_and_push_a(t_stack **a, t_stack **b, int size);
void	butterfly_algo(t_stack **a, t_stack **b, int size);
void	make_butterfly(t_stack **a, t_stack **b, int n);
void	sort_stack(t_stack **a, t_stack **b);

#endif