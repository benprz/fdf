/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/25 11:43:10 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 10:59:30 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static size_t	count_chars(const char *str, char c)
{
	size_t i;

	i = 0;
	while (*str == c && *str)
		str++;
	while (*str != c && *str)
	{
		str++;
		i++;
	}
	if (!(*str))
		i += 1;
	return (i);
}

t_list			*ft_lstsplit(char *str, char c)
{
	t_list	*list;
	t_list	*tmp;
	size_t	len;

	while (*str == c && *str)
		str++;
	len = count_chars(str, c);
	if (!(*str) || !(list = ft_lstsnew(str, len)))
		return (NULL);
	while (*str != c && *str)
		str++;
	tmp = list;
	while (*str && (len = count_chars(str, c)))
	{
		while (*str == c && *str)
			str++;
		if (!len || !(list->next = ft_lstsnew(str, len)))
			return (tmp);
		while (*str != c && *str)
			str++;
		list = list->next;
	}
	return (tmp);
}
