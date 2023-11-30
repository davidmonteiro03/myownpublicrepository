/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:01:04 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/30 20:32:14 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*ph_routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	while (1)
		ph_eating(philo);
	return (NULL);
}

void	ph_execute(t_data *data)
{
	t_philo	*temp;

	data->start = ph_get_time();
	temp = data->philos;
	while (temp)
	{
		temp->data = data;
		pthread_create(&temp->thread, NULL, &ph_routine, temp);
		temp = temp->next;
	}
}
