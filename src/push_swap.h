/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:36:33 by jsarda            #+#    #+#             */
/*   Updated: 2023/12/29 11:48:50 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}					t_list;

typedef enum
{
	false = 0,
	true = 1
}					bool;

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
int					nothing_to_be_done(t_list **stack);
void				args_parsing(t_list **stack, int argc, char **argv);
void				clear_list(t_list **stack);

#endif
