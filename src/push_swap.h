/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-02 10:25:17 by alisharu          #+#    #+#             */
/*   Updated: 2025-04-02 10:25:17 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# define ERROR_INVALID_INPUT 2
# define ERROR_MEMORY_ALLOCATION 3

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}	t_stack;

void	error_handling(void);
void	find_max_and_push_a(t_stack **a, t_stack **b, int size);
void	find_max_and_push_b(t_stack **a, t_stack **b, int size);
void	ft_add_back_list(t_stack **lst, int content);
void	ft_arr_sort(int *arr, int size);
void	ft_free_matrix(char **arr);
void	ft_free_stack(t_stack *stack);
void	init_indexs_list(t_stack **list, int *arr, int size);
void	make_butterfly(t_stack **a, t_stack **b, int n);
void	pa(t_stack **src, t_stack **dest);
void	pb(t_stack **src, t_stack **dest);
void	print_list(t_stack **list);
void	ra(t_stack **list);
void	rb(t_stack **list);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **list);
void	rrb(t_stack **list);
void	rrr(t_stack **a, t_stack **b);
void	sa(t_stack **list);
void	sb(t_stack **list);
void	ss(t_stack **a, t_stack **b);
void	checking_argument(char *arg);
int		push_swap(char *str);
int		checking_list(t_stack **list, int content);
int		ft_list_size(t_stack **list);
int		*list_to_arr(t_stack **list);
void	rotate_to_max(t_stack **a, int i, int size);
void	rotate_to_max_b(t_stack **b, int i, int size);
void	sort_three(t_stack **list);
void	print_stack(t_stack **list);
void	sort_two(t_stack **list);
int		is_sorted(t_stack **list);
int		find_min_pos(t_stack **list);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
void	min_pos_rev(t_stack **list);
void	pxik(t_stack **a, t_stack **b, int size);
void	print_index(t_stack **list);
t_stack	*ft_last_node(t_stack *lst);
t_stack	*ft_new_list(int content);
t_stack	*add_and_check_dublicate(t_stack *head, char *str);
int		optimaizer(int size);

#endif