/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelkabia <eelkabia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:42:31 by eelkabia          #+#    #+#             */
/*   Updated: 2025/01/02 11:08:12 by eelkabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

t_stack				*init_stack(int argc, char **argv, t_stack *a);
void				push_to_stack(t_stack **stack, int value);
// operations push
void				push_to_stack_a(t_stack **a, t_stack **b);
void				push_to_stack_b(t_stack **a, t_stack **b);
// operations rotate
void				rotate_stack_a(t_stack **a);
void				rotate_stack_b(t_stack **b);
void				rotate_stack_ab(t_stack **a, t_stack **b);
// operations reverse rotate
void				reverse_rotate_stack_a(t_stack **a);
void				reverse_rotate_stack_b(t_stack **b);
void				reverse_rotate_stack_ab(t_stack **a, t_stack **b);
// operations swap
void				swap_stack_a(t_stack **a);
void				swap_stack_b(t_stack **b);
void				swap_stack_ab(t_stack **a, t_stack **b);
// error
void				error_msg(void);
// check
void				check_input(int argc, char **argv);
// free
void				free_stack(t_stack *stack);

#endif
