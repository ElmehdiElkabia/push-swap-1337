/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelkabia <eelkabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:00:08 by eelkabia          #+#    #+#             */
/*   Updated: 2025/01/08 22:39:18 by eelkabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_doubles(char **argv)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (argv[len])
		len++;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	is_empty_or_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_number(char *argv)
{
	int	i;
	int	hyphen_count;

	i = 0;
	hyphen_count = 0;
	while (ft_isspace(argv[i]))
		i++;
	if (argv[i] == '-' && argv[i + 1] != '\0')	
	{
		hyphen_count++;
		i++;
	}
	if (!ft_isdigit(argv[i]))
		return (0);
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]) && !ft_isspace(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

static char	*join_arg(int argc, char **argv)
{
	char	*joined;
	char	*temp;
	int		i;

	i = 1;
	joined = ft_strdup("");
	while (i < argc)
	{
		if (!is_empty_or_whitespace(argv[i]))
		{
			temp = ft_strjoin(joined, argv[i]);
			free(joined);
			joined = ft_strjoin(temp, " ");
			free(temp);
		}
		i++;
	}
	if (is_empty_or_whitespace(joined))
	{
		free(joined);
		error_msg();
	}
	return (joined);
}

void	check_input(int argc, char **argv)
{
	int		i;
	char	**array;
	char	*args;
	long	tmp_argv;

	i = 0;
	args = join_arg(argc, argv);
	array = ft_split(args, ' ');
	free(args);
	while (array[i])
	{
		tmp_argv = ft_atoi(array[i]);
		if (tmp_argv < INT_MIN || tmp_argv > INT_MAX || !check_number(array[i]))
		{
			free_array(array);
			error_msg();
		}
		i++;
	}
	if (check_doubles(array))
	{
		free_array(array);
		error_msg();
	}
	free_array(array);
}
