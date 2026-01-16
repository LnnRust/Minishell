/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 03:36:03 by ancourti          #+#    #+#             */
/*   Updated: 2025/11/10 22:32:52 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_lstmap_cleanup(t_list **new_lst, void (*del)(void *))
{
	ft_lstclear(new_lst, del);
	free(*new_lst);
	*new_lst = NULL;
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*temp_src;
	t_list	*back_list;
	void	*content_temp;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	temp_src = lst;
	content_temp = f(temp_src->content);
	if (content_temp == NULL)
		return (NULL);
	new_lst = ft_lstnew(content_temp);
	if (new_lst == NULL)
		return (del(content_temp), NULL);
	while (temp_src->next != NULL)
	{
		content_temp = f((temp_src->next)->content);
		back_list = ft_lstnew(content_temp);
		if (back_list == NULL)
			return (del(content_temp), ft_lstmap_cleanup(&new_lst, del));
		ft_lstadd_back(&new_lst, back_list);
		temp_src = temp_src->next;
	}
	return (new_lst);
}
