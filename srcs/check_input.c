/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llo-surd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:27:35 by llo-surd          #+#    #+#             */
/*   Updated: 2022/12/08 13:24:21 by llo-surd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	num_check(char *argv);
static int	check_int(char *argv);
static int	duplicate_detected(char *argv, char **av, int i);
static int	invalid_input(int error);

int	check_input(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (num_check(argv[i]) != 0)
			return (invalid_input(1));
	}
	i = 0;
	while (argv[++i])
	{
		if (check_int(argv[i]) != 0)
			return (invalid_input(2));
	}
	i = 0;
	while (argv[++i])
	{
		if (duplicate_detected(argv[i], argv, i) != 0)
			return (invalid_input(3));
	}
	return (0);
}

static int	num_check(char *argv)
{
	int	i;

	i = -1;
	while (argv[++i])
	{
		if (argv[i] == '-')
			i++;
		if (!(argv [i] >= '0' && argv[i] <= '9'))
			return (-1);
	}
	return (0);
}

static int	check_int(char *argv)
{
	long int	num;

	num = ft_atoi(argv);
	if (num < -2147483647 || num > 2147483647)
		return (-1);
	return (0);
}

static int	duplicate_detected(char *argv, char **av, int i)
{
	long int	num;

	num = ft_atoi(argv);
	while (av[i + 1])
	{
		if (num == ft_atoi(av[i + 1]))
			return (-1);
		i++;
	}
	return (0);
}

static int	invalid_input(int error)
{
	if (error == 1)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	if (error == 2)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	if (error == 3)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	return (-1);
}
