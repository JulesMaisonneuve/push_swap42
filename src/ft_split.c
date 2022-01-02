/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumaison <jumaison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 17:57:41 by jumaison          #+#    #+#             */
/*   Updated: 2020/06/06 20:07:06 by jumaison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char	**ft_free_words(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static unsigned int	ft_countwords(char const *s, char c)
{
	unsigned int	i;
	unsigned int	words;

	if (!s[0])
		return (0);
	i = 0;
	words = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			words++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		words++;
	return (words);
}

static void	ft_getword(char **tab, unsigned int *strlen, char c)
{
	unsigned int	i;

	*tab += *strlen;
	*strlen = 0;
	i = 0;
	while (**tab && **tab == c)
		(*tab)++;
	while ((*tab)[i])
	{
		if ((*tab)[i] == c)
			return ;
		(*strlen)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	unsigned int	wordscount;
	char			**tab;
	char			*str;
	unsigned int	strlen;
	unsigned int	i;

	if (!s)
		return (NULL);
	wordscount = ft_countwords(s, c);
	tab = malloc(sizeof(char *) * (wordscount + 1));
	if (!tab)
		return (NULL);
	str = (char *)s;
	strlen = 0;
	i = -1;
	while (++i < wordscount)
	{
		ft_getword(&str, &strlen, c);
		tab[i] = malloc(sizeof(char) * (strlen + 1));
		if (!tab[i])
			return (ft_free_words(tab));
		ft_strlcpy(tab[i], str, strlen + 1);
	}
	tab[i] = NULL;
	return (tab);
}
