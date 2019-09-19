/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/26 13:24:08 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 10:47:03 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	**ft_sort_ascii(char **str)
{
	size_t	nstr;
	size_t	i;
	size_t	k;

	nstr = ft_strslen((const char **)str);
	if (nstr > 1)
	{
		i = 0;
		k = nstr - 1;
		while (k)
		{
			i = 0;
			k = nstr - 1;
			while (str[i + 1])
			{
				if (ft_strcmp(str[i], str[i + 1]) > 0)
					ft_swap(str[i], str[i + 1]);
				else
					k--;
				i++;
			}
		}
	}
	return (str);
}
