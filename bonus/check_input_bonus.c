/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelkabia <eelkabia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:00:08 by eelkabia          #+#    #+#             */
/*   Updated: 2025/01/02 11:06:04 by eelkabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
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

	i = 0;
	if (argv[i] == '-')
		i++;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
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
	long	tmp_argv;

	i = 0;
	array = ft_split(join_arg(argc, argv), ' ');
	while (array[i])
	{
		tmp_argv = ft_atoi(array[i]);
		if (tmp_argv < INT_MIN || tmp_argv > INT_MAX)
			error_msg();
		if (!check_number(array[i]))
			error_msg();
		i++;
	}
	if (check_doubles(array))
		error_msg();
	free(array);
}
