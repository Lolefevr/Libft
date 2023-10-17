/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:58:43 by lolefevr          #+#    #+#             */
/*   Updated: 2023/02/11 23:18:41 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	k;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (i < len && big[i])
	{
		k = 0;
		while (little[k] == big[i + k] && i + k < len)
		{
			if (!little[k +1])
				return ((char *)big + i);
			k++;
		}
		i++;
	}
	return (0);
}
