/*
** Loris
*/

#ifndef PARSING_HPP_
# define PARSING_HPP_

#include <iostream>
#include <exception>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <map>

class Parsing : std::exception
{
public:
  Parsing(const char *);
  ~Parsing(){};
  void		checkContent();
  void		show_me_the_map();
  std::vector<std::string>		split_line(std::string&);
private:
  std::string				_content;
  std::map<std::string,
	   std::vector<std::string>,
	   std::less<std::string>>	_clean_map;
};

#endif /* !PARSING */
