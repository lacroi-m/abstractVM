/*
** Loris
*/

#ifndef PARSING_HPP_
# define PARSING_HPP_

#include <iostream>
#include <exception>
#include <sstream>
#include <fstream>

class Parsing : std::exception
{
public:
  Parsing(const char *);
  ~Parsing(){};
private:
  std::string	_content;
};

#endif /* !PARSING */
