/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandreo <aandreo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 23:17:27 by aandreo           #+#    #+#             */
/*   Updated: 2026/02/18 01:19:03 by aandreo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

//bool  check_quotes -> fonction qui va checker 
// si les premieres quotes de la $var sont bien des ", sinon return false"

#include <stdbool.h>

//return true seulement si la premiere quote est bien une double quote = need to expand
bool check_first_quotes(char *prompt)
{
	for (int i = 0; prompt[i] != '\0'; i++)
	{
		if(prompt[i] == '"' || prompt[i] == '\'')
		{
			if(prompt[i] == '"')
				return true;
			return false;
		}
	}
	return false;
}

//➜ echo $USER -> replace $USER with var value
//➜ echo "$USER" -> same as up
//➜ echo "'$USER'" -> display var value surrounded by '' -> echo "'$USER'" == 'aandreo'
//➜ echo "ww$LESee" == ww
//➜ echo "'ww$LESee'" == 'ww'  
