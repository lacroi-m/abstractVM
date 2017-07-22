/*
** Loris
*/

#ifndef PARSE_READ_HPP_
# define PARSE_READ_HPP_

#include <iostream>
#include <exception>
#include <sstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

class ParseRead : std::exception {
public:
  ParseRead(std::istream &);
  ~ParseRead(){};
  void		checkContent();
  void		print_me_the_map();
  void		suppress_errors();
  std::map<std::string,std::vector<std::string>, std::less<std::string>> get_map();
  std::vector<std::string>		split_line(std::string&);
private:
  std::string				_content;
  std::map<std::string,
	   std::vector<std::string>,
	   std::less<std::string>>	 _clean_map;
};

#endif /* ! PARSE_READ_HPP_ */
