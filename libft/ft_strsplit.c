/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 11:10:27 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 13:26:14 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static size_t	count_words(char const *s, char c)
{
	int	index;
	int	nwords;

	index = 0;
	nwords = 0;
	while (s[index])
	{
		while (s[index] == c)
			index++;
		if (s[index])
			nwords++;
		while (s[index] != c && s[index])
			index++;
	}
	return (nwords);
}

static size_t	count_chars(char const *s, char c, size_t word)
{
	int index;
	int windex;

	index = 0;
	while (s[index] && word)
	{
		while (s[index] == c)
			index++;
		word--;
		if (word)
		{
			while (s[index] != c)
				index++;
		}
	}
	windex = index;
	while (s[index] != c && s[index])
		index++;
	return (index - windex);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**dst;
	size_t	nwords;
	size_t	word;
	int		index;

	dst = NULL;
	nwords = 0;
	if (s && c)
		nwords = count_words(s, c);
	if (!(dst = (char **)malloc(sizeof(*dst) * (nwords + 1))))
		return (dst);
	word = 0;
	index = 0;
	while (word != nwords)
	{
		while (s[index] == c)
			index++;
		dst[word] = ft_strsub(s, index, count_chars(s, c, word + 1));
		word++;
		while (s[index] != c && s[index])
			index++;
	}
	dst[nwords] = NULL;
	return (dst);
}
