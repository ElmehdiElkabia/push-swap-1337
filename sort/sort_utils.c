/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelkabia <eelkabia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:30:11 by eelkabia          #+#    #+#             */
/*   Updated: 2025/01/01 15:47:51 by eelkabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	small_sort(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
}

int	find_min_position(t_stack **a)
{
	int		min_pos;
	int		min;
	t_stack	*current;
	int		i;

	min_pos = 0;
	min = (*a)->value;
	current = *a;
	i = 0;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = i;
		}
		current = current->next;
		i++;
	}
	return (min_pos);
}

void	move_min_to_top(t_stack **a, t_stack **b, int min_pos)
{
	if (min_pos == 1)
		rotate_stack_a(a);
	else if (min_pos == 2)
	{
		rotate_stack_a(a);
		rotate_stack_a(a);
	}
	else if (min_pos == 3)
	{
		reverse_rotate_stack_a(a);
		reverse_rotate_stack_a(a);
	}
	else if (min_pos == 4)
		reverse_rotate_stack_a(a);
	push_to_stack_b(a, b);
}
