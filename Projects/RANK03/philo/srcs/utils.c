/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:39:25 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/16 19:39:37 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	status(t_ph *ph, char *status)
{
	if (ph->lm == -1)
		printf("%ld %d %s\n", \
			gettime() - ph->inf->time_start, \
			ph->ph_id, \
			status \
		);
	else
		printf("%ld %d %s\n", \
			gettime() - ph->lm, \
			ph->ph_id, \
			status \
		);
}
