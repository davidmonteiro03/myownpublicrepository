/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:33:31 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/13 16:41:37 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	exit_mini(t_mini *mini, int status)
{
	multiple_free("%c%a%a", \
		mini->vars, \
		mini->command, \
		mini \
	);
	exit(status);
}
