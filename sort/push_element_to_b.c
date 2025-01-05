/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_element_to_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelkabia <eelkabia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:54:42 by eelkabia          #+#    #+#             */
/*   Updated: 2025/01/01 15:46:13 by eelkabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_in_range(t_stack **a, t_stack **b, t_range *range)
{
	if (!a || !b || !range)
		return ;
	while (*a)
	{
		if ((*a)->value <= range->sorted_array[range->start])
		{
			push_to_stack_b(a, b);
			rotate_stack_b(b);
			next_chunk(range);
		}
		else if ((*a)->value <= range->sorted_array[range->end])
		{
			push_to_stack_b(a, b);
			if (size_stack(*b) > 2 && (*b)->value < (*b)->next->value)
				swap_stack_b(b);
			next_chunk(range);
		}
		else
			rotate_stack_a(a);
	}
}

void	push_element_to_b(t_stack **a, t_stack **b, t_range *range)
{
	if (!a || !b || !range)
		return ;
	push_in_range(a, b, range);
}
