/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 12:57:49 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 13:33:22 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	if (!(tmp = ft_lstnew(f(lst)->content, f(lst)->content_size)))
		return (NULL);
	new = tmp;
	lst = lst->next;
	while (lst)
	{
		if (!(tmp->next = ft_lstnew(f(lst)->content, f(lst)->content_size)))
			return (NULL);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (new);
}
