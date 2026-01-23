/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 10:40:29 by ancourti          #+#    #+#             */
/*   Updated: 2026/01/21 20:56:41 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Adds the node `new` at the end of the list.
/// @param lst The address of a pointer to the first node of a list.
/// @param new The address of a pointer to the node to be added.
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_element;

	last_element = ft_lstlast(*lst);
	if (last_element == NULL)
	{
		*lst = new;
		return ;
	}
	last_element->next = new;
}
