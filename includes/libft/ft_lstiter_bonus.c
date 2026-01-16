/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 03:28:33 by ancourti          #+#    #+#             */
/*   Updated: 2025/11/10 12:53:56 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
