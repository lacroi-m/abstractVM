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

void				Parsing::show_me_the_map() {
  for (std::map<std::string, std::vector<std::string>>::iterator it = _clean_map.begin(); it != _clean_map.end(); ++it) {
    std::cout << "--[" << it->first << "]--" << std::endl;
    for (std::vector<std::string>::iterator ite = it->second.begin(); ite != it->second.end(); ++ite)
      std::cout << "this vector's element --> " << *ite << std::endl;
  }
}

std::vector<std::string>	Parsing::split_line(std::string &line)
{
  std::vector<std::string>	splited;
  std::string			buf;

  std::replace(line.begin(), line.end(), '(', ' ');
  std::replace(line.begin(), line.end(), ')', ' ');
  std::istringstream	       	tmp(line);
  while (getline(tmp, buf, ' '))
    splited.push_back(buf);
  return (splited);
}

void		Parsing::checkContent() {
  std::istringstream			toParse(_content);
  std::string				tmp;
  int					i = 1;

  while (getline(toParse, tmp)) {
    if (tmp.length() > 1 && tmp.c_str()[0] != ';') {
      if (i < 10)
	_clean_map.insert(std::pair<std::string, std::vector<std::string>>("line0" + std::to_string(i), split_line(tmp)));
      else	
	_clean_map.insert(std::pair<std::string, std::vector<std::string>>("line" + std::to_string(i), split_line(tmp)));
    }
    i++;
  }
  show_me_the_map();
}
