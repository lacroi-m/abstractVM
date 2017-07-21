/*
** Loris
*/

#ifndef PARSE_READ_HPP_
# define PARSE_READ_HPP_

#include <iostream>
#include <exception>
#include <sstream>
#include <cstring>
#include <map>

class ParseRead : std::exception {
public:
  ParseRead(std::istream &);
  ~ParseRead(){};
  void		checkContent();
private:
  std::string				_content;
  std::map<std::string, std::string>	_clean_map;
};

#endif /* ! PARSE_READ_HPP_ */
