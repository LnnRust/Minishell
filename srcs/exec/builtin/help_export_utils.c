/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_export_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandreo <aandreo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:29:48 by memillet          #+#    #+#             */
/*   Updated: 2026/03/04 07:42:37 by aandreo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	swap_and_print(char **tmp)
{
	int		i;
	char	*swap_tmp;
	char	*equal;

	i = 0;
	while (tmp[i] && tmp[i + 1])
	{
		if (ft_strncmp(tmp[i], tmp[i + 1], ft_strlen(tmp[i])) > 0)
		{
			swap_tmp = tmp[i];
			tmp[i] = tmp[i + 1];
			tmp[i + 1] = swap_tmp;
			i = 0;
		}
		else
			i++;
	}
	i = 0;
	while (tmp[i])
	{
		equal = ft_strchr(tmp[i], '=');
		if (!equal)
			printf("declare -x %s=\"\"\n", tmp[i]);
		else if (*(equal + 1) == '\0')
			printf("declare -x %.*s=\"\"\n", (int)(equal - tmp[i]), tmp[i]);
		else
			printf("declare -x %s\n", tmp[i]);
		free(tmp[i]);
		i++;
	}
}
