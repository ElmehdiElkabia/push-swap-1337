/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelkabia <eelkabia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 21:45:50 by eelkabia          #+#    #+#             */
/*   Updated: 2025/01/02 11:11:25 by eelkabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	push_to_stack(t_stack **stack, int value)
{
	t_stack	*new;

	if (!stack)
		return ;
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->value = value;
	new->next = *stack;
	*stack = new;
}

void	error_msg(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

static	char	*join_arg(int argc, char **argv)
{
	char	*joined;
	char	*temp;
	int		i;

	i = 1;
	joined = ft_strdup("");
	while (i < argc)
	{
		temp = ft_strjoin(joined, argv[i]);
		free(joined);
		joined = ft_strjoin(temp, " ");
		free(temp);
		i++;
	}
	return (joined);
}

t_stack	*init_stack(int argc, char **argv, t_stack *a)
{
	char	**array;
	char	*joined_args;
	int		i;

	a = NULL;
	i = 0;
	joined_args = join_arg(argc, argv);
	array = ft_split(joined_args, ' ');
	free(joined_args);
	while (array[i])
		i++;
	i--;
	while (i >= 0)
	{
		push_to_stack(&a, ft_atoi(array[i]));
		i--;
	}
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
	return (a);
}

void	free_stack(t_stack *stack)
{
	t_stack	*node;

	while (stack)
	{
		node = stack;
		stack = stack->next;
		free(node);
	}
}
