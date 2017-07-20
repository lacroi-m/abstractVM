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
}
