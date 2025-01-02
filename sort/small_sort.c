/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelkabia <eelkabia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:29:31 by eelkabia          #+#    #+#             */
/*   Updated: 2025/01/01 15:47:33 by eelkabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two(t_stack **a)
{
	if (!a || !(*a) || !((*a)->next))
		return ;
	if ((*a)->value > (*a)->next->value)
		swap_stack_a(a);
}

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		swap_stack_a(a);
	else if (first > second && second > third)
	{
		swap_stack_a(a);
		reverse_rotate_stack_a(a);
	}
	else if (first > second && second < third && first > third)
		rotate_stack_a(a);
	else if (first < second && second > third && first < third)
	{
		swap_stack_a(a);
		rotate_stack_a(a);
	}
	else if (first < second && second > third && first > third)
		reverse_rotate_stack_a(a);
}

void	sort_four(t_stack **a, t_stack **b)
{
	int	min_pos;

	min_pos = find_min_position(a);
	if (min_pos == 1)
		rotate_stack_a(a);
	else if (min_pos == 2)
	{
		rotate_stack_a(a);
		rotate_stack_a(a);
	}
	else if (min_pos == 3)
		reverse_rotate_stack_a(a);
	push_to_stack_b(a, b);
	sort_three(a);
	push_to_stack_a(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	min_pos;

	min_pos = find_min_position(a);
	move_min_to_top(a, b, min_pos);
	min_pos = find_min_position(a);
	if (min_pos == 1)
		rotate_stack_a(a);
	else if (min_pos == 2)
	{
		rotate_stack_a(a);
		rotate_stack_a(a);
	}
	else if (min_pos == 3)
		reverse_rotate_stack_a(a);
	push_to_stack_b(a, b);
	sort_three(a);
	push_to_stack_a(a, b);
	push_to_stack_a(a, b);
}
