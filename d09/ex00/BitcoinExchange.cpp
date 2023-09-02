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

#include <iostream>
#include <fstream>  /* ifstream */
#include <cctype>   /* isdigit */
#include <cstdlib>  /* atoi */
#include <stdlib.h> /* strtod */
#include <cmath>    /* NAN */

/****************
 * CANONICAL FORM
 ****************/

BitcoinExchange::BitcoinExchange(void)
{
    std::ifstream ifs(DATABASE_PATH);
    std::string buffer;

    if (!ifs.good())
        throw BitcoinExchange::DataBaseFileException();

    // Skip first line
    std::getline(ifs, buffer);
    while (ifs.good())
    {
        std::getline(ifs, buffer);
        checkLineDb(buffer);
    }
    ifs.close();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy)
    : _ref(copy._ref)
{
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
    if (this != &rhs)
    {
        _ref = rhs._ref;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
}

/******************************************************************************/

/*************
 * EXCEPTIONS
 *************/

const char *BitcoinExchange::DataBaseFileException::what() const throw()
{
    return "Database path is not valid. Check the path";
}
/******************************************************************************/

/****************
 * PUBLIC METHODS
 ****************/

void    BitcoinExchange::calculateRateExchange(char const filePath[]) const
{
    std::ifstream ifs(filePath);
    std::string buffer;
    std::string date;
    double      value;
    size_t  sep;                

    if (!ifs.good())
    {
        std::cerr << "File doesn't exist" << std::endl;
        return ;
    }

    // Skip first line
    std::getline(ifs, buffer);
    while (ifs.good())
    {
        std::getline(ifs, buffer);
        if (ifs.eof())
            break ;
        if (!isValidInputLine(buffer))
        {
            std::cerr << "Error: Bad input => " << buffer << std::endl;
            continue;
        }
        sep = buffer.find("|");
        date = buffer.substr(0, sep - 1);

        if (!isValidDate(date))
        {
            std::cerr << "Error: invalid date." << std::endl;
            continue ;
        }
        value = stringToFloat(buffer.substr(sep + 2));
        if (value == NAN)
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

void BitcoinExchange::checkLineDb(std::string line)
{
    size_t sep;

    if (line.empty())
        return;
    if ((sep = line.find(",")) == std::string::npos)
    {
        std::cerr << "Invalid line format. Valid format <YYYY-MM-DD,value>. "
                  << "(" + line + ")" << std::endl;
        return;
    }

    std::string date = line.substr(0, sep);
    if (!isValidDate(date))
    {
        std::cerr << "Invalid date, format or date non-exist. "
                  << "(" + line + ")"
                  << std::endl;
        return;
    }

    double value = stringToFloat(line.substr(sep + 1));
    if (value == NAN)
        std::cerr << "Value is not a number. " << "(" + line + ")" << std::endl;
    else if (value == HUGE_VAL || value == -HUGE_VAL)
        std::cerr << "Value is out of range. " << "(" + line + ")" << std::endl;
    else
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
    std::string wholeNumber = "";
    std::string fractionalPart = "";
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

bool    BitcoinExchange::isValidInputLine(std::string const & line) const
{
    size_t sep = line.find("|");

    if (sep == std::string::npos)
        return false;
    return (true);
}