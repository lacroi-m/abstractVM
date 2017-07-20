/*
** Loris
*/

#ifndef PARSE_READ_HPP_
# define PARSE_READ_HPP_

#include <iostream>
#include <exception>
#include <sstream>
#include <cstring>

class ParseRead : std::exception {
public:
  ParseRead(std::istream &);
  ~ParseRead(){};
private:
  std::string	_content;
};

#endif /* ! PARSE_READ_HPP_ */
