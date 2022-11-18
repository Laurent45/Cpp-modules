/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 08:03:37 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/18 11:34:28 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialize.hpp"
#include <cstddef>

uintptr_t serialize(Data * ptr)
{
	if (ptr == NULL)
		return (NULL);
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data * deserialize(uintptr_t raw)
{
	if (raw == NULL)
		return (NULL);
	return (reinterpret_cast<Data *>(raw));
}
