/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 10:18:43 by ancourti          #+#    #+#             */
/*   Updated: 2026/01/21 20:52:37 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Counts the number of nodes in the list.
/// @param lst The beginning of the list.
/// @return The length of the list.
int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*ptr_lst;

	if (lst == NULL)
	{
		return (0);
	}
	ptr_lst = lst;
	i = 1;
	while (ptr_lst->next != NULL)
	{
		ptr_lst = ptr_lst->next;
		i++;
	}
	return (i);
}
