/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 10:34:27 by ancourti          #+#    #+#             */
/*   Updated: 2025/11/10 12:54:03 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr_lst;

	if (lst == NULL)
	{
		return (NULL);
	}
	ptr_lst = lst;
	while (ptr_lst->next != NULL)
	{
		ptr_lst = ptr_lst->next;
	}
	return (ptr_lst);
}
