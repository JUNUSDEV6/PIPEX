/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youneshanafi <youneshanafi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:47:43 by youneshanaf       #+#    #+#             */
/*   Updated: 2024/01/17 16:36:02 by youneshanaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	else if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}

void	ft_bzero(void *s, size_t leng)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	while (i < leng)
	{
		str[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*array;
	size_t	*leng;

	leng = num * size;
	array = (void *)malloc(leng)
	if (!array)
		return (NULL);
	ft_bzero(array, leng);
	return (array);
}