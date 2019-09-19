/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 10:50:57 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 12:48:55 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;

	if (alst && del)
	{
		while (*alst)
		{
			temp = (*alst)->next;
			ft_lstdelone(alst, del);
			*alst = temp;
		}
	}
}
