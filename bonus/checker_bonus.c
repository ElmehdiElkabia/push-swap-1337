/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelkabia <eelkabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:40:14 by eelkabia          #+#    #+#             */
/*   Updated: 2025/01/08 22:30:49 by eelkabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

static void	execute_push_swap(char *line, t_stack **a, t_stack **b)
{
	if (ft_strcmp(line, "pa\n") == 0)
		push_to_stack_a(a, b);
	else if (ft_strcmp(line, "pb\n") == 0)
		push_to_stack_b(a, b);
	else if (ft_strcmp(line, "sa\n") == 0)
		swap_stack_a(a);
	else if (ft_strcmp(line, "sb\n") == 0)
		swap_stack_b(b);
	else if (ft_strcmp(line, "ss\n") == 0)
		swap_stack_ab(a, b);
	else
	{
		free_stack(*a);
		free_stack(*b);
		free(line);
		error_msg();
	}
}

static void	execute_rotate_reverse(char *line, t_stack **a, t_stack **b)
{
	if (ft_strcmp(line, "ra\n") == 0)
		rotate_stack_a(a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rotate_stack_b(b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rotate_stack_ab(a, b);
	else if (ft_strcmp(line, "rra\n") == 0)
		reverse_rotate_stack_a(a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		reverse_rotate_stack_b(b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		reverse_rotate_stack_ab(a, b);
	else
	{
		free_stack(*a);
		free_stack(*b);
		free(line);
		error_msg();
	}
}

static void	ft_execute(char *line, t_stack **a, t_stack **b)
{
	if (ft_strcmp(line, "pa\n") == 0 || ft_strcmp(line, "pb\n") == 0
		|| ft_strcmp(line, "sa\n") == 0 || ft_strcmp(line, "sb\n") == 0
		|| ft_strcmp(line, "ss\n") == 0)
		execute_push_swap(line, a, b);
	else
		execute_rotate_reverse(line, a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	if (!argv)
		error_msg();
	if (argc < 2)
		return (0);
	stack_b = NULL;
	stack_a = init_stack(argc, argv, NULL);
	check_input(argc, argv);
	line = get_next_line(0);
	while (line)
	{
		ft_execute(line, &stack_a, &stack_b);
		free(line);
		line = get_next_line(0);
	}
	if (check_sorted(stack_a) && !stack_b)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_stack(stack_a);
	free_stack(stack_b);
}
