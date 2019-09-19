/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 13:15:25 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 11:10:39 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static int		has_wsp(char const c)
{
	if (c != ' ' && c != '\t' && c != '\n')
		return (0);
	else
		return (1);
}

static int		ft_strlen_nowsp(char const *s)
{
	size_t	slen;
	size_t	elen;
	int		index;

	slen = 0;
	elen = 0;
	index = 0;
	if (has_wsp(s[index]))
	{
		while (has_wsp(s[index]))
		{
			slen++;
			index++;
		}
	}
	index = slen != ft_strlen(s) ? ft_strlen(s) - 1 : index;
	if (has_wsp(s[index]))
	{
		while (has_wsp(s[index]))
		{
			elen++;
			index--;
		}
	}
	return (ft_strlen(s) - slen - elen);
}

char			*ft_strtrim(char const *s)
{
	char	*s2;
	int		len;
	int		start;

	s2 = NULL;
	if (s)
	{
		len = ft_strlen_nowsp(s);
		start = 0;
		while (has_wsp(s[start]))
			start++;
		s2 = ft_strsub(s, start, len);
	}
	return (s2);
}
