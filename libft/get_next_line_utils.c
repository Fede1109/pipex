/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:37:31 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/10/21 17:44:22 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1 || !s2)
	{
		s1 = malloc(sizeof(char) + 1);
		if (!s1 || !s2)
			return (NULL);
		s1[0] = '\0';
	}
	str = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (str)
	{
		while (s1[++i] != '\0')
			str[i] = s1[i];
		while (s2[++j] != '\0')
			str[i + j] = s2[j];
		str[i + j] = '\0';
	}
	free(s1);
	return (str);
}

char	*ft_extract_line(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	ret = malloc(sizeof(char) * (i + 1));
	if (!ret)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != '\n')
		ret[i] = str[i];
	if (str[i] == '\n')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen_gnl(const char *str)
{
	size_t	counter;

	counter = 0;
	while (*str != '\0')
	{
		counter++;
		str++;
	}	
	return (counter);
}

char	*ft_new_static(char *aux)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	while (aux[i] && aux[i] != '\n')
		i++;
	if (!aux[i])
	{
		free(aux);
		return (NULL);
	}
	ret = malloc(sizeof(char) * (ft_strlen_gnl(aux) - i + 1));
	if (!ret)
	{
		free(aux);
		return (NULL);
	}
	i++;
	j = 0;
	while (aux[i] != '\0')
		ret[j++] = aux[i++];
	ret[j] = '\0';
	free(aux);
	return (ret);
}
