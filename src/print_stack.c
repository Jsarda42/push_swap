
#include "push_swap.h"
void	print_stack(t_list *stack)
{
	while (stack)
	{
		ft_printf("%d\n", (stack)->data);
		stack = stack->next;
	}
}
