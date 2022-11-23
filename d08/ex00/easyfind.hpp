/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:45:28 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/23 17:45:23 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template<typename T>
bool	easyfind(T const & container, int n)
{
	if (container.end() == std::find(container.begin(), container.end(), n))
		return (false);
	return (true);
}

#endif
