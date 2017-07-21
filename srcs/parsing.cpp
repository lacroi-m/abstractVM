/*
** Loris
*/

#include "parsing.hpp"

Parsing::Parsing(const char *path)
{
  std::string		tmp;
  std::stringstream	content;
  std::ifstream		file(path, std::ifstream::in);

  if (file.is_open())
    while (getline(file, tmp))
      content << tmp << std::endl;
  else {
    std::cerr << "Exception while opening/reading the file : " << path << std::endl;
    exit(84);
  }
  _content = content.str();
  checkContent();
}

void		Parsing::checkContent() {
  std::istringstream			toParse(_content);
  std::string				tmp;
  int					i = 1;

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
