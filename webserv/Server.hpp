/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:33:20 by lfrederi          #+#    #+#             */
/*   Updated: 2023/05/08 15:43:30 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>

class Server
{
	public:
		
		Server(void);
		Server(Server const & copy);
		~Server(void);
		Server &	operator=(Server const & rhs);

		int		getListenerFd() const;

		void	serverInit(short portNumber);
		void	listening() const;

	private:
		
		int		_listenerFd;

};

std::ostream & operator<<(std::ostream & out, Server const & server);

#endif

