/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 18:49:35 by rsibiet           #+#    #+#             */
/*   Updated: 2017/02/13 18:49:38 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	*ft_memdup(const void *src, size_t size)
{
	unsigned char	*x;

	if (!(x = (unsigned char *)malloc(size)))
		return (NULL);
	return (ft_memcpy(x, src, size));
}
