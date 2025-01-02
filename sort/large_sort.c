/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelkabia <eelkabia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:29:28 by eelkabia          #+#    #+#             */
/*   Updated: 2025/01/01 15:48:36 by eelkabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_offset(int size)
{
	if (size <= 100)
		return (size / 6);
	else if (size <= 500)
		return (size / 16);
	else
		return (size / 20);
}

void	init_range(t_stack **a, t_range *range, int size)
{
	int	*array;

	array = stack_to_array(*a, size);
	if (!array)
		exit(1);
	sorted_array(array, size);
	range->offset = find_offset(size);
	range->sorted_array = array;
	range->size = size;
	range->start = 0;
	range->end = range->offset;
}

void	next_chunk(t_range *range)
{
	if (range->start < range->end - 1)
		range->start += 1;
	if (range->end < range->size - 1)
		range->end += 1;
}

void	large_sort(t_stack **a, t_stack **b, int size)
{
	t_range	*range;

	range = (t_range *)malloc(sizeof(t_range));
	if (!range)
		exit(1);
	init_range(a, range, size);
	push_element_to_b(a, b, range);
	push_elements_to_a(a, b);
	free(range->sorted_array);
	free(range);
}
