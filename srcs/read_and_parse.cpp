/*
** Loris
*/

#include "parse_read.hpp"

ParseRead::ParseRead(std::istream &cin) {
  std::string		tmp;
  std::stringstream	content;
  
  while (getline(cin, tmp)
	 && std::strncmp(tmp.c_str(), ";;", 2) != 0)
    content << tmp << std::endl;
  _content = content.str();   
}
