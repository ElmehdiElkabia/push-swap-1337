/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelkabia <eelkabia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:24:03 by eelkabia          #+#    #+#             */
/*   Updated: 2025/01/02 11:01:21 by eelkabia         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (!argv)
		error_msg();
	if (argc < 2)
		return (0);
	stack_a = init_stack(argc, argv, NULL);
	stack_b = NULL;
	check_input(argc, argv);
	sorted_stack(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}
