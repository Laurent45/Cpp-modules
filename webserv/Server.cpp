/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:35:40 by lfrederi          #+#    #+#             */
/*   Updated: 2023/05/08 16:07:58 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <strings.h>
#include <unistd.h>

/* ************************************************************************** */
//						           PUBLIC									  //
/* ************************************************************************** */

// Canonical form
Server::Server(void) : _listenerFd(-1) 
{}

Server::Server(Server const & copy) : _listenerFd(copy._listenerFd)
{}

Server::~Server(void)
{
	close(this->_listenerFd);
}

Server &	Server::operator=(Server const & rhs)
{
	if (this != &rhs)
	{
		this->_listenerFd = rhs._listenerFd;
	}
	return *this;
}

// Constructors

// Members methods
int		Server::getListenerFd() const 
{
	return this->_listenerFd;
}


void	Server::serverInit(short portNumber)
{
	struct sockaddr_in addr;

	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(portNumber);

	if ((this->_listenerFd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		throw std::exception();
	
	if (bind(this->_listenerFd,(struct sockaddr *) &addr, sizeof(addr)) < 0)
		throw std::exception();

	if (listen(this->_listenerFd, 10) < 0)
		throw std::exception();

	std::cout << "The server is ready to listening on port " << portNumber << std::endl;
}

void	Server::listening() const
{
	struct sockaddr_in	addrAccept;
	unsigned int		acceptFd;
	socklen_t			size;

	size = sizeof(addrAccept);
	while (true)
	{
		std::cout << "Waiting connection ..." << std::endl;

		acceptFd = accept(this->_listenerFd, (struct sockaddr *) &addrAccept, &size);
		if (acceptFd > 0)
		{
			std::cout << "accept fd => " << acceptFd << std::endl;
			close(acceptFd);
		}
	}
}

/* ************************************************************************** */
//						           PRIVATE									  //
/* ************************************************************************** */

// Members methods


/* ************************************************************************** */
//						           FUNCTIONS								  //
/* ************************************************************************** */

std::ostream & operator<<(std::ostream & out, Server const & server)
{
	out << "Server(listenerFd: " << server.getListenerFd() << ")"
		<< std::endl;
	return out;
}
