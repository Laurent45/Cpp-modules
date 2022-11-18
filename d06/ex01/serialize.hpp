/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 08:01:41 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/18 08:04:08 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

struct Data
{
	int	id;
	char c;
	float f;
	double d;
};

typedef unsigned int * uintptr_t;

uintptr_t serialize(Data * ptr);
Data * deserialize(uintptr_t raw);

#endif
