/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 07:15:41 by ancourti          #+#    #+#             */
/*   Updated: 2025/11/10 12:53:47 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
