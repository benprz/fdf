/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstsnew.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/26 11:09:02 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/26 11:58:01 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

t_list		*ft_lstsnew(char *content, size_t content_size)
{
	t_list	*new;
	size_t	size;

	if (!(new = malloc(sizeof(*new))))
		return (NULL);
	if (!content || !content_size)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		size = sizeof(char *) * content_size + 1;
		if (!(new->content = (char *)malloc(size)))
		{
			free(new);
			return (NULL);
		}
		ft_memcpy(new->content, content, content_size);
		ft_memcpy(new->content, ft_strcat(new->content, "\0"), content_size);
		new->content_size = content_size + 1;
	}
	new->next = NULL;
	return (new);
}
