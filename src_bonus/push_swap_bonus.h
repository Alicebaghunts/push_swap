# ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H


# include "../src/push_swap.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

int		strcmp_check(char *s1, char *s2);
int		exec_instruction(t_stack **a, t_stack **b, char *input);
void	read_from_stdin(t_stack **a, t_stack **b);

#endif