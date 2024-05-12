/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:19:56 by rnogueir          #+#    #+#             */
/*   Updated: 2023/11/08 13:49:20 by rnogueir         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*elm;
	t_list	*new_lst;
	void	*content;

	new_lst = NULL;
	while (lst)
	{
		content = f(lst->content);
		elm = ft_lstnew(content);
		if (!elm)
		{
			ft_lstclear(&new_lst, del);
			free(content);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, elm);
		lst = lst->next;
	}
	return (new_lst);
}
