/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   literalType.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:09:09 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/17 16:48:54 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LITERAL_TYPE_HPP
#define LITERAL_TYPE_HPP

enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	UNKNOWN
};

e_type	detectLiteralType(char const * literal);

#endif
