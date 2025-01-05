/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelkabia <eelkabia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:24:05 by eelkabia          #+#    #+#             */
/*   Updated: 2025/01/01 18:48:38 by eelkabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

typedef struct s_range
{
	int				*sorted_array;
	int				size;
	int				start;
	int				end;
	int				offset;
}					t_range;

void				push_to_stack(t_stack **stack, int value);
t_stack				*init_stack(int argc, char **argv, t_stack *a);
int					size_stack(t_stack *stack);
// small sort
void				small_sort(t_stack **a, t_stack **b, int size);
void				sort_two(t_stack **a);
void				sort_three(t_stack **a);
void				sort_four(t_stack **a, t_stack **b);
void				sort_five(t_stack **a, t_stack **b);
int					find_min_position(t_stack **a);
void				move_min_to_top(t_stack **a, t_stack **b, int min_pos);
// large sort
void				large_sort(t_stack **a, t_stack **b, int size);
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

void				print_stack(t_stack *stack);

// array_utils
int					*stack_to_array(t_stack *stack, int size);
void				sorted_array(int *array, int size);
/*// push_elements_to_b*/
void				push_element_to_b(t_stack **a, t_stack **b, t_range *range);
void				next_chunk(t_range *range);
/*// push_elements_to_a*/
void				push_elements_to_a(t_stack **a, t_stack **b);

void				error_msg(void);
void				check_input(int argc, char **argv);

#endif
