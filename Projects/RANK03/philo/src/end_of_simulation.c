/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_of_simulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:50:52 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/07 17:05:46 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	ph_check_deaths(t_philo *philo)
{
	long	now;

	now = ph_get_time();
	if ((philo->last_meal == -1 && \
		now - philo->data->start_time > philo->data->time_to_die) || \
		(philo->last_meal != -1 && \
		now - philo->last_meal > philo->data->time_to_die))
	{
		ph_display_status(philo, DIED);
		pthread_mutex_lock(&philo->data->check);
		philo->data->simulation_end = true;
		return (pthread_mutex_unlock(&philo->data->check), true);
	}
	return (false);
}

bool	ph_check_finish_meals(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->check);
	if (philo->data->num_meals_per_philo == -1)
		return (pthread_mutex_unlock(&philo->data->check), false);
	if (philo->data->num_finish_meals == philo->data->num_philos)
	{
		philo->data->simulation_end = true;
		return (pthread_mutex_unlock(&philo->data->check), true);
	}
	return (pthread_mutex_unlock(&philo->data->check), false);
}
