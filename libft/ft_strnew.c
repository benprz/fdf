/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 09:57:10 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 13:24:07 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strnew(size_t size)
{
	char *str;

	str = NULL;
	if (!(str = (char *)malloc(sizeof(*str) * size + 1)))
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}
