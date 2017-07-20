/*
** Loris
*/

#include "parsing.hpp"

Parsing::Parsing(const char *path)
{
  std::string		tmp;
  std::stringstream	content;
  std::ifstream		file(path, std::ifstream::in);

  file.exceptions (std::ifstream::failbit | std::ifstream::badbit);
  try {
    while (getline(file, tmp))
      content << tmp << std::endl;
  }
  catch (const std::ifstream::failure &err) {
    std::cerr << "Exception while opening/reading the file : " << path << std::endl;
  }
  _content = content.str();
}
