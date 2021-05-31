/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 19:37:04 by gariadno          #+#    #+#             */
/*   Updated: 2020/02/15 14:38:41 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_tr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;
	size_t			s_len;

	if (!s || !(str = malloc((len + 1) * sizeof(*str))))
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	while (i < len && (start + i) < s_len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
