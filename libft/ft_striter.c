/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_striter.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 10:39:56 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/12 10:35:17 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int i;
	int j;

	if (s && f)
	{
		i = ft_strlen(s);
		j = 0;
		while (j != i)
		{
			f(s + j);
			j++;
		}
	}
}
