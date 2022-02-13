/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:42:38 by aklaikel          #+#    #+#             */
/*   Updated: 2022/01/18 00:11:18 by aklaikel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

size_t	ft_strlen( const char	*str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	substr = (char *) malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (start < ft_strlen(s) && i < len)
	{
		substr[i] = (char)s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

static size_t	ft_total(char const *s, char c)
{
	size_t	t;

	t = 0;
	while (*s)
	{
		if (*s != c)
		{
			t++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (t);
}

static char	**ft_free(char **str, int index)
{
	while (index--)
	{
		free(str[index]);
	}
	free(str);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	len;
	char	**str;

	i = 0;
	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (ft_total(s, c) + 1));
	if (!str)
		return (0);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		if (len != 0)
			str[i++] = ft_substr(s, 0, len);
		if (!str[i - 1] && len != 0)
			return (ft_free(str, i - 1));
		s += len;
	}
	str[i] = NULL;
	return (str);
}
