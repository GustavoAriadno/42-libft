/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 20:08:30 by gariadno          #+#    #+#             */
/*   Updated: 2020/01/29 14:02:51 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*f_pointer(char const *s, char c)
{
	unsigned int	i;
	unsigned int	len;
	char			*str;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	i = 0;
	str = (char *)malloc(len * sizeof(char) + 1);
	str[len] = '\0';
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

char			*f_findword(char const *s, char c, unsigned int word)
{
	unsigned int	words;
	int				trigger;

	trigger = 0;
	words = 0;
	while (*s || word == words)
	{
		if (word == words)
			return (f_pointer(--s, c));
		else if (*s != c && trigger == 0)
		{
			words++;
			trigger = 1;
		}
		else if (*s == c)
			trigger = 0;
		s++;
	}
	return (0);
}

unsigned int	f_countw(char const *s, char c)
{
	unsigned int	words;
	int				trigger;

	trigger = 0;
	words = 0;
	while (*s)
	{
		if (*s != c && trigger == 0)
		{
			words++;
			trigger = 1;
		}
		else if (*s == c)
			trigger = 0;
		s++;
	}
	return (words);
}

char			**ft_split(char const *s, char c)
{
	unsigned int	i;
	char			**str;

	if (!s || !(str = (char **)malloc((f_countw(s, c) + 1) * sizeof(char *))))
		return (NULL);
	str[f_countw(s, c)] = NULL;
	i = 0;
	while (i < f_countw(s, c))
	{
		str[i] = f_findword(s, c, i + 1);
		i++;
	}
	return (str);
}