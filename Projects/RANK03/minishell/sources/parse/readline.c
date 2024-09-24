/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:05:02 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/20 13:10:22 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	parse_readline(t_shell *shell)
{
	shell->line = readline(CYN PROMPT RESET "$ ");
	if (shell->line == NULL)
		return (false);
	if (*shell->line != '\0')
		add_history(shell->line);
	shell->tokens = tokens_parse(shell->line, 0);
	return (true);
}