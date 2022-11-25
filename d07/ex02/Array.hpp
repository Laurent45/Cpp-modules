/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 07:56:48 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/25 12:58:45 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>

template<typename T>
class Array
{
	private:
		unsigned int		_size;
		T *					_array;

	public:
		// Canonical form
		Array(void)
			: _size(0), _array(new T[0]) {}

		~Array(void) {
			if (_array)
				delete [] _array;
		}

		Array(Array<T> const & copy)
			: _size(copy._size), _array(new T[copy._size]) {
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = copy._array[i];
		}

		Array &	operator=(Array<T> const & rhs) {
			if (this != &rhs) {
				_size = rhs._size;
				if (_array)
					delete [] _array;
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = rhs[i];
			}
			return (*this);
		}

		// Constructor
		Array(unsigned int n)
			: _size(n), _array(new T[n]) {}
		
		// Members functions
		T &	operator[](unsigned int n) {
			if (n >= _size)
				throw std::exception();
			return (this->_array[n]);
		}

		T const &	operator[](unsigned int n) const {
			if (n >= _size)
				throw std::exception();
			return (this->_array[n]);
		}

		unsigned int	size(void) const {
			return (this->_size);
		}
};

#endif
