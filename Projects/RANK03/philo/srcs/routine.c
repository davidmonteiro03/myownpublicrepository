/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:00:53 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/10 17:44:22 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	lock_forks(t_ph *ph)
{
	if (ph->inf->cur_eat >= ph->inf->max_eat)
		return (1);
	pthread_mutex_lock(ph->lf);
	status(ph, "has taken a fork");
	pthread_mutex_lock(ph->rf);
	status(ph, "has taken a fork");
	return (0);
}

void	sleeping(t_ph *ph)
{
	status(ph, "is sleeping");
	usleep(ph->inf->time_sleep);
}

void	unlock_forks(t_ph *ph)
{
	pthread_mutex_unlock(ph->lf);
	pthread_mutex_unlock(ph->rf);
	ph->meal_count++;
	ph->lm = get_time();
}