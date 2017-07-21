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
  checkContent();
}


void            ParseRead::checkContent() {
  std::istringstream                    toParse(_content);
  std::string                           tmp;
  int                                   i = 1;

  while (getline(toParse, tmp)) {
    if (tmp.length() > 1 && tmp.c_str()[0] != ';') {
      if (i < 10)
        _clean_map.insert(std::pair<std::string, std::string>("line0" + std::to_string(i), tmp));
      else
        _clean_map.insert(std::pair<std::string, std::string>("line" + std::to_string(i), tmp));
    }
    i++;
  }
  for (std::map<std::string, std::string>::iterator it = _clean_map.begin(); it != _clean_map.end(); ++it)
    std::cout << it->first << " --> " << it->second << std::endl;
}
