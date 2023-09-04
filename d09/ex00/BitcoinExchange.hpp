/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:42:46 by lfrederi          #+#    #+#             */
/*   Updated: 2023/07/08 17:22:53 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <string>

#define DATABASE_PATH   "/Users/laurentfrederick/Downloads/cpp_09/data.csv"

enum    MONTH
{
    JAN = 1,
    FEB,
    MAR,
    APR,
    MAY,
    JUN,
    JUL,
    AUG,
    SEP,
    OCT,
    NOV,
    DEC
};

class BitcoinExchange
{

    private:

        std::map<std::string, double>   _ref;

        void    insertLineIntoMap(std::string const & line);
        bool    isValidDate(std::string const & date) const;
        double  stringToFloat(std::string const & value) const;
        bool    isAllDigit(std::string const & str) const;
        void    calculate(std::string date, double value) const;
        
    public:

        BitcoinExchange(void);
        BitcoinExchange(BitcoinExchange const & copy);
        BitcoinExchange & operator=(BitcoinExchange const & rhs);
        ~BitcoinExchange(void);

        void    loadDataBase();
        void    calculateRateExchange(char const filePath[]) const;

        void    print();
};

#endif
