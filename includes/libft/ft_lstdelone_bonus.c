/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:49:21 by ancourti          #+#    #+#             */
/*   Updated: 2026/01/21 20:53:48 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Takes a node as parameter and frees its content
/// using the function `del`. Free the node itself but
/// does NOT free the next node.
/// @param lst The node to free.
/// @param del The address of the function used to delete the content.
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del((lst)->content);
	free(lst);
}
