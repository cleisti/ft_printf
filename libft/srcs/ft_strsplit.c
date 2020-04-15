/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 09:54:05 by cleisti           #+#    #+#             */
/*   Updated: 2019/11/10 16:46:42 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words(char const *s, char c)
{
	unsigned int	words;
	int				i;

	i = 0;
	words = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			words++;
		i++;
	}
	return (words);
}

static int		ft_word_len(char const *s, int i, char c)
{
	int len;

	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		count;
	int		i;
	int		j;

	count = 0;
	i = 0;
	j = 0;
	if (!(s))
		return (NULL);
	if (!(arr = (char**)malloc(sizeof(char*) * (ft_count_words(s, c) + 1))))
		return (NULL);
	while (s[i] != '\0' && count < ft_count_words(s, c))
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			j = i + 1;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			arr[count] = ft_strsub(s, j, ft_word_len(s, j, c));
			count++;
		}
		i++;
	}
	arr[count] = NULL;
	return (arr);
}
