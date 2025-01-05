/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_element_to_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelkabia <eelkabia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:22:32 by eelkabia          #+#    #+#             */
/*   Updated: 2025/01/01 15:48:54 by eelkabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	find_max_value(t_stack *stack)
{
	int	max_value;

	max_value = stack->value;
	while (stack)
	{
		if (stack->value > max_value)
			max_value = stack->value;
		stack = stack->next;
	}
	return (max_value);
}

static int	get_postition(t_stack *stack, int max_value)
{
	int	postition;

	postition = 0;
	while (stack)
	{
		if (stack->value == max_value)
			return (postition);
		postition++;
		stack = stack->next;
	}
	return (postition);
}

void	push_elements_to_a(t_stack **a, t_stack **b)
{
	int	max_value;
	int	pos;
	int	size;

	if (!a || !b)
		return ;
	while (*b)
	{
		max_value = find_max_value(*b);
		pos = get_postition(*b, max_value);
		size = size_stack(*b);
		if (pos <= size / 2)
		{
			while ((*b)->value != max_value)
				rotate_stack_b(b);
		}
		else
		{
			while ((*b)->value != max_value)
				reverse_rotate_stack_b(b);
		}
		push_to_stack_a(a, b);
		if (*b && (*b)->value > (*a)->value)
			rotate_stack_a(a);
	}
}
