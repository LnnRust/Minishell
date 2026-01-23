/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 07:15:41 by ancourti          #+#    #+#             */
/*   Updated: 2026/01/21 20:52:26 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Adds the node `new` at the beginning of the list.
/// @param lst The address of a pointer to the first node of a list.
/// @param new The address of a pointer to the node to be added.
/// @return None.
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// int	main(void)
// {
// 	t_list	*first = ft_lstnew("bonjour");
// 	t_list	*second = ft_lstnew("au revoir");

// 	first->next = second;

// 	ft_lstadd_front(&first, second);
// }
