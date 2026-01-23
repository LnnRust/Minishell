/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 03:28:33 by ancourti          #+#    #+#             */
/*   Updated: 2026/01/21 20:54:26 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Iterates through the list `lst` and applies the
/// function `f` to the content of each node.
/// @param lst The address of a pointer to a node.
/// @param f The address of the function to apply to each
/// node’s content.
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	if (lst == NULL)
	{
		return ;
	}
	temp = lst;
	while (temp->next != NULL)
	{
		f(temp->content);
		temp = temp->next;
	}
	f(temp->content);
}
