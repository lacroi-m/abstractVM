/*
** Loris
*/

#ifndef PARSING_HPP_
# define PARSING_HPP_

#include <iostream>
#include <exception>
#include <sstream>
#include <fstream>
#include <map>

class Parsing : std::exception
{
public:
  Parsing(const char *);
  ~Parsing(){};
  void		checkContent();
private:
  std::string				_content;
  std::map<std::string, std::string>	_clean_map;
};

#endif /* !PARSING */
