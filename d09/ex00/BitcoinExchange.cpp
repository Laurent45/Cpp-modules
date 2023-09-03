/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:42:40 by lfrederi          #+#    #+#             */
/*   Updated: 2023/07/08 17:33:31 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <algorithm>
#include <cstring>
#include <exception>
#include <iostream>
#include <fstream>  /* ifstream */
#include <cctype>   /* isdigit */
#include <cstdlib>  /* atoi */
#include <ostream>
#include <stdlib.h> /* strtod */
#include <cmath>    /* NAN */

/****************
 * CANONICAL FORM
 ****************/

BitcoinExchange::BitcoinExchange(void)
{}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy) : _ref(copy._ref)
{}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
    if (this != &rhs)
        _ref = rhs._ref;

    return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{}

/******************************************************************************/

/****************
 * PUBLIC METHODS
 ****************/

void    BitcoinExchange::loadDataBase()
{
    std::ifstream ifs(DATABASE_PATH);
    std::string line;

    if (!ifs)
    {
        std::cerr << "Impossible to load database. Check DATABASE_PATH define "
                  << "in BitcoinExchange.hpp" << std::endl;
        throw std::exception();
    }

    // Skip first line
    std::getline(ifs, line);
    while (ifs.good())
    {
        std::getline(ifs, line);

        try {
            insertLineIntoMap(line);
        } catch (std::exception & e) {
            ifs.close();
            throw e;
        }
    }
    ifs.close();
}

void BitcoinExchange::print()
{
    for (std::map<std::string, double>::const_iterator it = _ref.begin(); it != _ref.end(); it++) {
        std::cout << it->first << "," << it->second << std::endl;
    }
}


void    BitcoinExchange::calculateRateExchange(char const filePath[]) const
{
    std::ifstream   ifs(filePath);
    std::string     line;
    std::string     date;
    double          value;
    size_t          sep;                

    if (!ifs)
    {
        std::cerr << "File doesn't exist" << std::endl;
        throw std::exception();
    }

    // Skip first line
    std::getline(ifs, line);
    while (ifs.good())
    {
        std::getline(ifs, line);
        if (ifs.eof())
            break ;

        if ((sep = line.find("|")) == std::string::npos)
        {
            std::cerr << "Error: Bad input => " << line << std::endl;
            continue;
        }

        date = line.substr(0, sep - 1);
        if (!isValidDate(date))
        {
            std::cerr << "Error: invalid date." << std::endl;
            continue ;
        }

        value = stringToFloat(line.substr(sep + 2));
        if (std::isnan(value))
            std::cerr << "Error: not a number." << std::endl;
        else if (value == HUGE_VAL || value > 1000.0)
            std::cerr << "Error: too large number." << std::endl;
        else if (value == -HUGE_VAL || value < 0.0)
            std::cerr << "Error: not a positive number." << std::endl;
        else
            calculate(date, value);
    }
    ifs.close();

}
/******************************************************************************/

/*****************
 * PRIVATE METHODS
 *****************/

void    BitcoinExchange::insertLineIntoMap(std::string const & line)
{
    size_t sep;

    if (line.empty())
        return;

    if ((sep = line.find(",")) == std::string::npos)
    {
        std::cerr << "Invalid line format. Valid format <YYYY-MM-DD,value>. "
                  << "(" + line + ")" << std::endl;
        throw std::exception();
    }

    std::string date = line.substr(0, sep);
    if (!isValidDate(date))
    {
        std::cerr << "Invalid date or format or date non-exist. "
                  << "(" + line + ")"
                  << std::endl;
         throw std::exception();
    }

    double value = stringToFloat(line.substr(sep + 1));
    if (value == NAN || value == HUGE_VAL || value == -HUGE_VAL)
    {
        std::cerr << "Value is not a number or is out of range. " 
                  << "(" + line + ")" << std::endl;
        throw std::exception();
    }
    _ref[date] = value;
}

bool BitcoinExchange::isValidDate(std::string const &date) const
{
    size_t firstSep = date.find("-");
    size_t secondSep = date.rfind("-");
    if (firstSep == secondSep)
        return false;

    std::string y = date.substr(0, firstSep);
    std::string m = date.substr(firstSep + 1, secondSep - firstSep - 1);
    std::string d = date.substr(secondSep + 1);

    if ((y.length() == 4 && isAllDigit(y)) && (m.length() == 2 && isAllDigit(m))
         && (d.length() == 2 && isAllDigit(d)))
    {
        int month = atoi(m.c_str());
        if (!(month >= JAN && month <= DEC))
            return false;

        int year = atoi(y.c_str());
        int day = atoi(d.c_str());
        if (month == FEB)
        {
            if ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)))
                return (day >= 1 && day <= 29);
            else
                return (day >= 1 && day <= 28);
        }
        else if (month == APR || month == JUN || month == SEP || month == NOV)
            return (day >= 1 && day <= 30);
        else
            return (day >= 1 && day <= 31);
    }
    return false;
}

double BitcoinExchange::stringToFloat(std::string const &value) const
{
    size_t posPoint = value.find(".");
    std::string wholeNumber;
    std::string fractionalPart;
    size_t sign = (value[0] == '+' || value[0] == '-') ? 1 : 0;

    if (posPoint != std::string::npos)
    {
        wholeNumber = value.substr(sign, posPoint - sign);
        fractionalPart = value.substr(posPoint + 1);
    }
    else
        wholeNumber = value.substr(sign);

    if (!isAllDigit(wholeNumber) || !isAllDigit(fractionalPart))
        return NAN;
    
    return strtod(value.c_str(), NULL);
}

bool BitcoinExchange::isAllDigit(std::string const &str) const
{
    for (std::string::const_iterator it = str.begin(); it != str.end(); it++)
    {
        if (!isdigit(*it))
            return (false);
    }
    return (true);
}

void    BitcoinExchange::calculate(std::string date, double value) const
{
    std::map<std::string, double>::const_iterator it = _ref.begin();
    int cmp; 
    
    std::cout << date << " => " << value << " = "; 

    for (; it != _ref.end(); it++) {
        if ((cmp = std::strcmp(date.c_str(), it->first.c_str())) <= 0)
        {
            if (cmp == 0 || it == _ref.begin())
                std::cout << it->second * value << std::endl;
            else
            {
                it--;
                std::cout << it->second * value << std::endl;
                it++;
            }
            break ;
        }
    }
    if (it == _ref.end())
        std::cout << (--it)->second * value << std::endl;
}
