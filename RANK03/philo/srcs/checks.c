/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:01:54 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/08 09:12:20 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ph_atoi(const char *nptr)
{
	int		num;
	int		sign;
	size_t	i;

	num = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign = -1;
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
		num = num * 10 + nptr[i++] - '0';
	return (num * sign);
}

void	check_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (!str[i] || !(str[i] >= '0' && str[i] <= '9'))
		error_message();
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] && !(str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		error_message();
}

void	check_args(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
		check_number(av[i]);
}