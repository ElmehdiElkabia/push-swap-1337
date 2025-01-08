/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelkabia <eelkabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:24:03 by eelkabia          #+#    #+#             */
/*   Updated: 2025/01/08 22:34:12 by eelkabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void	sorted_stack(t_stack **a, t_stack **b)
{
	if (check_sorted(*a))
		return ;
	if (size_stack(*a) < 6)
		small_sort(a, b, size_stack(*a));
	else
		large_sort(a, b, size_stack(*a));
}

static void	free_stack(t_stack *stack)
{
	t_stack	*node;

	while (stack)
	{
		node = stack;
		stack = stack->next;
		free(node);
	}
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
		free(array[i++]);
	free(array);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (!argv)
		error_msg();
	if (argc < 2)
		return (0);
	check_input(argc, argv);
	stack_a = NULL;
	stack_a = init_stack(argc, argv, stack_a);
	stack_b = NULL;
	sorted_stack(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}
