/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:36:33 by jsarda            #+#    #+#             */
/*   Updated: 2024/01/04 12:51:41 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}					t_list;

typedef enum s_bool
{
	false = 0,
	true = 1
}					t_bool;

// rules functions
int					sa(t_list **stack_a);
int					sb(t_list **stack_b);
int					pa(t_list **stack_b, t_list **stack_a);
int					pb(t_list **stack_a, t_list **stack_b);
int					ra(t_list **stack);
int					rb(t_list **stack);
int					rr(t_list **stack_a, t_list **stack_b);
int					rra(t_list **stack_a);
int					rrb(t_list **stack_b);
int					rrr(t_list **stack_a, t_list **stack_b);

// lst utils functions
int					ft_lstsize(t_list *stack);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(int value);

// utils
void				error_message(char *message, t_list **stack);
void				succes_message(char *message, t_list **stack_a,
						t_list **stack_b);
void				args_parsing(t_list **stack, int argc, char **argv);
t_bool				is_sorted(t_list *stack_a);
int					ft_find_index(t_list *stack, int nbr);
int					get_max(t_list *stack);
int					get_min(t_list *stack);

// free function
void				clear_list(t_list **stack);
void				ft_free(char **str);
void				free_stack(t_list **stack);
void				free_args(int argc, t_list **stack, char **args,
						char *message);

// sort function
void				sort_3(t_list **stack_a);
void				sort(t_list **stack_a, t_list **stack_b);
#endif
