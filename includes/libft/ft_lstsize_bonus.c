/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 10:18:43 by ancourti          #+#    #+#             */
/*   Updated: 2025/11/10 12:54:19 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
