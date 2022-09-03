/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:22:11 by lfrederi          #+#    #+#             */
/*   Updated: 2022/09/03 13:29:14 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

#define CONTACT_MAX 8

class PhoneBook
{
	public:

		void	addContact(void);
		void	search(void) const;

	private:
		
		Contact		_contacts[CONTACT_MAX];
		static int	_nbContact;

		void			_printContact(int index) const;
		void			_printContacts(void) const;
		void			_printRule(std::string str) const;
		bool			_isValidIndex(std::string index, int *idx) const;
		std::string		_getContactField(std::string contactField) const;


};

#endif
